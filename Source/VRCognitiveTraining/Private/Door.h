// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "Door.generated.h"

/**
 * 
 */
UCLASS()
class VRCOGNITIVETRAINING_API ADoor : public AInteractableActor
{
	GENERATED_BODY()

public:
	ADoor(const FObjectInitializer& ObjectInitializer);
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadonly)
	class UBoxComponent* BoxCollision;
	UPROPERTY(VisibleAnywhere, BlueprintReadonly)
	class UStaticMeshComponent* Mesh;
	UPROPERTY(EditAnywhere, BlueprintReadwrite)
	FName LevelToLoad;
	UPROPERTY(VisibleAnywhere, BlueprintReadonly)
	class UWidgetComponent* TextUI;

	UFUNCTION(BlueprintCallable)
	void Unlock();
	UFUNCTION(BlueprintCallable)
	void Lock();

	//------------ AInteractableActor interface ------------
	virtual void OnPressedByTrigger(const FHitResult& hitResult) override;
	virtual void BeginOverlapByController(const FHitResult& hitResult) override;
	virtual void EndOverlapByController() override;
	//------------ AInteractableActor interface ------------

protected:
	bool bIsLocked = false;
	UPROPERTY(EditAnywhere, BlueprintReadwrite)
	TSubclassOf<UUserWidget> DoorUIClass;
	
};
