#pragma once

#include "CoreMinimal.h"
#include "AbilityFilter.h"
#include "AF_ActorsInRadius.generated.h"

/** Base class for any fillter that needs actors in radius 
*/
UCLASS(Abstract, NotBlueprintable, EditInlineNew, CollapseCategories, defaultconfig, configdonotcheckdefaults)
class ABILITYSELECTOR_API UAF_ActorsInRadius : public UAbilityFilter
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (DisplayName = "Actor Class", DisplayPriority = "2"))
	TSubclassOf<AActor> m_actor_class;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (DisplayName = "Radius", ClampMin = "0.0", DisplayPriority = "4"))
	float m_radius;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, meta = (DisplayName = "Draw Debug Sphere", DevelopmentOnly))
	bool m_draw_debug_sphere = false;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, meta = (DisplayName = "Debug Sphere Duration", EditCondition = "m_draw_debug_hit_point", EditConditionHides, DevelopmentOnly))
	float m_debug_sphere_duration = 5.0f;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, meta = (DisplayName = "Debug Sphere Color", EditCondition = "m_draw_debug_hit_point", EditConditionHides, DevelopmentOnly))
	FColor m_debug_sphere_color = FColor(255, 64, 64);

public:
	virtual bool CanPassFilter_Implementation(UAbilityFilterData* data) const override;

	FORCEINLINE TSubclassOf<AActor> GetActorClass() const { return m_actor_class; }
	FORCEINLINE float GetRadius() const { return m_radius; }
};

