#include "AbilityFilters/AF_IsCharacterNotFalling.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "AbilityFilterData.h"

bool UAF_IsCharacterNotFalling::CanPassFilter_Implementation(UAbilityFilterData* data) const
{
	return !data->GetCharacter()->GetCharacterMovement()->IsFalling();
}

