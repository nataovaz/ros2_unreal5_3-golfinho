// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ROS2NodeComponent.h"
#include "ROS2Publisher.h"
#include "ROS2Subscriber.h"
#include "MyActor.generated.h"

UCLASS()
class CAMPUS_ITABIRA_API AMyActor : public AActor
{
    GENERATED_BODY()

public:    
    // Sets default values for this actor's properties
    AMyActor();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:    
    // Called every frame
    virtual void Tick(float DeltaTime) override;

private:
    UPROPERTY()
    UROS2NodeComponent* NodeComponent;

    UPROPERTY()
    UROS2Subscriber* Subscriber;

    UFUNCTION()
    void OnMessageReceived(const UROS2GenericMsg* InMsg);
};
