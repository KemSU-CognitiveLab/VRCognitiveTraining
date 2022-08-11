// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VRGameModeBase.h"
#include "TrainingGameModeBase.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTraining, Log, All);

USTRUCT(BlueprintType)
struct FTaskStatistic
{
	GENERATED_BODY()
	UPROPERTY()
	float FullGameplayTime = 0.0f;
	UPROPERTY()
	int AttemptsCount = 0;
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
	UFUNCTION(BlueprintCallable, Category = "Training")
	virtual void FinishTask(int fail_code = 0, const FString& reason = TEXT(""));
	UFUNCTION(BlueprintCallable, Category = "Training")
	FORCEINLINE FTaskStatistic GetStatistic() const { return statistic; }

	UFUNCTION(BlueprintImplementableEvent)
	void OnTaskStarted();
	UFUNCTION(BlueprintImplementableEvent)
	void OnTaskFailed(int fail_code, const FString& reason);
	UFUNCTION(BlueprintImplementableEvent)
	void OnTaskSucceed();
	UPROPERTY(VisibleAnywhere, BlueprintReadonly)
	bool bExecutionStarted = false;

protected:
	float RestOfTime = 0.0f;
	bool bTaskStarted = false;
	bool bUseTimer = false;
	FTaskStatistic statistic;
	
};
