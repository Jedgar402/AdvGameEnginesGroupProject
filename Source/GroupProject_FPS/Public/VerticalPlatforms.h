// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "VerticalPlatforms.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GROUPPROJECT_FPS_API UVerticalPlatforms : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UVerticalPlatforms();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Function to move the platform up and down
	void MovePlatform(float DeltaTime);

private:
	// Target height for the platform's movement
	UPROPERTY(EditAnywhere, Category = "Vertical Platform")
	float TargetHeight = 20.f;

	// Speed at which the platform moves
	UPROPERTY(EditAnywhere, Category = "Vertical Platform")
	float MoveSpeed = 50.f;

	// Initial location of the platform
	FVector InitialLocation;

	// Current location of the platform
	FVector CurrentLocation;
};
