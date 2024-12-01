// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatformCplus.h"
#include "Components/BoxComponent.h"
#include "Components/InterpToMovementComponent.h"

// Sets default values
AMovingPlatformCplus::AMovingPlatformCplus()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collider"));
	RootComponent = BoxCollider;

	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Platform's Mesh"));
	PlatformMesh ->SetupAttachment(RootComponent);

	MovementComponent = CreateDefaultSubobject<UInterpToMovementComponent>(TEXT("Movement Component"));

	//setting up deafault parameterss
	MovementComponent->Duration = 5.0f;
	MovementComponent->bSweep = true;
	MovementComponent->BehaviourType = EInterpToBehaviourType::PingPong;
}

// Called when the game starts or when spawned
void AMovingPlatformCplus::BeginPlay()
{
	Super::BeginPlay();
	//setting up control points for movement ont he path
	MovementComponent->ControlPoints.Add(FInterpControlPoint(FVector(0.f, 0.f, 0.f), true));
	for(int i= 0; i < ThePath.Num(); i++)
	{ 
		MovementComponent->ControlPoints.Add(FInterpControlPoint(ThePath [i], true));

	}
	MovementComponent->FinaliseControlPoints();
}

// Called every frame
void AMovingPlatformCplus::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

