// Fill out your copyright notice in the Description page of Project Settings.

#include "CurveRotator.h"


UCurveRotator::UCurveRotator(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

FRotator UCurveRotator::GetRotatorValue(float InTime) const
{
	FRotator Result;
	Result.Roll = FloatCurves[0].Eval(InTime);
	Result.Pitch = FloatCurves[1].Eval(InTime);
	Result.Yaw = FloatCurves[2].Eval(InTime);
	return Result;
}

static const FName XCurveName(TEXT("Roll  (X)"));
static const FName YCurveName(TEXT("Pitch (Y)"));
static const FName ZCurveName(TEXT("Yaw   (Z)"));

TArray<FRichCurveEditInfoConst> UCurveRotator::GetCurves() const
{
	TArray<FRichCurveEditInfoConst> Curves;
	Curves.Add(FRichCurveEditInfoConst(&FloatCurves[0], XCurveName));
	Curves.Add(FRichCurveEditInfoConst(&FloatCurves[1], YCurveName));
	Curves.Add(FRichCurveEditInfoConst(&FloatCurves[2], ZCurveName));
	return Curves;
}

TArray<FRichCurveEditInfo> UCurveRotator::GetCurves()
{
	TArray<FRichCurveEditInfo> Curves;
	Curves.Add(FRichCurveEditInfo(&FloatCurves[0], XCurveName));
	Curves.Add(FRichCurveEditInfo(&FloatCurves[1], YCurveName));
	Curves.Add(FRichCurveEditInfo(&FloatCurves[2], ZCurveName));
	return Curves;
}

bool UCurveRotator::operator==(const UCurveRotator& Curve) const
{
	return (FloatCurves[0] == Curve.FloatCurves[0]) && (FloatCurves[1] == Curve.FloatCurves[1]) && (FloatCurves[2] == Curve.FloatCurves[2]);
}

bool UCurveRotator::IsValidCurve(FRichCurveEditInfo CurveInfo)
{
	return CurveInfo.CurveToEdit == &FloatCurves[0] ||
		CurveInfo.CurveToEdit == &FloatCurves[1] ||
		CurveInfo.CurveToEdit == &FloatCurves[2];
}

