
#include "Characters/Engine_Character.h"


#include "TimerManager.h"
#include "Actors/Cannon_Ball_ObjectPool.h"
#include "Actor_Components/Object_Pool.h"
#include "Engine/World.h"


AEngine_Character::AEngine_Character()
{
	PrimaryActorTick.bCanEverTick = false;

	Object_Pooler = CreateDefaultSubobject<UObject_Pool>(TEXT("Object_Pooler"));
}