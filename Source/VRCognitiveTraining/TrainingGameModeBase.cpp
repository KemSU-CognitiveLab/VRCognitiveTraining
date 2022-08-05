// Fill out your copyright notice in the Description page of Project Settings.


#include "TrainingGameModeBase.h"


DEFINE_LOG_CATEGORY(LogTraining);

void ATrainingGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bTaskStarted && bUseTimer)
	{
		RestOfTime -= DeltaTime;
		if (RestOfTime <= 0.0f)
			FinishTask(false, TEXT("Time is out"));
	}
	if (bExecutionStarted)
		GameplayTime += DeltaTime;
}

void ATrainingGameModeBase::StartTask(float timer)
{
	if (!bTaskStarted) 
	{
		bTaskStarted = true;
		if (timer > 0.0f)
		{
			bUseTimer = true;
			RestOfTime = timer;
		}
		UE_LOG(LogTraining, Display, TEXT("Task started with timer %f"), timer);
		OnTaskStarted();
	}
	else UE_LOG(LogTraining, Error, TEXT("Try to start not finished task"));
	if (!bExecutionStarted)
	{
		GameplayTime = 0.0f;
	}
}

void ATrainingGameModeBase::FinishTask(int fail_code, const FString& reason)
{
	if (bTaskStarted)
	{
		bTaskStarted = false;
		if (fail_code == 0)
		{
			UE_LOG(LogTraining, Display, TEXT("Task successfully completed"), fail_code, *reason);
			bExecutionStarted = false;
			OnTaskSucceed();
		}
		else
		{
			UE_LOG(LogTraining, Display, TEXT("Task failed (%i) with reason - %s"), fail_code, *reason);
			OnTaskFailed(fail_code, reason);
		}
	}
	else UE_LOG(LogTraining, Error, TEXT("Try to finish not started task"));
}
