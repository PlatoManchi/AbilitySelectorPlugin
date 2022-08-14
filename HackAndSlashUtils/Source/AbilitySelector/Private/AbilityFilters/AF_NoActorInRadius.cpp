#include "AbilityFilters/AF_NoActorInRadius.h"
#include "AbilityFilterData.h"

bool UAF_NoActorInRadius::CanPassFilter_Implementation(UAbilityFilterData* data) const
{
	check(data);

	Super::CanPassFilter_Implementation(data);

	const FActorsInRadiiArray* actors_in_radius_array = data->GetActorsInRadiusMap().Find(m_actor_class);

	check(actors_in_radius_array); // actors_in_radius_array shouldn't be null anymore

	const FActorsInRadius* actors_in_radius = actors_in_radius_array->m_actors_in_radii.FindByPredicate(
		[&](const FActorsInRadius& other) {
			return other.m_radius == m_radius;
		});

	check(actors_in_radius); // actors_in_radius shouldn't be null anymore

	return actors_in_radius->m_actors.Num() == 0;
}

