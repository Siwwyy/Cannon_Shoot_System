//Copyright 2020, Damian Andrysiak. All rights reserved
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Object_Pool.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SHIP_CANNON_API UObject_Pool : public UActorComponent
{
	GENERATED_BODY()

public:
	UObject_Pool();

	UFUNCTION(BlueprintCallable, Category = "ObjectPooler")
	class AObject_Cannon_Ball* Get_PooledObject();

protected:
	virtual void BeginPlay() override;

public:

	UPROPERTY(EditAnywhere, Category = "ObjectPooler")
		TSubclassOf<class AObject_Cannon_Ball> PooledObject_SubClass;

	UPROPERTY(EditAnywhere, Category = "ObjectPooler")
		int32 Pool_Size = 8;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ObjectPooler")
		TArray<class AObject_Cannon_Ball*> Pool_Array;
};