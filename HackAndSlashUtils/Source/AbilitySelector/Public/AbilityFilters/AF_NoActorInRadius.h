#pragma once

#include "CoreMinimal.h"
#include "AF_ActorsInRadius.h"
#include "AF_NoActorInRadius.generated.h"

/** Passes filter if there are no actors of type in radius
*/
UCLASS(NotBlueprintable, EditInlineNew, CollapseCategories, defaultconfig, configdonotcheckdefaults, meta = (DisplayName = "No Actors In Radius"))
class ABILITYSELECTOR_API UAF_NoActorInRadius : public UAF_ActorsInRadius
{
	GENERATED_BODY()
protected:
	
public:
	virtual bool CanPassFilter_Implementation(UAbilityFilterData* data) const override;
};

