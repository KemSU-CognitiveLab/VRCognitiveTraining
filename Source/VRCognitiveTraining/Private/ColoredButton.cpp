// Fill out your copyright notice in the Description page of Project Settings.


#include "ColoredButton.h"

UColoredButton::UColoredButton()
{
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> BaseMaterialAsset(TEXT("Material'/Game/UI/M_ColoredCircleButton.M_ColoredCircleButton'"));
	base_material = BaseMaterialAsset.Object;
}

TSharedRef<SWidget> UColoredButton::RebuildWidget()
{
	auto widget = Super::RebuildWidget();
	normal_material = UMaterialInstanceDynamic::Create(base_material, this);
	hovered_material = UMaterialInstanceDynamic::Create(base_material, this);
	pressed_material = UMaterialInstanceDynamic::Create(base_material, this);
	disabled_material = UMaterialInstanceDynamic::Create(base_material, this);
	FButtonStyle style;
	FSlateBrush normal_brush, hovered_brush, pressed_brush, disabled_brush;
	normal_brush.DrawAs = ESlateBrushDrawType::Image;
	normal_brush.SetResourceObject(normal_material);
	style.SetNormal(normal_brush);
	hovered_brush.DrawAs = ESlateBrushDrawType::Image;
	hovered_brush.SetResourceObject(hovered_material);
	style.SetHovered(hovered_brush);
	pressed_brush.DrawAs = ESlateBrushDrawType::Image;
	pressed_brush.SetResourceObject(pressed_material);
	style.SetPressed(pressed_brush);
	disabled_brush.DrawAs = ESlateBrushDrawType::Image;
	disabled_brush.SetResourceObject(disabled_material);
	style.SetDisabled(disabled_brush);
	SetStyle(style);
	return widget;
}

void UColoredButton::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	auto hovered_color = ColorAndOpacity;//make it brighter
	normal_material->SetVectorParameterValue(TEXT("Color"), ColorAndOpacity);
	hovered_material->SetVectorParameterValue(TEXT("Color"), hovered_color);
	pressed_material->SetVectorParameterValue(TEXT("Color"), FLinearColor::Gray);
	disabled_material->SetVectorParameterValue(TEXT("Color"), FLinearColor::Gray);
}
