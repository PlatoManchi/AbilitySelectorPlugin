#include "AbilityFilters/AF_IsCharacterFalling.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "AbilityFilterData.h"

bool UAF_IsCharacterFalling::CanPassFilter_Implementation(UAbilityFilterData* data) const
{
	return data->GetCharacter()->GetCharacterMovement()->IsFalling();
}

