#pragma once

#include "CoreMinimal.h"
#include "AF_ActorsInRadius.h"
#include "AF_NumActorsInRadius.generated.h"

/** Passes filter if there are exactly or more than particular number of actors in radius
*/
UCLASS(NotBlueprintable, EditInlineNew, CollapseCategories, defaultconfig, configdonotcheckdefaults, meta = (DisplayName = "Num of Actors In Radius"))
class ABILITYSELECTOR_API UAF_NumActorsInRadius : public UAF_ActorsInRadius
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Actors Count", ClampMin = "0", DisplayPriority = "3"))
	int m_actor_count;

public:
	virtual bool CanPassFilter_Implementation(UAbilityFilterData* data) const override;
};

