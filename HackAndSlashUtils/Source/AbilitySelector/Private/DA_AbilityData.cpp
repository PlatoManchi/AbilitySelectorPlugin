#include "DA_AbilityData.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"

#include "AbilityFilter.h"
#include "AbilityFilterData.h"


void UDA_AbilityData::GiveAllAbilitiesToCharacter(ACharacter* character)
{
	check(character != nullptr);

	IAbilitySystemInterface* ability_interface = Cast<IAbilitySystemInterface>(character);
	check(ability_interface != nullptr);

	UAbilitySystemComponent* ability_comp = ability_interface->GetAbilitySystemComponent();
	check(ability_comp != nullptr);

	for (FAbilitySelectData& data : m_abilities_list)
	{
		data.m_ability_spec_handle = ability_comp->GiveAbility(data.m_gameplay_ability);
	}
}

void UDA_AbilityData::ClearAllAbilitiesFromCharacter(ACharacter* character)
{
	check(character != nullptr);

	IAbilitySystemInterface* ability_interface = Cast<IAbilitySystemInterface>(character);
	check(ability_interface != nullptr);

	UAbilitySystemComponent* ability_comp = ability_interface->GetAbilitySystemComponent();
	check(ability_comp != nullptr);

	for (FAbilitySelectData& data : m_abilities_list)
	{
		ability_comp->ClearAbility(data.m_ability_spec_handle);
	}
}

TArray<FAbilitySelectData> UDA_AbilityData::TryGetAbilities(ACharacter* character)
{
	check(m_ability_filter_data != nullptr);
	check(m_ability_selector != nullptr);

	// Collect the data that is needed to evulate filters.
	m_ability_filter_data->CollectData(character, m_abilities_list);

	// try to get abilities using the selector
	return m_ability_selector->TryGetAbilities(m_ability_filter_data, m_abilities_list);
}

