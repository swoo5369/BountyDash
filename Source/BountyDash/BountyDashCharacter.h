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
	//�̵����� �迭
	UPROPERTY(EditAnyWhere, Category = Logic)
	TArray<class ATargetPoint*> TargetArray;

	//ĳ���� �� �ٲ� �ӵ�
	UPROPERTY(EditAnyWhere, Category = Logic)
	float CharSpeed;

	//�浹���带 ���� ����� ������Ʈ
	UPROPERTY(EditAnyWhere, Category = sound)
	UAudioComponent* hitObstacleSound;

	//���� ȹ�� ���带 ���� ����� ������Ʈ
	UPROPERTY(EditAnyWhere, Category = Sound)
	UAudioComponent* dingSound;

protected:
	//�÷��̾�� ī�޶� ���� �Ÿ��� �����ϱ����� ī�޶� ��
	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = Camera)
		class USpringArmComponent* CameraBoom;

	//Ÿ�� ��� ����� ī�޶�
	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = Camera)
	class UCameraComponent* FollowCamera;

	//�÷��̾�����
	UPROPERTY(BlueprintReadOnly)
	int32 Score;

private:
	//ĳ���� �� ��ġ ������
	short CurrentLocation;
	FVector DesiredLocation;
	bool bBeginPushed;

public:
	void ScoreUp();

protected:
	//�÷��̾��� �¿� Ÿ�� ��ġ�̵��� �����Ѵ�
	void MoveRight();
	void MoveLeft();

	//������Ʈ �ݸ��� ĸ���� ���Ǵ� �������Լ�
	UFUNCTION()
	void MyOnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void MyOnComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};