// Fill out your copyright notice in the Description page of Project Settings.


#include "VerticalPlatforms.h"

// Sets default values for this component's properties
UVerticalPlatforms::UVerticalPlatforms()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UVerticalPlatforms::BeginPlay()
{
	Super::BeginPlay();

	// Store the initial location of the platform
	InitialLocation = GetOwner()->GetActorLocation();

	// Set the target height relative to the initial location
	TargetHeight += InitialLocation.Z;

	// Set the current location to the initial location
	CurrentLocation = InitialLocation;
	
}


// Called every frame
void UVerticalPlatforms::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Move the platform up and down
	MovePlatform(DeltaTime);
}

void UVerticalPlatforms::MovePlatform(float DeltaTime)
{
	// Check if the platform has reached the top or bottom
	if (CurrentLocation.Z >= TargetHeight || CurrentLocation.Z <= InitialLocation.Z)
	{
		// Change the direction of movement
		MoveSpeed *= -1;
	}

	// Update the current location based on the movement direction
	CurrentLocation.Z += MoveSpeed * DeltaTime;

	// Set the new location
	GetOwner()->SetActorLocation(CurrentLocation);
}

