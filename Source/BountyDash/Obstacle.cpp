// Fill out your copyright notice in the Description page of Project Settings.


#include "BountyDashGameModeBase.h"
#include "Obstacle.h"

// Sets default values
AObstacle::AObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collider = CreateAbstractDefaultSubobject<USphereComponent>(TEXT("Collider"));
	check(Collider);

	RootComponent = Collider;
	Collider->SetCollisionProfileName("OverlapAllDynamic");

	Mesh = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	check(Mesh);
	Mesh->AttachTo(Collider);
	Mesh->SetCollisionResponseToAllChannels(ECR_Ignore);
	KillPoint = 20000.0f;

	OnActorBeginOverlap.AddDynamic(this, &AObstacle::MyOnActorBeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &AObstacle::MyOnActorEndOverlap);
}

// Called when the game starts or when spawned
void AObstacle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float gameSpeed = GetCustomGameMode<ABountyDashGameModeBase>(GetWorld())->GetInvGameSpeed();

	AddActorLocalOffset(FVector(gameSpeed, 0.0f, 0.0f));

	if (GetActorLocation().X < KillPoint)
	{
		Destroy();
	}
}

void AObstacle::SetKillPoint(float point)
{
	KillPoint = point;
}

float AObstacle::GetKillPoint()
{
	return KillPoint;
}

void AObstacle::MyOnActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
}

void AObstacle::MyOnActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
}

