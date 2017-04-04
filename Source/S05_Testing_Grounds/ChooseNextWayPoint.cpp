// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_Testing_Grounds.h"
#include "ChooseNextWayPoint.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UChooseNextWayPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) 
{
	auto blackboardComp = OwnerComp.GetBlackboardComponent();

	auto index = blackboardComp->GetValueAsInt(Index.SelectedKeyName);

	return EBTNodeResult::Type::Succeeded;
}