// Fill out your copyright notice in the Description page of Project Settings.


#include "CognitiveTrainingUtils.h"

TArray<FString> UCognitiveTrainingUtils::BreakWordIntoSpells(const FString& word, bool allow_dublicates)
{
	TArray<FString> result;
	auto uppered = word.ToUpper();
	for (auto _char : uppered)
	{
		auto str = FString().AppendChar(_char);
		if (allow_dublicates || !result.Contains(str))
			result.Add(str);
	}
	return result;
}

TArray<FString> UCognitiveTrainingUtils::GenerateEncoding(const TArray<FString>& spells)
{
	TArray<FString> result;

	return result;
}
