#include "VoxelWorld.h"

#include "Components/InstancedStaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

AVoxelWorld::AVoxelWorld()
{
    PrimaryActorTick.bCanEverTick = false;

    Blocks = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("Blocks"));
    SetRootComponent(Blocks);
    Blocks->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    Blocks->SetCollisionResponseToAllChannels(ECR_Block);

    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(
        TEXT("/Engine/BasicShapes/Cube.Cube"));
    if (CubeMesh.Succeeded())
    {
        Blocks->SetStaticMesh(CubeMesh.Object);
    }
}

void AVoxelWorld::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform);
    GenerateWorld();
}

void AVoxelWorld::GenerateWorld()
{
    if (!Blocks || !Blocks->GetStaticMesh())
    {
        return;
    }

    Blocks->ClearInstances();

    const float HalfSize = (WorldSize - 1) * BlockSize * 0.5f;
    for (int32 X = 0; X < WorldSize; ++X)
    {
        for (int32 Y = 0; Y < WorldSize; ++Y)
        {
            for (int32 Z = 0; Z < WorldHeight; ++Z)
            {
                const FVector Location(
                    X * BlockSize - HalfSize,
                    Y * BlockSize - HalfSize,
                    Z * BlockSize);
                Blocks->AddInstance(FTransform(FRotator::ZeroRotator, Location));
            }
        }
    }
}
