//Copyright 2020, Damian Andrysiak. All rights reserved
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cannon_Ball_ObjectPool.generated.h"

UCLASS()
class SHIP_CANNON_API ACannon_Ball_ObjectPool : public AActor
{
	GENERATED_BODY()

public:
	ACannon_Ball_ObjectPool();

	virtual void SetLifeSpan(float LifeSpan) override;

	UFUNCTION(BlueprintCallable, Category = "Functions")
		void Set_IsActive(bool IsActive);

	UFUNCTION(BlueprintCallable, Category = "Functions")
		void Deactivate();

	bool Get_IsActive() const;
	
protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mesh")
		class UStaticMeshComponent * Mesh;
	
	float LifeSpan = 5.f;
	
	FTimerHandle LifeSpan_Timer;

	bool IsActive;

};