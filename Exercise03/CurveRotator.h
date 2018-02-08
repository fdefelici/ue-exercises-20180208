// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Curves/CurveBase.h"
#include "CurveRotator.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class EXERCISE03_API UCurveRotator : public UCurveBase
{
	GENERATED_BODY()
public:
	UCurveRotator(const FObjectInitializer& ObjectInitializer);

	/** Keyframe data, one curve for X, Y and Z */
	UPROPERTY()
	FRichCurve FloatCurves[3];

	/** Evaluate this float curve at the specified time */
	UFUNCTION(BlueprintCallable, Category = "Math|Curves")
	FRotator GetRotatorValue(float InTime) const;

	// Begin FCurveOwnerInterface
	virtual TArray<FRichCurveEditInfoConst> GetCurves() const override;
	virtual TArray<FRichCurveEditInfo> GetCurves() override;

	/** Determine if Curve is the same */
	bool operator == (const UCurveRotator& Curve) const;

	virtual bool IsValidCurve(FRichCurveEditInfo CurveInfo) override;
};
