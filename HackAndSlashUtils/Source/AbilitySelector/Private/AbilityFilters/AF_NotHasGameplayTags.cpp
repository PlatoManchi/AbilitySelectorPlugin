#include "AbilityFilters/AF_NotHasGameplayTags.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"

#include "AbilityFilterData.h"

bool UAF_NotHasGameplayTags::CanPassFilter_Implementation(UAbilityFilterData* data) const
{
	if (data->GetCharacter())
	{
		TObjectPtr<UAbilitySystemComponent> ability_comp = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent((AActor*)data->GetCharacter());
		if (ability_comp)
		{
			return !ability_comp->HasAllMatchingGameplayTags(m_tags);
		}
	}
	

	return false;
}

/*FString UAF_NotHasGameplayTags::GetDesc()
{
	TArray< FStringFormatArg > args;
	args.Add(FStringFormatArg(m_tags.ToString()));

	return FString::Format(TEXT("Doesn't Has Tags [{0}]"), args);
}*/