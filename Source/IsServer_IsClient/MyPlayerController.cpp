// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPlayerController.h"

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogInit, Error, TEXT("a"));
	if (GEngine)
	{
		constexpr auto displayTime = 999.f;
		FString role;
		switch (Role)
		{
		case ROLE_Authority: role = "Authority"; break;
		case ROLE_AutonomousProxy: role = "Owner"; break;
		case ROLE_SimulatedProxy: role = "Proxy"; break;
		}
		GEngine->AddOnScreenDebugMessage(-1, displayTime, FColor::Emerald,
			FString::Printf(TEXT("%s: role %s"), *this->GetName(), *role)
		);
		GEngine->AddOnScreenDebugMessage(-1, displayTime, FColor::Cyan,
			FString::Printf(TEXT("%s: GetWorld()->IsServer() = %i vs. GIsServer = %i"),
				*this->GetName(), GetWorld()->IsServer(), GIsServer
			)
		);
		GEngine->AddOnScreenDebugMessage(-1, displayTime, FColor::Orange,
			FString::Printf(TEXT("%s: GetWorld()->IsClient() = %i vs. GIsClient = %i"),
				*this->GetName(), GetWorld()->IsClient(), GIsClient
			)
		);
	}
}