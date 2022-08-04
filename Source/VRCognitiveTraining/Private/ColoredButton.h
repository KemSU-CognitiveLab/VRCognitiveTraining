// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RichButton.h"
#include "ColoredButton.generated.h"

/**
 * 
 */
UCLASS()
class UColoredButton : public URichButton
{
	GENERATED_BODY()
public:
	UColoredButton();

	UPROPERTY(EditAnywhere, BlueprintReadonly)
	UMaterialInterface* base_material;
protected:
	
	UPROPERTY()
	UMaterialInstanceDynamic* normal_material;
	UPROPERTY()
	UMaterialInstanceDynamic* hovered_material;
	UPROPERTY()
	UMaterialInstanceDynamic* pressed_material;
	UPROPERTY()
	UMaterialInstanceDynamic* disabled_material;
	
protected:
	//~ Begin UWidget Interface
	virtual TSharedRef<SWidget> RebuildWidget() override;
	virtual void SynchronizeProperties() override;
	//~ End UWidget Interface
};
