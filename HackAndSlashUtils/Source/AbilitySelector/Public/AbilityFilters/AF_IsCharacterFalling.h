#pragma once

#include "CoreMinimal.h"
#include "AbilityFilter.h"
#include "AF_IsCharacterFalling.generated.h"

UCLASS(NotBlueprintable, EditInlineNew, CollapseCategories, defaultconfig, configdonotcheckdefaults, meta = (DisplayName = "Is Character Falling"))
class ABILITYSELECTOR_API UAF_IsCharacterFalling : public UAbilityFilter
{
	GENERATED_BODY()
	
protected:
	virtual bool CanPassFilter_Implementation(UAbilityFilterData* data) const;
};
