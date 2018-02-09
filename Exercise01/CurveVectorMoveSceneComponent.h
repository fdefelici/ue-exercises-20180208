// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Curves/CurveVector.h"
#include "CurveVectorMoveSceneComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EXERCISE01_API UCurveVectorMoveSceneComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	UPROPERTY(EditAnywhere)
	UCurveVector* VectorCurve;
	//Execution speed of a complete curve. [1 is the curve time]
	UPROPERTY(EditAnywhere)
	float Speed;

	// Sets default values for this component's properties
	UCurveVectorMoveSceneComponent();
	//The Vector Curve describing the movement over time
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;

private:
	float ElapsedTime;
	float CurveMaxTime;
	//AActor* Actor;
};
