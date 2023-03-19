// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/TextureRenderTarget2D.h"
#include "CognitiveTrainingUtils.generated.h"

UCLASS(BlueprintType, Blueprintable)
class USymbolEncoding : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
	FString Symbol = TEXT("");
	UPROPERTY(BlueprintReadWrite)
	TArray<FColor> Colors;
};

UCLASS(BlueprintType, Blueprintable)
class UColorObject : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
	FColor Color;
};

/**
 * 
 */
UCLASS()
class UCognitiveTrainingUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable, Category = "Room01")
	static TArray<FString> BreakWordIntoCharacters(const FString& word, bool allow_dublicates = false);
	UFUNCTION(BlueprintCallable, Category = "Room01")
	static TArray<int> RandomSample(int SetLength, int SampleLength);
	UFUNCTION(BlueprintCallable, Category = "Room01")
	static TMap<FString, FString> GenerateEncoding(const FString& password, int desired_colors_count_per_symbol = 0);
};
