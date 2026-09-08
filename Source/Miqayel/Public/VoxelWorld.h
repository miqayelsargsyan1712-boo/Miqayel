#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VoxelWorld.generated.h"

class UInstancedStaticMeshComponent;

UCLASS()
class MIQAYEL_API AVoxelWorld : public AActor
{
    GENERATED_BODY()

public:
    AVoxelWorld();

protected:
    virtual void OnConstruction(const FTransform& Transform) override;

private:
    void GenerateWorld();

    UPROPERTY(VisibleAnywhere)
    TObjectPtr<UInstancedStaticMeshComponent> Blocks;

    UPROPERTY(EditAnywhere, Category = "Voxel World", meta = (ClampMin = "1", ClampMax = "64"))
    int32 WorldSize = 16;

    UPROPERTY(EditAnywhere, Category = "Voxel World", meta = (ClampMin = "1", ClampMax = "16"))
    int32 WorldHeight = 4;

    UPROPERTY(EditAnywhere, Category = "Voxel World", meta = (ClampMin = "10.0", ClampMax = "500.0"))
    float BlockSize = 100.0f;
};
