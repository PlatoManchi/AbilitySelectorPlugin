#pragma once

#include "CoreMinimal.h"
#include "AbilitySelector.h"
#include "AS_AbilityWithHighestScore.generated.h"

UCLASS(NotBlueprintable, EditInlineNew, CollapseCategories, defaultconfig, configdonotcheckdefaults, meta = (DisplayName = "Ability With highest Score"))
class ABILITYSELECTOR_API UAS_AbilityWithHighestScore : public UAbilitySelector
{
	GENERATED_BODY()
	
protected:
	virtual TArray<FAbilitySelectData> TryGetAbilities_Implementation(UAbilityFilterData* ability_filter_data, const TArray<FAbilitySelectData>& abilities_list) override;

	// temporary struct to store filter score for abilities
	struct AbilityToScore
	{
		const FAbilitySelectData& m_ability_select_data;
		int m_score;
	};
};

