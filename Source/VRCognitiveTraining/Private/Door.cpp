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
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	RootComponent = Mesh;
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->SetupAttachment(RootComponent);
	static ConstructorHelpers::FClassFinder<UUserWidget> UI_DoorFinder(TEXT("/Game/UI/UI_Door"));
	DoorUIClass = UI_DoorFinder.Class;
	TextUI = CreateDefaultSubobject<UWidgetComponent>(TEXT("TextUI"));
	TextUI->SetupAttachment(RootComponent);
	TextUI->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	TextUI->SetWidgetClass(DoorUIClass);
	TextUI->SetDrawSize(FVector2D(200.0f, 100.0f));
	TextUI->SetVisibility(false);
}

void ADoor::BeginPlay()
{
	Super::BeginPlay();
}

void ADoor::Unlock()
{
	if (bIsLocked)
	{
		bIsLocked = false;
		auto textbox = Cast<UEditableText>(TextUI->GetWidget()->GetWidgetFromName(TEXT("text_DoorText")));
		if (IsValid(textbox))
			textbox->SetText(FText::FromString(TEXT("Click: Open")));
	}
}

void ADoor::Lock()
{
	if (!bIsLocked)
	{
		bIsLocked = true;
		auto textbox = Cast<UEditableText>(TextUI->GetWidget()->GetWidgetFromName(TEXT("text_DoorText")));
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
	TextUI->SetVisibility(true);
}

void ADoor::EndOverlapByController()
{
	TextUI->SetVisibility(false);
}
