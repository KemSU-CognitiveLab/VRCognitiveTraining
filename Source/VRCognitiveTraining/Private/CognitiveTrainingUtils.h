// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CognitiveTrainingUtils.generated.h"

/**
 * 
 */
UCLASS()
class UCognitiveTrainingUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable, Category = "Room01")
	static TArray<FString> BreakWordIntoSpells(const FString& word, bool allow_dublicates = false);
	UFUNCTION(BlueprintCallable, Category = "Room01")
	static TArray<FString> GenerateEncoding(const TArray<FString>& spells);
};
