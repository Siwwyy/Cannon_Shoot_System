#include "Object_Cannon_Ball.h"

#include "TimerManager.h"
#include "Engine/Engine.h"
#include "Components/StaticMeshComponent.h"


AObject_Cannon_Ball::AObject_Cannon_Ball()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	Mesh->SetMobility(EComponentMobility::Static);
	AActor::SetActorHiddenInGame(true);
}

void AObject_Cannon_Ball::SetLifeSpan(float LifeSpan)
{
	this->LifeSpan = LifeSpan;
	GetWorldTimerManager().SetTimer(LifeSpan_Timer, this, &AObject_Cannon_Ball::Deactivate, LifeSpan, false);
}

void AObject_Cannon_Ball::Set_IsActive(bool IsActive)
{
	this->IsActive = IsActive;
}

bool AObject_Cannon_Ball::Get_IsActive() const
{
	return IsActive;
}

void AObject_Cannon_Ball::Deactivate()
{
	Set_IsActive(false);
	AActor::SetActorHiddenInGame(true);
	Mesh->SetMobility(EComponentMobility::Static);
	GetWorldTimerManager().ClearTimer(LifeSpan_Timer);
}