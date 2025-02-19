#pragma once

#include "CoreMinimal.h"
#include "Item/BaseItem.h"
#include "BulletItem.generated.h"


UCLASS()
class ECLIPSE_SYNDROME_API ABulletItem : public ABaseItem
{
	GENERATED_BODY()

public:
	ABulletItem();

	//�Ѿ��� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	float NumOfBullet;

	//mesh��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
	USceneComponent* SceneRootComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	UStaticMeshComponent* StaticMeshComp;


	

	virtual void ActivateItem(AActor* Activator) override;
	
};
