#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AbilityFilter.generated.h"

class UAbilityFilterData;

UCLASS(Abstract, Blueprintable, EditInlineNew, CollapseCategories, defaultconfig, configdonotcheckdefaults)
class ABILITYSELECTOR_API UAbilityFilter : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	bool CanPassFilter(UAbilityFilterData* data) const;
	
	
	FORCEINLINE int8 GetPassingScore() const { return m_passing_score; }

protected:
	virtual bool CanPassFilter_Implementation(UAbilityFilterData* data) const { return true; };


	// Score used while calculating which ability to be choosen. Score will be added to ability for every filter passes.
	// And ability with highest score will be selected. 
	// Can give different scores for same filter on different ability.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (DisplayName = "Passing Score", DisplayPriority = "1", SimpleDisplay))
	int m_passing_score = 1;
};

