#include "Weapon/Weapon.h"
#include "Engine/Engine.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

AWeapon::AWeapon()
{
	GunMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GunMesh"));
	RootComponent = GunMesh;

	// �⺻ �� ����
	FireRate = 0.2f;
	MaxAmmo = 30;
	CurrentAmmo = MaxAmmo;
	FireRange = 5000.f;
	Damage = 10.f;
}

void AWeapon::BeginPlay()
{
	Super::BeginPlay();
}

void AWeapon::Fire()
{
    if (CurrentAmmo <= 0)
    {
        return;
    }

    // �ѱ� ��ġ ��������
    FVector MuzzleLocation = GunMesh->GetComponentLocation();
    FRotator MuzzleRotation = GunMesh->GetComponentRotation();

    // Ʈ���̽�
    FHitResult HitResult;
    FVector EndLocation = MuzzleLocation + MuzzleRotation.Vector() * FireRange;  // ��Ÿ� ���� ���

    FCollisionQueryParams Params;
    Params.AddIgnoredActor(this);  // �ѱ� �ڽ��� ����

    if (GetWorld()->LineTraceSingleByChannel(HitResult, MuzzleLocation, EndLocation, ECC_Visibility, Params))
    {
        if (HitResult.GetActor())
        {
            UGameplayStatics::ApplyPointDamage(HitResult.GetActor(), Damage, HitResult.ImpactNormal, HitResult, nullptr, this, nullptr);
        }
    }

    // ź�� ����
    CurrentAmmo--;
}

// ������ ���
void AWeapon::Reload()
{
    CurrentAmmo = MaxAmmo;
}

