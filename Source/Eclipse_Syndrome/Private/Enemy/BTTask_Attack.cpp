// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/BTTask_Attack.h"
#include "Enemy/ZombieAIController.h"
#include "Character/PlayerCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Enemy/ZombieEnemy.h"

UBTTask_Attack::UBTTask_Attack()
{
	NodeName = TEXT("Attack Player");
}

EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Get AI controller
	AZombieAIController* AIController = Cast<AZombieAIController>(OwnerComp.GetAIOwner());
	if (!AIController)
	{
		return EBTNodeResult::Failed;
	}

	// Get enemy character
	AZombieEnemy* EnemyCharacter = Cast<AZombieEnemy>(AIController->GetPawn());
	if (!EnemyCharacter)
	{
		return EBTNodeResult::Failed;
	}

	// Get player character from blackboard
	APlayerCharacter* TargetActor = Cast<APlayerCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject("TargetActor"));
	if (!TargetActor)
	{
		return EBTNodeResult::Failed;
	}

	// Attack
	PerformAttack(EnemyCharacter, TargetActor);
	return EBTNodeResult::Succeeded;
}

void UBTTask_Attack::PerformAttack(AActor* EnemyActor, AActor* TargetActor)
{
	if (!EnemyActor || !TargetActor)
	{
		return;
	}

	AZombieEnemy* EnemyCharacter = Cast<AZombieEnemy>(EnemyActor);
	if (!EnemyCharacter)
	{
		return;
	}

	// Calculate distance between enemy and player
	float Distance = FVector::Dist(EnemyActor->GetActorLocation(), TargetActor->GetActorLocation());
	float AttackRange = EnemyCharacter->AttackRange;

	if (Distance <= AttackRange)
	{
		UE_LOG(LogTemp, Warning, TEXT("Enemy Attacks!"));
		// Play attack animation
		//if (EnemyCharacter && EnemyCharacter->GetMesh())
		//{
		//	UAnimInstance* AnimInstance = EnemyCharacter->GetMesh()->GetAnimInstance();
		//	if (AnimInstance)
		//	{
		//		UAnimMontage* AttackMontage = nullptr; // here set attack animation montage
		//		if (AttackMontage)
		//		{
		//			AnimInstance->Montage_Play(AttackMontage);
		//		}
		//	}
		//}

		// Apply damage
		UGameplayStatics::ApplyDamage(TargetActor, EnemyCharacter->Damage, nullptr, EnemyActor, UDamageType::StaticClass());
	}
}
