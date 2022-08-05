// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/WidgetComponent.h"
#include "Components/EditableText.h"
#include "Kismet/GameplayStatics.h"

ADoor::ADoor(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer)
{
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	RootComponent = Box;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
	static ConstructorHelpers::FClassFinder<UUserWidget> UI_DoorFinder(TEXT("/Game/UI/UI_Door"));
	DoorUIClass = UI_DoorFinder.Class;
	UI = CreateDefaultSubobject<UWidgetComponent>(TEXT("UI"));
	UI->SetupAttachment(RootComponent);
	UI->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ADoor::BeginPlay()
{
	Super::BeginPlay();
	UI->SetWidgetClass(DoorUIClass);
	UI->SetDrawSize(FVector2D(200.0f, 100.0f));
}

void ADoor::Unlock()
{
	if (bIsLocked)
	{
		bIsLocked = false;
		auto textbox = Cast<UEditableText>(UI->GetWidget()->GetWidgetFromName(TEXT("text_DoorText")));
		textbox->SetText(FText::FromString(TEXT("Click: Open")));
	}
}

void ADoor::Lock()
{
	if (!bIsLocked)
	{
		bIsLocked = true;
		auto textbox = Cast<UEditableText>(UI->GetWidget()->GetWidgetFromName(TEXT("text_DoorText")));
		textbox->SetText(FText::FromString(TEXT("Closed")));
	}
}

void ADoor::OnPressedByTrigger(const FHitResult& hitResult)
{
	if (!bIsLocked)
	{
		UGameplayStatics::OpenLevel(GetWorld(), LevelToLoad);
	}
}

void ADoor::BeginOverlapByController()
{
	UI->SetVisibility(true);
}

void ADoor::EndOverlapByController()
{
	UI->SetVisibility(false);
}
