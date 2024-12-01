// Fill out your copyright notice in the Description page of Project Settings.


#include "JumpPad.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Character.h"


// Sets default values
AJumpPad::AJumpPad()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//initialise Mesh
	JumpPadMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Jump Pad Mesh"));
	//initialise trigger volume
	JumpPadTriggerVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("Jump Pad Trigger Volume"));
	JumpPadTriggerVolume->SetupAttachment(JumpPadMesh);

}

// Called when the game starts or when spawned
void AJumpPad::BeginPlay()
{
	Super::BeginPlay();
	
	JumpPadMesh->SetMaterial(0, InactiveMaterial);

	//binding created functions to Unreal events
	JumpPadTriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &AJumpPad::JumpPadTriggered);
	JumpPadTriggerVolume->OnComponentEndOverlap.AddDynamic(this, &AJumpPad::JumpPadEndTriggered);

}

// Called every frame
void AJumpPad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AJumpPad::JumpPadTriggered(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//check to see if actor is character
	if (ACharacter* ourChar = Cast<ACharacter>(OtherActor))
	{
		//check if capsule component
		if (Cast<UCapsuleComponent>(OtherComp) == ourChar->GetCapsuleComponent())
		{
			//then change material
			JumpPadMesh->SetMaterial(0, ActiveMaterial);
			//prep character larger jump
			ourChar->GetCharacterMovement()->JumpZVelocity *= 3;
		}

	}
	
}

void AJumpPad::JumpPadEndTriggered(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//check to see if actor is character
	if (ACharacter* ourChar = Cast<ACharacter>(OtherActor))
	{
		//check if capsule component
		if (Cast<UCapsuleComponent>(OtherComp) == ourChar->GetCapsuleComponent())
		{
			//then change material
			JumpPadMesh->SetMaterial(0, InactiveMaterial);
			//prep character larger jump
			ourChar->GetCharacterMovement()->JumpZVelocity /= 3;
		}

	}

}
