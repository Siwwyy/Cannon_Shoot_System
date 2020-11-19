//Copyright 2020, Damian Andrysiak. All rights reserved
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Object_Cannon_Ball.generated.h"

UCLASS()
class SHIP_CANNON_API AObject_Cannon_Ball : public AActor
{
	GENERATED_BODY()
	
public:
	AObject_Cannon_Ball();

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