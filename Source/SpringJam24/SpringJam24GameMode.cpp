// Copyright Epic Games, Inc. All Rights Reserved.

#include "SpringJam24GameMode.h"
#include "SpringJam24PlayerController.h"
#include "SpringJam24Character.h"
#include "UObject/ConstructorHelpers.h"

ASpringJam24GameMode::ASpringJam24GameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ASpringJam24PlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}