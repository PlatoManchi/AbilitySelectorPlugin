#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "AbilitySelectorTypes.h"

#include "AbilitySelector.generated.h"



UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABILITYSELECTOR_API UAbilitySelector : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintNativeEvent)
	TArray<FAbilitySelectData> TryGetAbilities(UAbilityFilterData* ability_filter_data, const TArray<FAbilitySelectData>& abilities_list);

protected:
	virtual TArray<FAbilitySelectData> TryGetAbilities_Implementation(UAbilityFilterData* ability_filter_data, const TArray<FAbilitySelectData>& abilities_list) 
	{
		return TArray<FAbilitySelectData>();
	}
};

