#include "Actors/Cannon_Ball_ObjectPool.h"

#include "TimerManager.h"
#include "Engine/Engine.h"
#include "Components/StaticMeshComponent.h"


ACannon_Ball_ObjectPool::ACannon_Ball_ObjectPool()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	Mesh->SetMobility(EComponentMobility::Static);
	AActor::SetActorHiddenInGame(true);
}

void ACannon_Ball_ObjectPool::SetLifeSpan(float LifeSpan)
{
	this->LifeSpan = LifeSpan;
	GetWorldTimerManager().SetTimer(LifeSpan_Timer, this, &ACannon_Ball_ObjectPool::Deactivate, LifeSpan, false);
}

void ACannon_Ball_ObjectPool::Set_IsActive(bool IsActive)
{
	this->IsActive = IsActive;
	Mesh->SetMobility(EComponentMobility::Movable);
}

bool ACannon_Ball_ObjectPool::Get_IsActive() const
{
	return IsActive;
}

void ACannon_Ball_ObjectPool::Deactivate()
{
	Set_IsActive(false);
	AActor::SetActorHiddenInGame(true);
	Mesh->SetMobility(EComponentMobility::Static);
	GetWorldTimerManager().ClearTimer(LifeSpan_Timer);
}