// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay() {
    Super::BeginPlay();
    UE_LOG(LogTemp, Warning, TEXT("AI controller beginPlay"));
    auto ControlledTank {GetControlledTank()};
    if(!ControlledTank) {
        UE_LOG(LogTemp, Warning, TEXT("AI controller not possessing a tank"));      
    } else {
        UE_LOG(LogTemp, Warning, TEXT("AI controller possessing: %s"), *(ControlledTank->GetName()));
    }

    auto PlayerTank {GetPlayerTank()};

    if(!PlayerTank) {
        UE_LOG(LogTemp, Warning, TEXT("AI controller not targeting the player tank"));      
    } else {
        UE_LOG(LogTemp, Warning, TEXT("AI controller targeting: %s"), *(PlayerTank->GetName()));
    }
    
    //UE_LOG(LogTemp, Warning, TEXT());    
}

ATank* ATankAIController::GetControlledTank() const {
    return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {
    UWorld* World {GetWorld()};
    auto PlayerPawn = World->GetFirstPlayerController()->GetPawn();
    return Cast<ATank>(PlayerPawn);
}
