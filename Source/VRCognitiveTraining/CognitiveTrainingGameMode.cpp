// Copyright Epic Games, Inc. All Rights Reserved.


#include "CognitiveTrainingGameMode.h"

ACognitiveTrainingGameMode::ACognitiveTrainingGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PrimaryActorTick.bStartWithTickEnabled = true;
	PrimaryActorTick.bCanEverTick = true;
}

void ACognitiveTrainingGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	PassedTime += DeltaTime;
	if (PassedTime >= TimeLimitInSec)
	{
		ChangeTaskStatus(FAILED);
	}
}

void ACognitiveTrainingGameMode::ChangeTaskStatus(TaskStatus status)
{
	switch (status)
	{
	case IN_PROCESS: {PassedTime = 0.0f; } break;
	case FAILED: {OnTaskFailed(); } break;
	case COMPLETED: {OnTaskCompleted(); } break;
	default: UE_LOG(LogGameMode, Warning, TEXT("Incorrect task state")); break;
	}
}

void ACognitiveTrainingGameMode::OnTaskCompleted_Implementation()
{
}

void ACognitiveTrainingGameMode::OnTaskFailed_Implementation()
{
}
