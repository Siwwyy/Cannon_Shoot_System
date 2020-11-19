#include "Actor_Components/Object_Pool.h"
#include "Object_Cannon_Ball.h"

#include "Engine.h"


UObject_Pool::UObject_Pool()
{
	PrimaryComponentTick.bCanEverTick = false;
}

AObject_Cannon_Ball* UObject_Pool::Get_PooledObject()
{
	for(const auto& Poolable_Actor: Pool_Array)
	{
		if(!Poolable_Actor->Get_IsActive())
		{
			return Poolable_Actor;
		}
	}
	return nullptr;
}

void UObject_Pool::BeginPlay()
{
	Super::BeginPlay();

	if(!PooledObject_SubClass)
	{
		return;
	}

	UWorld * const World = GetWorld();
	if(World)
	{
		for(int32 i = 0; i < Pool_Size; ++i)
		{
			AObject_Cannon_Ball * Pooled_Actor = GetWorld()->SpawnActor<AObject_Cannon_Ball>(PooledObject_SubClass, FVector().ZeroVector, FRotator().ZeroRotator);
			Pool_Array.Add(Pooled_Actor);
		}
	}
}