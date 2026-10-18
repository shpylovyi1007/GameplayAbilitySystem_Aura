
#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "MVVM_LoadSlot.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSetWidgetSwitcherIndex, int32, WidgetSwitcherIndex);

/**
 * 
 */
UCLASS()
class AURA_API UMVVM_LoadSlot : public UMVVMViewModelBase
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(BlueprintAssignable)
	FSetWidgetSwitcherIndex SetWidgetSwitcherIndex;
	
	void InitializeSlot();
	
	UPROPERTY()
	FString PlayerName;
	
	UPROPERTY()
	int32 SlotIndex;
	
	// UPROPERTY()
	// FString LoadSlotName2;
	
	
	
	
	/* Field Notifies */
	
	FString GetLoadSlotName() const { return LoadSlotName; }
	
	void SetLoadSlotName(FString InLoadSlotName);
	
private:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, FieldNotify, Setter, Getter, meta = (AllowPrivateAccess = "true"));
	FString LoadSlotName;
};
