// Copyright Epic Games, Inc. All Rights Reserved.

#include "FactionsRuntime.h"
#include "GameDelegates.h"
#include "FactionsSettings.h"

DEFINE_LOG_CATEGORY(FactionsRuntime)

#define LOCTEXT_NAMESPACE "FactionsRuntime"

void FFactionsRuntime::StartupModule()
{
	UE_LOG(FactionsRuntime, Warning, TEXT("FactionsRuntime module has been loaded"));

	RegisterSettings();

	CacheFactionInformation();

	OnEndPlayHandle = FGameDelegates::Get().GetEndPlayMapDelegate().AddRaw(this, &FFactionsRuntime::OnEndPlay);
}

void FFactionsRuntime::ShutdownModule()
{
	UE_LOG(FactionsRuntime, Warning, TEXT("FactionsRuntime module has been unloaded"));

	FGameDelegates::Get().GetEndPlayMapDelegate().Remove(OnEndPlayHandle);

	if (UObjectInitialized())
	{
		UnregisterSettings();

		// Destroy faction Info
		if (FactionManager.IsValid())
		{
			FactionManager->RemoveFromRoot();
			FactionManager->MarkAsGarbage();
		}
	}
}

void FFactionsRuntime::RegisterSettings()
{
#if WITH_EDITOR
	// Registering some settings is just a matter of exposing the default UObject of
	// your desired class, feel free to add here all those settings you want to expose
	// to your LDs or artists.

	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		// Get Project Settings category
		ISettingsContainerPtr SettingsContainer = SettingsModule->GetContainer("Project");

		// Register Factions settings
		const ISettingsSectionPtr SettingsSection = SettingsModule->RegisterSettings("Project", "Game", "Factions",
		                                                                             LOCTEXT("RuntimeFactionsSettingsName", "Factions"),
		                                                                             LOCTEXT("RuntimeFactionsDescription", "Factions database and relations table"),
		                                                                             GetMutableDefault<UFactionsSettings>());

		// Register the save handler to your settings, you might want to use it to
		// validate those or just act to settings changes.
		if (SettingsSection.IsValid())
		{
			SettingsSection->OnModified().BindRaw(this, &FFactionsRuntime::HandleSettingsSaved);
		}
	}
#endif
}

void FFactionsRuntime::UnregisterSettings() const
{
#if WITH_EDITOR
	// Ensure to unregister all of your registered settings here, hot-reload would
	// otherwise yield unexpected results.

	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Project", "Game", "Factions");
	}
#endif
}

bool FFactionsRuntime::HandleSettingsSaved() const
{
	UFactionsSettings* Settings = GetMutableDefault<UFactionsSettings>();
	bool ResaveSettings = false;

	if (ModifiedSettingsDelegate.IsBound()) {
		ModifiedSettingsDelegate.Execute();
	}

	// You can put any validation code in here and resave the settings in case an invalid
	// value has been entered

	if (ResaveSettings)
	{
		Settings->SaveConfig();
	}

	CacheFactionInformation();
	return true;
}

void FFactionsRuntime::CacheFactionInformation() const
{
	// Destroy previous Info
	if (FactionManager.IsValid())
	{
		FactionManager->RemoveFromRoot();
		FactionManager->MarkAsGarbage();
	}

	// Create new infos from settings, and don't allow GC destruction
	FactionManager = NewObject<UFactionsSettings>();
	FactionManager->AddToRoot();
}

TWeakObjectPtr<class UFactionsSettings> FFactionsRuntime::FactionManager {};

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FFactionsRuntime, FactionsRuntime)
