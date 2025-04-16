// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActor.h"
#include "ROS2NodeComponent.h"
#include "ROS2Subscriber.h"
#include "Msgs/ROS2Str.h"

// Sets default values
AMyActor::AMyActor()
{
    PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Warning, TEXT("BeginPlay do AMyActor chamado! (apenas subscriber)"));

    NodeComponent = NewObject<UROS2NodeComponent>(this, TEXT("ROSNode"));
    NodeComponent->RegisterComponent();
    NodeComponent->Init();

    FSubscriptionCallback Callback;
    Callback.BindUFunction(this, FName("OnMessageReceived"));
    Subscriber = NodeComponent->CreateSubscriber(
        TEXT("/teste_unreal"),
        UROS2StrMsg::StaticClass(),
        Callback,
        UROS2QoS::SensorData
    );

    if (Subscriber) {
        UE_LOG(LogTemp, Warning, TEXT("Subscriber criado com sucesso! (AMyActor)"));
    } else {
        UE_LOG(LogTemp, Error, TEXT("Falha ao criar o subscriber! (AMyActor)"));
    }
}

void AMyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (NodeComponent)
    {
        UE_LOG(LogTemp, Log, TEXT("[DEBUG] NodeComponent State: %d"), (int)NodeComponent->State);
    }
}

void AMyActor::OnMessageReceived(const UROS2GenericMsg* InMsg)
{
    UE_LOG(LogTemp, Error, TEXT(">>> CALLBACK RECEBIDO! (AMyActor)"));
    const UROS2StrMsg* StringMsg = Cast<UROS2StrMsg>(InMsg);
    if (!StringMsg) return;
    FROSStr MsgData;
    StringMsg->GetMsg(MsgData);
    UE_LOG(LogTemp, Log, TEXT("[Recebendo] %s"), *MsgData.Data);
}

