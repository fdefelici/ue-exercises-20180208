// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Runtime/Engine/Classes/Curves/CurveVector.h"
#include "CurveVectorMoveComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EXERCISE01_API UCurveVectorMoveComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCurveVectorMoveComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//The Vector Curve describing the movement over time
	UPROPERTY(EditAnywhere)
	UCurveVector* VectorCurve;
	
	//Execution speed of a complete curve. [1 is the curve time]
	UPROPERTY(EditAnywhere)
	float Speed;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:	
	float ElapsedTime;
	float CurveMaxTime;
	AActor* Actor;
};
