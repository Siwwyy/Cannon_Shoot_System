#include "Actors/Spawn_Objects.h"

#include "TimerManager.h"
#include "Actors/Cannon_Ball_ObjectPool.h"
#include "Actor_Components/Object_Pool.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "Components/BoxComponent.h"


ASpawn_Objects::ASpawn_Objects()
{
	PrimaryActorTick.bCanEverTick = false;
	Spawn_Volume = CreateDefaultSubobject<UBoxComponent>(TEXT("Spawn_Volume"));
	RootComponent = Spawn_Volume;

	Object_Pooler = CreateDefaultSubobject<UObject_Pool>(TEXT("Object_Pooler"));
}

void ASpawn_Objects::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(Spawn_CoolDown_Timer, this, &ASpawn_Objects::Spawn, Spawn_Cooldown, false);
}

float ASpawn_Objects::Get_LifeSpan()
{
	return Life_Span;
}

void ASpawn_Objects::Spawn()
{
	ACharacter* My_Character = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	//ACannon_Ball_ObjectPool* Poolable_Actor = Object_Pooler->Get_PooledObject();

	//if (!Poolable_Actor)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("Cannot Spawn"));
	//	GetWorldTimerManager().SetTimer(Spawn_CoolDown_Timer, this, &ASpawn_Objects::Spawn, Spawn_Cooldown, false);
	//	return;
	//}

	//Poolable_Actor->SetActorLocation(My_Character->GetNavAgentLocation());
	//Poolable_Actor->SetLifeSpan(Life_Span);
	//Poolable_Actor->Set_IsActive(true);
	//Poolable_Actor->SetActorRotation(My_Character->GetActorRotation());
	//GetWorldTimerManager().SetTimer(Spawn_CoolDown_Timer, this, &ASpawn_Objects::Spawn, Spawn_Cooldown, false);
	//UE_LOG(LogTemp, Warning, TEXT("Spawning"));
}
