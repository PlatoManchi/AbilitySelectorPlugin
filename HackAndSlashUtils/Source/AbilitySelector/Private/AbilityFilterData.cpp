#include "AbilityFilterData.h"

#include "GameFramework/Character.h"
#include "Kismet/KismetSystemLibrary.h"

#include "DA_AbilityData.h"
#include "AbilityFilter.h"
#include "AbilityFilters/AF_ActorsInRadius.h"

void UAbilityFilterData::CollectData_Implementation(ACharacter* character, const TArray<FAbilitySelectData>& abilities_select_list)
{
	// Gather data needed for all filters
	m_character = character;

#pragma region actors_in_radius
	// Get max radius to find actors in
	bool is_actors_in_radius_filter_present = false;
	float max_radius = -1.0f;
	for (const FAbilitySelectData& ability : abilities_select_list)
	{
		for (const TObjectPtr<const UAbilityFilter> filter : ability.m_ability_filters)
		{
			TObjectPtr<UAF_ActorsInRadius> actors_in_radius_filter = Cast<UAF_ActorsInRadius>(filter);
			if (actors_in_radius_filter)
			{
				is_actors_in_radius_filter_present = true;
				if (max_radius < actors_in_radius_filter->GetRadius())
				{
					max_radius = actors_in_radius_filter->GetRadius();
				}

				// Resetting data from previous data collection run. Also helps with initializing the struct on first run
				FActorsInRadiiArray* actors_in_radius_array = m_actors_in_radius_map.Find(actors_in_radius_filter->GetActorClass());
				if (!actors_in_radius_array)
				{
					actors_in_radius_array = &m_actors_in_radius_map.Add(actors_in_radius_filter->GetActorClass());
				}

				check(actors_in_radius_array); // actors_in_radius_array shouldn't be null anymore

				FActorsInRadius* actors_in_radius = actors_in_radius_array->m_actors_in_radii.FindByPredicate(
					[actors_in_radius_filter](const FActorsInRadius& other) {
						return other.m_radius == actors_in_radius_filter->GetRadius();
					});
				if (!actors_in_radius)
				{
					int index = actors_in_radius_array->m_actors_in_radii.Add({ actors_in_radius_filter->GetRadius(), {} });
					actors_in_radius = &actors_in_radius_array->m_actors_in_radii[index];
				}

				check(actors_in_radius); // actors_in_radius shouldn't be null anymore

				actors_in_radius->m_actors.Empty();
			}
		}
	}

	if (is_actors_in_radius_filter_present && max_radius >= 0.0f)
	{
		// Get all actors in max radius
		TArray<FHitResult> out_results;
		bool is_overlap_test_success = false;
		if (character->GetWorld() != nullptr)
		{
			FCollisionQueryParams params;
			params.AddIgnoredActor(m_character);

			character->GetWorld()->SweepMultiByObjectType(
				out_results, 
				character->GetActorLocation(), 
				character->GetActorLocation() + FVector(0.01f, 0.01f, 0.01f),
				FQuat::Identity, 
				FCollisionObjectQueryParams::AllObjects, 
				FCollisionShape::MakeSphere(max_radius), 
				params);
		}

		// filtering actors that passed overlap test based on class
		for (FHitResult const& result : out_results)
		{
			if (result.bBlockingHit && result.GetActor()->IsValidLowLevelFast())
			{
				AActor* actor = result.GetActor();
				
				for (TPair<TSubclassOf<AActor>, FActorsInRadiiArray>& pair : m_actors_in_radius_map)
				{
					// If we are interested in this actor of class
					if (actor->IsA(pair.Key))
					{
						// Checking for distance using impact point instead of actor location, because some actors might be
						// very large and sweep might hit them, but their pivot point would be out of radius and I want to consider
						// those actors as inside radius.
						float distance = FVector::Dist(m_character->GetActorLocation(), result.ImpactPoint);

						// Loop through all radii and add actor into the array if radius is less than distance
						for (FActorsInRadius& actors_in_radius : pair.Value.m_actors_in_radii)
						{
							if (actors_in_radius.m_radius > distance)
							{
								actors_in_radius.m_actors.AddUnique(actor);
							}
						}
					}
				}
			}
		}
	}
#pragma endregion
}