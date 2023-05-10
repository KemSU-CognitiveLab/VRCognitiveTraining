// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VRGameModeBase.h"
#include "TrainingGameModeBase.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTraining, Log, All);

UCLASS(BlueprintType)
class UTaskStatistic : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadonly)
	float FullGameplayTime = 0.0f; // Time to solve room
	UPROPERTY(VisibleAnywhere, BlueprintReadonly)
	int AttemptsCount = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadonly)
	float RestOfTime = 0.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadonly)
	FString Name;
};

/**
 * 
 */
UCLASS()
class VRCOGNITIVETRAINING_API ATrainingGameModeBase : public AVRGameModeBase
{
	GENERATED_BODY()
	virtual void Tick(float DeltaTime) override;
public:
	UFUNCTION(BlueprintCallable, Category="Training")
	virtual void StartTask(float timer);
	UFUNCTION(BLueprintCallable, Category = "Training")
	void FailAttempt();
	UFUNCTION(BlueprintImplementableEvent)
	void OnFailAttempt_BP();
	UFUNCTION(BlueprintCallable, Category = "Training")
	virtual void FinishTask(int fail_code = 0, const FString& reason = TEXT(""));

	UFUNCTION(BlueprintImplementableEvent)
	void OnTaskStarted();
	UFUNCTION(BlueprintImplementableEvent)
	void OnTaskFailed(int fail_code, const FString& reason);
	UFUNCTION(BlueprintImplementableEvent)
	void OnTaskSucceed();
	UPROPERTY(VisibleAnywhere, BlueprintReadonly)
	bool bExecutionStarted = false;
	UPROPERTY(EditAnywhere, BlueprintReadonly)
	UTaskStatistic* Statistic;
protected:
	bool bTaskStarted = false;
	bool bUseTimer = false;
	
	
};
