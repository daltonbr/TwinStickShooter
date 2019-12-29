// DaltonLima 2019 - github.com/daltonbr - daltonlima.com

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS(Blueprintable)
class TWINSTICKSHOOTER_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:

    // Expose a float property: health
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Base Character")
        float Health = 100;

    // Expose a boolean property: bIsDead
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Base Character")
        bool bIsDead = false;

    // Helper function
    virtual void CalculateDead();
    
    // Expose a method (CalculateHealth)
    UFUNCTION(BlueprintCallable, Category = "Base Character")
        virtual void CalculateHealth(const float Delta);

#if WITH_EDITOR
    // Editor code to make updating values in the editor cleaner
    virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
