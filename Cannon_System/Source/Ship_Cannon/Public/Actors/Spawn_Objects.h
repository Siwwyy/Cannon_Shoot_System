//Copyright 2020, Damian Andrysiak. All rights reserved
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawn_Objects.generated.h"



UCLASS()
class SHIP_CANNON_API ASpawn_Objects : public AActor
{
	GENERATED_BODY()

public:
	ASpawn_Objects();

protected:
	virtual void BeginPlay() override;

private:

	float Get_LifeSpan();

	class UBoxComponent* Spawn_Volume;

	UPROPERTY(EditAnywhere, Category = "Spawner")
		class UObject_Pool* Object_Pooler;

	UPROPERTY(EditAnywhere, Category = "Spawner")
		bool Trigger;

	UPROPERTY(EditAnywhere, Category = "Spawner")
		float Life_Span = 5.f;

	UPROPERTY(EditAnywhere, Category = "Spawner")
		float Spawn_Cooldown = 1.2f;

	FTimerHandle Spawn_CoolDown_Timer;

	void Spawn();
};