// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VRGameModeBase.h"
#include "CognitiveTrainingGameMode.generated.h"


UENUM()
enum TaskStatus
{
	PREPARATION		UMETA(DisplayName = "Preparation"),
	IN_PROCESS		UMETA(DisplayName = "In process"),
	FAILED			UMETA(DisplayName = "Failed"),
	COMPLETED		UMETA(DisplayName = "Completed"),
};

UCLASS()
class VRCOGNITIVETRAINING_API ACognitiveTrainingGameMode : public AVRGameModeBase
{
	GENERATED_BODY()
public:
	ACognitiveTrainingGameMode(const FObjectInitializer& ObjectInitializer);
	virtual void Tick(float DeltaTime) override;

	//---------------- API -------------------
	UFUNCTION(BlueprintCallable)
	void ChangeTaskStatus(TaskStatus status);//called from scene objects to notify that task is completed

	UFUNCTION(BlueprintNativeEvent)
	void OnTaskCompleted();
	virtual void OnTaskCompleted_Implementation();
	UFUNCTION(BlueprintNativeEvent)
	void OnTaskFailed();
	virtual void OnTaskFailed_Implementation();

	UPROPERTY(EditAnywhere, BlueprintReadonly)
	float TimeLimitInSec = 0.0f;//if it's zero then no time limit
	


protected:
	float PassedTime = 0.0f;

};
