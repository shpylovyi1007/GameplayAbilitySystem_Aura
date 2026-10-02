
#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/AuraDamageGameplayAbility.h"
#include "AuraBeamSpell.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAuraBeamSpell : public UAuraDamageGameplayAbility
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION(BLueprintCallable)
	void StoreMouseDataInfo(const FHitResult& HitResult);
	
	UFUNCTION(BLueprintCallable)
	void StoreOwnerVariables();
protected:
	
	UPROPERTY(BlueprintReadWrite, Category="Beam")
	FVector MouseHitLocation;
	
	UPROPERTY(BlueprintReadWrite, Category="Beam")
	TObjectPtr<AActor> MouseHitActor;
	
	UPROPERTY(BlueprintReadWrite, Category="Beam")
	TObjectPtr<APlayerController> OwnerPlayerController;
	
	UPROPERTY(BlueprintReadWrite, Category="Beam")
	TObjectPtr<ACharacter> OwnerCharacter;
};
