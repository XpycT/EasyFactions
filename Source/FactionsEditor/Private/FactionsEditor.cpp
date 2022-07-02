#include "FactionsEditor.h"

DEFINE_LOG_CATEGORY(FactionsEditor);

#define LOCTEXT_NAMESPACE "FFactionsEditor"

void FFactionsEditor::StartupModule()
{
	UE_LOG(FactionsEditor, Warning, TEXT("FactionsEditor module has been loaded"));
}

void FFactionsEditor::ShutdownModule()
{
	UE_LOG(FactionsEditor, Warning, TEXT("FactionsEditor module has been unloaded"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FFactionsEditor, FactionsEditor)