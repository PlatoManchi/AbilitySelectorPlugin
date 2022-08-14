#pragma once

#include "CoreMinimal.h"
#include "AbilityFilter.h"
#include "GameplayTagContainer.h"
#include "AF_HasGameplayTag.generated.h"

/** Passes filter if character has all of tags specified
*/
UCLASS(NotBlueprintable, EditInlineNew, CollapseCategories, defaultconfig, configdonotcheckdefaults, meta = (DisplayName = "Has Gameplay Tags"))
class ABILITYSELECTOR_API UAF_HasGameplayTag : public UAbilityFilter
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Tags", DisplayPriority = "2"))
	FGameplayTagContainer m_tags;

public:
	virtual bool CanPassFilter_Implementation(UAbilityFilterData* data) const override;
};


