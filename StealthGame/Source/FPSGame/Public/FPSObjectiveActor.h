// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPSObjectiveActor.generated.h"

class USphereComponent;

UCLASS()
class FPSGAME_API AFPSObjectiveActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPSObjectiveActor();

protected:

	UPROPERTY(VisibleAnyWhere, Category = "Components")
	UStaticMeshComponent* MeshComp;
	 
	UPROPERTY(VisibleAnyWhere, Category = "Components")
	USphereComponent* SphereComp;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Effects")
	UParticleSystem* PickupFX;

	// 播放特效
	void PlayEffects();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 重写这个公有函数
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
};
