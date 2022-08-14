#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "GameplayAbilitySpec.h"

#include "AbilitySelectorTypes.h"
#include "AbilitySelector.h"

#include "DA_AbilityData.generated.h"

class UGameplayAbility;

class UAbilityFilter;
class UAbilityFilterData;


UCLASS(BlueprintType)
class ABILITYSELECTOR_API UDA_AbilityData : public UDataAsset
{
	GENERATED_BODY()

public:
	// Give all abilities to character that are in the ability list
	UFUNCTION(BlueprintCallable)
	void GiveAllAbilitiesToCharacter(ACharacter* character);

	// Clears all the abilities that are present in the ability list
	UFUNCTION(BlueprintCallable)
	void ClearAllAbilitiesFromCharacter(ACharacter* character);

	// Will try to get abilities based on the selector algorithm.
	UFUNCTION(BlueprintCallable)
	TArray<FAbilitySelectData> TryGetAbilities(ACharacter* character);

	FORCEINLINE TArray<FAbilitySelectData>& GetAbilitiesList() { return m_abilities_list; }
	FORCEINLINE TObjectPtr<UAbilityFilterData> GetAbilityFilterData() { return m_ability_filter_data; }

protected:
	UPROPERTY(EditDefaultsOnly, Instanced, BlueprintReadOnly, meta = (DisplayName = "Ability Filter Data"))
	TObjectPtr<UAbilityFilterData> m_ability_filter_data;
	
	UPROPERTY(EditDefaultsOnly, Instanced, BlueprintReadOnly, meta = (DisplayName = "Ability Selector"))
	TObjectPtr<UAbilitySelector> m_ability_selector;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (DisplayName = "Abillities List"))
	TArray<FAbilitySelectData> m_abilities_list;
};


