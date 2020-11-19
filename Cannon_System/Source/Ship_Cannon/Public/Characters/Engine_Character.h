//Copyright 2020, Damian Andrysiak. All rights reserved
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Engine_Character.generated.h"

UCLASS()
class SHIP_CANNON_API AEngine_Character : public ACharacter
{
	GENERATED_BODY()

public:
	AEngine_Character();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner", meta = (AllowProtectedAccess = "true"))
		class UObject_Pool* Object_Pooler;

	FTimerHandle Spawn_CoolDown_Timer;
};