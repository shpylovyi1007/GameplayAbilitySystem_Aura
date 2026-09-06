
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AuraAbilitySystemLibrary.generated.h"

class UAttributeMenuWidgetController;
class UOverlayWidgetController;

UCLASS()
class AURA_API UAuraAbilitySystemLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintPure, Category = "AuraAbilitySystemLibrary")
	static UOverlayWidgetController* GetOverlayWidgetController(UObject* WorldContextObject);
	
	UFUNCTION(BlueprintPure, Category = "AuraAbilitySystemLibrary")
	static UAttributeMenuWidgetController* GetAttributeMenuWidgetController(UObject* WorldContextObject);
};
