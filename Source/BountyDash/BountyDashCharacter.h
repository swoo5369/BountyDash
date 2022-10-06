// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BountyDashCharacter.generated.h"

UCLASS()
class BOUNTYDASH_API ABountyDashCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABountyDashCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


public:
	//이동방향 배열
	UPROPERTY(EditAnyWhere, Category = Logic)
	TArray<class ATargetPoint*> TargetArray;

	//캐릭터 줄 바꿈 속도
	UPROPERTY(EditAnyWhere, Category = Logic)
	float CharSpeed;

	//충돌사운드를 위한 오디오 컴포넌트
	UPROPERTY(EditAnyWhere, Category = sound)
	UAudioComponent* hitObstacleSound;

	//코인 획득 사운드를 위한 오디오 컴포넌트
	UPROPERTY(EditAnyWhere, Category = Sound)
	UAudioComponent* dingSound;

protected:
	//플레이어와 카메라 간의 거리를 유지하기위한 카메라 붐
	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = Camera)
		class USpringArmComponent* CameraBoom;

	//타깃 뷰로 사용할 카메라
	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = Camera)
	class UCameraComponent* FollowCamera;

	//플레이어점수
	UPROPERTY(BlueprintReadOnly)
	int32 Score;

private:
	//캐릭터 선 위치 데이터
	short CurrentLocation;
	FVector DesiredLocation;
	bool bBeginPushed;

public:
	void ScoreUp();

protected:
	//플레이어의 좌우 타깃 위치이동을 조정한다
	void MoveRight();
	void MoveLeft();

	//컴포넌트 콜리전 캡슐에 사용되는 오버랩함수
	UFUNCTION()
	void MyOnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void MyOnComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
