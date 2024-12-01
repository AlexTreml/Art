// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "MovingPlatform.generated.h"

UCLASS()
class TECHART_API AMovingPlatform : public AActor
{
    GENERATED_BODY()

public:
    AMovingPlatform();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    // Static Mesh component for the platform
    UPROPERTY(VisibleAnywhere, Category = "Platform")
    UStaticMeshComponent* PlatformMesh;

    // Movement properties
    UPROPERTY(EditAnywhere, Category = "Movement")
    FVector StartLocation;

    UPROPERTY(EditAnywhere, Category = "Movement")
    FVector EndLocation;

    UPROPERTY(EditAnywhere, Category = "Movement")
    float Speed = 200.0f;

private:
    FVector CurrentDirection;
    bool bMovingToEnd;
};