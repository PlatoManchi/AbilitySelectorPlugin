#include "AbilityFilters/AF_ActorsInRadius.h"
#include "GameFramework/Character.h"

#if UE_BUILD_DEVELOPMENT
#include "DrawDebugHelpers.h"
#endif

bool UAF_ActorsInRadius::CanPassFilter_Implementation(UAbilityFilterData* data) const
{
	check(data);

#if UE_BUILD_DEVELOPMENT
	if (m_draw_debug_sphere && data->GetCharacter() && data->GetCharacter()->GetWorld())
	{
		DrawDebugSphere(data->GetCharacter()->GetWorld(), data->GetCharacter()->GetActorLocation(), m_radius, FMath::Min(FMath::Max(m_radius / 4.f, 2.f), 25.0f), m_debug_sphere_color, false, m_debug_sphere_duration, 0, 0);
	}
#endif
	return true;
}
