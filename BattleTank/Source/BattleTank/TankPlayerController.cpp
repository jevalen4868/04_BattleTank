// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay() {
    Super::BeginPlay();
    UE_LOG(LogTemp, Warning, TEXT("Player controller beginPlay"));
    auto ControlledTank {GetControlledTank()};
    if(!ControlledTank) {
      UE_LOG(LogTemp, Warning, TEXT("Player controller not possessing a tank"));      
    } else {
        UE_LOG(LogTemp, Warning, TEXT("Player controller possessing: %s"), *(ControlledTank->GetName()));
    }
    
    //UE_LOG(LogTemp, Warning, TEXT());    
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    //UE_LOG(LogTemp, Warning, TEXT("Ticking away..."));      
}

ATank* ATankPlayerController::GetControlledTank() const {
    return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair() {
    if(!GetControlledTank()) { return; }
    // get world location if linetrace through crosshair.
    // If it hits the landscape
        // Tell controlled tank to aim at this point.
}
