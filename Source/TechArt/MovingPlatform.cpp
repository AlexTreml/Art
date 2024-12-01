// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"
#include "Components/StaticMeshComponent.h"

AMovingPlatform::AMovingPlatform()
{
    PrimaryActorTick.bCanEverTick = true;

    // Create the Static Mesh component and set it as the root component
    PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));
    SetRootComponent(PlatformMesh); // Use SetRootComponent to ensure it's recognized as the root
}

void AMovingPlatform::BeginPlay()
{
    Super::BeginPlay();

    // Initialize positions
    StartLocation = GetActorLocation();
    bMovingToEnd = true;

    // Determine initial direction
    CurrentDirection = (EndLocation - StartLocation).GetSafeNormal();
}

void AMovingPlatform::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Calculate the distance to move this frame
    FVector TargetLocation = GetActorLocation() + (CurrentDirection * Speed * DeltaTime);
    SetActorLocation(TargetLocation);

    // Check if reached target
    float DistanceToTarget = FVector::Dist(GetActorLocation(), bMovingToEnd ? EndLocation : StartLocation);
    if (DistanceToTarget <= Speed * DeltaTime)
    {
        // Toggle direction
        bMovingToEnd = !bMovingToEnd;
        CurrentDirection *= -1.0f;
    }
}