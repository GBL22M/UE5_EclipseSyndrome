#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ItemInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UItemInterface : public UInterface
{
	GENERATED_BODY()
};


class ECLIPSE_SYNDROME_API IItemInterface
{
	GENERATED_BODY()

public:
	//ActivateItem : �������� Ŭ������ ��
	virtual void ActivateItem(AActor* Activator) = 0;
	//GetItemType : �������� ���� ��ȯ
	virtual FName GetItemType() const = 0;
};
