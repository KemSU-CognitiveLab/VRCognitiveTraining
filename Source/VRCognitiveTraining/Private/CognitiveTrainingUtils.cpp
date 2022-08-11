// Fill out your copyright notice in the Description page of Project Settings.


#include "CognitiveTrainingUtils.h"
#include "Kismet/KismetArrayLibrary.h"

TArray<FString> UCognitiveTrainingUtils::BreakWordIntoCharacters(const FString& word, bool allow_dublicates)
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

TArray<int> UCognitiveTrainingUtils::RandomSample(int SetLength, int SampleLength)
{
	TArray<int> sample;
	int Max = SetLength - 1;
	for (int i = 0; i < SampleLength; ++i)
	{
		auto r = FMath::RandRange(SampleLength - i - 1, Max);
		sample.Add(r);
		Max = r - 1;
	}
	return sample;
}

template <class T>
void ShuffleArray(T& InArray)
{
	const int32 LastIndex = InArray.Num() - 1;
	for (int32 i = 0; i < LastIndex; ++i)
	{
		int32 Index = FMath::RandRange(0, LastIndex);
		if (i != Index)
		{
			InArray.Swap(i, Index);
		}
	}
}

TMap<FString, FString> UCognitiveTrainingUtils::GenerateEncoding(const FString& password, int desired_colors_count_per_symbol)
{
	TMap<FString, FString> encoding;
	const TCHAR* colors = TEXT("ROYGCBP");
	const int combinations_count[] = {7, 42, 210, 840, 2520, 5040, 5040};//C(^k)(_n) * k! where k is colors_count and n = 7 becauses 7 colors in total
	auto symbols = BreakWordIntoCharacters(password);
	ShuffleArray(symbols);

	int min_colors_count_per_symbol = 0;
	while (symbols.Num() > combinations_count[min_colors_count_per_symbol])
		min_colors_count_per_symbol++;

	int colors_count_per_symbol = FMath::Max(desired_colors_count_per_symbol, min_colors_count_per_symbol);
	UE_LOG(LogTemp, Display, TEXT("%i"), colors_count_per_symbol);
	TArray<FString> used_color_chooses;
	for (auto _char : symbols)
	{
		FString coding_colors;
		do {
			coding_colors.Empty(7);
			auto choose = RandomSample(7, colors_count_per_symbol + 1);
			for (auto i : choose)
				coding_colors.AppendChar(colors[i]);
			UE_LOG(LogTemp, Display, TEXT("%s"), *coding_colors);
		}
		while (used_color_chooses.Contains(coding_colors));
		used_color_chooses.Add(coding_colors);
		encoding.Add(_char, coding_colors);
	}
	return encoding;
}


