// Fill out your copyright notice in the Description page of Project Settings.

#include "CurveVectorMoveComponent.h"


// Sets default values for this component's properties
UCurveVectorMoveComponent::UCurveVectorMoveComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	Speed = 1;
}


// Called when the game starts
void UCurveVectorMoveComponent::BeginPlay()
{
	Super::BeginPlay();

	ElapsedTime = 0;

	float min, max;
	VectorCurve->GetTimeRange(min, max);
	CurveMaxTime = max;
	Actor = GetOwner();
}


// Called every frame
void UCurveVectorMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	//1) Updated elapsed time related to the Curve Length
	ElapsedTime += DeltaTime * Speed;
	if (ElapsedTime > CurveMaxTime) {
		ElapsedTime -= CurveMaxTime;
	}
	//2) Get Vector Value
	FVector currentVectorValue = VectorCurve->GetVectorValue(ElapsedTime);
	
	//3) Set Actor Location
	Actor->SetActorLocation(currentVectorValue, false);

}

