#pragma once

#include "CoreMinimal.h"

class FClashRoyaleRTSModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
