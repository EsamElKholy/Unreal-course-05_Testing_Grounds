// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
#pragma once 
#include "GameFramework/HUD.h"
#include "S05_Testing_GroundsHUD.generated.h"

UCLASS()
class AS05_Testing_GroundsHUD : public AHUD
{
	GENERATED_BODY()

public:
	AS05_Testing_GroundsHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

