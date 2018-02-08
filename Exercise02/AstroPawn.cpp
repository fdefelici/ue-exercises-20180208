// Fill out your copyright notice in the Description page of Project Settings.

#include "AstroPawn.h"


// Sets default values
AAstroPawn::AAstroPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;
	USphereComponent* newRootComp = CreateDefaultSubobject<USphereComponent>(TEXT("PawnRoot"));
	newRootComp->InitSphereRadius(50.0f);
	newRootComp->SetCollisionProfileName(TEXT("PawnCollider"));
	RootComponent = newRootComp;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PawnMesh"));
	Mesh->SetupAttachment(RootComponent);

	// Don't rotate when the controller rotates.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Create a camera boom attached to the root (capsule)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bAbsoluteRotation = true; // Rotation of the character should not affect rotation of boom
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->TargetArmLength = 500.f;
	CameraBoom->SocketOffset = FVector(0.f, 0.f, 75.f);
	CameraBoom->RelativeRotation = FRotator(0.f, 180.f, 0.f);

	// Create a camera and attach to boom
	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	SideViewCameraComponent->bUsePawnControlRotation = false; // We don't want the controller rotating the camera

	MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));
	MovementComponent->UpdatedComponent = RootComponent;

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void AAstroPawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AAstroPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAstroPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveHoriz", this, &AAstroPawn::MoveHoriz);
	PlayerInputComponent->BindAxis("MoveVert", this, &AAstroPawn::MoveVert);

}

void AAstroPawn::MoveVert(float Val)
{
	MovementComponent->AddInputVector(FVector(0,0, Val), true);
}

void AAstroPawn::MoveHoriz(float Val)
{
	MovementComponent->AddInputVector(FVector(0, -Val, 0), true);
}

