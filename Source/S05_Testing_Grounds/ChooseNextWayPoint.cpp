// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_Testing_Grounds.h"
#include "ChooseNextWayPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrollingGuard.h"

EBTNodeResult::Type UChooseNextWayPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) 
{
	auto AIController = OwnerComp.GetAIOwner();

	auto controlledPawn = AIController->GetPawn();

	auto patrollingGuard = Cast<APatrollingGuard>(controlledPawn);

	auto patrollingPoints = patrollingGuard->PatrollingPointsCPP;

	auto blackboardComp = OwnerComp.GetBlackboardComponent();

	auto index = blackboardComp->GetValueAsInt(Index.SelectedKeyName);

	blackboardComp->SetValueAsObject(WayPoint.SelectedKeyName, patrollingPoints[index]);

	auto nextIndex = (index + 1) % patrollingPoints.Num();

	blackboardComp->SetValueAsInt(Index.SelectedKeyName, nextIndex);

	return EBTNodeResult::Type::Succeeded;
}