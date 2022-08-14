#pragma once

#include "CoreMinimal.h"
#include "GameplayAbilitySpec.h"

#include "AbilitySelectorTypes.generated.h"


class UGameplayAbility;

class UAbilityFilter;


USTRUCT(BlueprintType)
struct ABILITYSELECTOR_API FAbilitySelectData
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = AbilityData, meta = (DisplayName = "Gameplay Ability"))
	TSubclassOf<UGameplayAbility> m_gameplay_ability;

	UPROPERTY(BlueprintReadOnly, Category = AbilityData, meta = (DisplayName = "Ability Spec Handle"))
	FGameplayAbilitySpecHandle m_ability_spec_handle;

	UPROPERTY(EditDefaultsOnly, Instanced, BlueprintReadOnly, Category = AbilityData, meta = (DisplayName = "Ability Filters"))
	TArray<TObjectPtr<UAbilityFilter>> m_ability_filters;
};

