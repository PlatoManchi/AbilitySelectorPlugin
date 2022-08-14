#include "AbilityFilters/AF_HasGameplayTag.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"

#include "AbilityFilterData.h"


bool UAF_HasGameplayTag::CanPassFilter_Implementation(UAbilityFilterData* data) const
{
	if (data->GetCharacter())
	{
		TObjectPtr<UAbilitySystemComponent> ability_comp = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent((AActor*)data->GetCharacter());
		if (ability_comp)
		{
			return ability_comp->HasAllMatchingGameplayTags(m_tags);
		}
	}

	return false;
}


/*FString UAF_HasGameplayTag::GetDesc() const
{
	TArray< FStringFormatArg > args;
	args.Add(FStringFormatArg(m_tags.ToString()));

	return FString::Format(TEXT("Has Tags [{0}]"), args);
}*/