// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

#if WITH_EDITOR
#include "ISettingsModule.h"
#include "ISettingsSection.h"
#include "ISettingsContainer.h"
#endif //WITH_EDITOR

DECLARE_LOG_CATEGORY_EXTERN(FactionsRuntime, All, All);

class FFactionsRuntime : public IModuleInterface
{
public:

	FORCEINLINE static FFactionsRuntime& Get() {
		return FModuleManager::LoadModuleChecked<FFactionsRuntime>("FactionsRuntime");
	}

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	virtual bool SupportsDynamicReloading() override { return true; }

	DECLARE_DELEGATE_RetVal(void, FOnModifiedSettings)
	FOnModifiedSettings& OnModifiedSettings()
	{
		return ModifiedSettingsDelegate;
	}

private:

	FDelegateHandle OnEndPlayHandle;

	void OnEndPlay() const
	{
		CacheFactionInformation();
	}
	
	/** Holds a delegate that is executed after the settings section has been modified. */
	FOnModifiedSettings ModifiedSettingsDelegate;

	void RegisterSettings();
	void UnregisterSettings() const;

	// Callbacks for when the settings were saved.
	bool HandleSettingsSaved() const;

	void CacheFactionInformation() const;

	static TWeakObjectPtr<class UFactionsSettings> FactionManager;

public:

	static UFactionsSettings* GetFactionManager() {
		return FactionManager.Get();
	}
};
