// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/CurveFactory.h"
#include "CurveRotator.h"
#include "CurveRotatorFactory.generated.h"

/**
 * 
 */
UCLASS()
class EXERCISE03_API UCurveRotatorFactory : public UCurveFactory
{
	GENERATED_BODY()
public:
	UCurveRotatorFactory(const FObjectInitializer& ObjectInitializer);

	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	// UFactory interface
	virtual bool ConfigureProperties() override { return true; }
	virtual bool ShouldShowInNewMenu() const override { return false; }
	// End of UFactory interface
	
};
