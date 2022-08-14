#include "AbilitySelectorEditor.h"

// Engine includes
#include "Modules/ModuleManager.h"
#include "PropertyEditor/Public/PropertyEditorModule.h"

// Editor includes
#include "Customization/AbilitySelectData_Customization.h"

// Game includes
#include "DA_AbilityData.h"

#define LOCTEXT_NAMESPACE "FAbilitySelectorEditorModule"

void FAbilitySelectorEditorModule::StartupModule()
{
	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");

	// FAbilitySelectData
	PropertyModule.RegisterCustomPropertyTypeLayout(
		FAbilitySelectData::StaticStruct()->GetFName(),
		FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FAbilitySelectData_Customization::MakeInstance)
	);
}

void FAbilitySelectorEditorModule::ShutdownModule()
{
	if (FModuleManager::Get().IsModuleLoaded("PropertyEditor"))
	{
		// unregister properties when the module is shutdown
		FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
		PropertyModule.UnregisterCustomPropertyTypeLayout(FAbilitySelectData::StaticStruct()->GetFName());

		PropertyModule.NotifyCustomizationModuleChanged();
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FAbilitySelectorEditorModule, AbilitySelectorEditor)