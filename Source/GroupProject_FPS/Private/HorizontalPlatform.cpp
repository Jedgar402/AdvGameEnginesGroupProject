// Fill out your copyright notice in the Description page of Project Settings.


#include "HorizontalPlatform.h"

// Sets default values for this component's properties
UHorizontalPlatform::UHorizontalPlatform()
{
    PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UHorizontalPlatform::BeginPlay()
{
    Super::BeginPlay();

    // Store the initial location of the platform
    InitialLocation = GetOwner()->GetActorLocation();

    // Set the target distance relative to the initial location
    TargetDistance += InitialLocation.X;

    // Set the current location to the initial location
    CurrentLocation = InitialLocation;
}

// Called every frame
void UHorizontalPlatform::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    // Move the platform left and right
    MovePlatform(DeltaTime);
}

void UHorizontalPlatform::MovePlatform(float DeltaTime)
{
    // Check if the platform has reached the left or right
    if (CurrentLocation.X >= TargetDistance || CurrentLocation.X <= InitialLocation.X)
    {
        // Change the direction of movement
        MoveSpeed *= -1;
    }

    // Update the current location based on the movement direction
    CurrentLocation.X += MoveSpeed * DeltaTime;

    // Set the new location
    GetOwner()->SetActorLocation(CurrentLocation);
}


