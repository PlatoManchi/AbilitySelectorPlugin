#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "DA_AbilityData.h"

#include "AbilityFilterData.generated.h"

class AActor;
class ACharacter;

USTRUCT(BlueprintType)
struct ABILITYSELECTOR_API FActorsInRadius
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(BlueprintReadOnly, meta = (DisplayName = "Radius"))
	float m_radius;

	UPROPERTY(BlueprintReadOnly, meta = (DisplayName = "Actors"))
	TArray<AActor*> m_actors;
};

USTRUCT(BlueprintType)
struct ABILITYSELECTOR_API FActorsInRadiiArray
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(BlueprintReadOnly, meta = (DisplayName = "Actors In Radii"))
	TArray<FActorsInRadius> m_actors_in_radii;
};

UCLASS(Blueprintable, EditInlineNew)
class ABILITYSELECTOR_API UAbilityFilterData : public UObject
{
	GENERATED_BODY()

public:
	// Dont forget to call super CollectData when overriding this in function blueprints.
	UFUNCTION(BlueprintNativeEvent)
	void CollectData(ACharacter* character, const TArray<FAbilitySelectData>& abilities_select_list);
	

	FORCEINLINE TObjectPtr<ACharacter> GetCharacter() const { return m_character; }
	FORCEINLINE const TMap<TSubclassOf<AActor>, FActorsInRadiiArray>& GetActorsInRadiusMap() const { return m_actors_in_radius_map; }

protected:
	virtual void CollectData_Implementation(ACharacter* character, const TArray<FAbilitySelectData>& abilities_select_list);


	UPROPERTY(BlueprintReadOnly, Category = "Ability Selection Filter Data", meta = (DisplayName = "Character"))
	TObjectPtr<ACharacter> m_character;

	UPROPERTY(BlueprintReadOnly, Category = "Ability Selection Filter Data", meta = (DisplayName = "Actors In Radius Map"))
	TMap<TSubclassOf<AActor>, FActorsInRadiiArray> m_actors_in_radius_map;
};


