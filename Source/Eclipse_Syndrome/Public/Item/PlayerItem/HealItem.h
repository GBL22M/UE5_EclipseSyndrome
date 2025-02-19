#pragma once

#include "CoreMinimal.h"
#include "Item/BaseItem.h"
#include "HealItem.generated.h"


UCLASS()
class ECLIPSE_SYNDROME_API AHealItem : public ABaseItem
{
	GENERATED_BODY()

public:
	AHealItem();

	//�� ������ ����, �� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	float HealAmount;

	//mesh��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	USceneComponent* SceneRootComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	UStaticMeshComponent* StaticMeshComp;



	virtual void ActivateItem(AActor* Activator) override;
};
