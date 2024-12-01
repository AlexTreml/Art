// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JumpPad.generated.h"

UCLASS()
class TECHART_API AJumpPad : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AJumpPad();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:
	
	UPROPERTY(EditDefaultsOnly)
	class UStaticMeshComponent* JumpPadMesh;

	UPROPERTY(EditDefaultsOnly)
	class UBoxComponent* JumpPadTriggerVolume;

	UPROPERTY(EditDefaultsOnly)
	class UMaterialInterface* InactiveMaterial;

	UPROPERTY(EditDefaultsOnly)
	class UMaterialInterface* ActiveMaterial;



	UFUNCTION()
	void JumpPadTriggered(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void JumpPadEndTriggered(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};