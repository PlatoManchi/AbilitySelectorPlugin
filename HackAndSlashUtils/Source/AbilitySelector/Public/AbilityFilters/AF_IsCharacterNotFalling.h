#pragma once

#include "CoreMinimal.h"
#include "AbilityFilter.h"
#include "AF_IsCharacterNotFalling.generated.h"

UCLASS(NotBlueprintable, EditInlineNew, CollapseCategories, defaultconfig, configdonotcheckdefaults, meta = (DisplayName = "Is Character Not Falling"))
class ABILITYSELECTOR_API UAF_IsCharacterNotFalling : public UAbilityFilter
{
	GENERATED_BODY()
	
protected:
	virtual bool CanPassFilter_Implementation(UAbilityFilterData* data) const;
};
