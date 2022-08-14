#include "Customization/AbilitySelectData_Customization.h"

#include "DetailLayoutBuilder.h"
#include "DetailWidgetRow.h"
#include "PropertyHandle.h"
#include "IDetailChildrenBuilder.h"

// Game includes
#include "DA_AbilityData.h"

#define LOCTEXT_NAMESPACE "FAbilitySelectorEditorModule"


TSharedRef<IPropertyTypeCustomization> FAbilitySelectData_Customization::MakeInstance()
{
    // Create the instance and returned a SharedRef
    return MakeShareable(new FAbilitySelectData_Customization());
}

void FAbilitySelectData_Customization::CustomizeHeader(TSharedRef<IPropertyHandle> struct_property_handle, FDetailWidgetRow& header_row, IPropertyTypeCustomizationUtils& struct_customization_utils)
{
    // Get the property handler of the type property:
    TSharedPtr<IPropertyHandle> ability_property = struct_property_handle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FAbilitySelectData, m_gameplay_ability));
    
    check(ability_property.IsValid());
    
    header_row
        .WholeRowContent()[
            SNew(SHorizontalBox)
                + SHorizontalBox::Slot()
                .HAlign(HAlign_Fill)
                .VAlign(VAlign_Center)
                
                [
                    ability_property->CreatePropertyValueWidget(true)
                ]
            + SHorizontalBox::Slot()
                .HAlign(HAlign_Right)
                .VAlign(VAlign_Center)
                .AutoWidth()
                [
                    struct_property_handle->CreateDefaultPropertyButtonWidgets()
                ]
        ];
}

void FAbilitySelectData_Customization::CustomizeChildren(TSharedRef<IPropertyHandle> struct_property_handle, IDetailChildrenBuilder& struct_builder, IPropertyTypeCustomizationUtils& struct_customization_utils)
{
    TSharedPtr<IPropertyHandle> ability_property = struct_property_handle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FAbilitySelectData, m_gameplay_ability));
    
    FString ability_property_name = ability_property->GetPropertyDisplayName().ToString();
    
    uint32 num_childern = 0;
    if (struct_property_handle->GetNumChildren(num_childern) == FPropertyAccess::Success)
    {
        for (uint32 i = 0; i < num_childern; ++i)
        {
            // Dont show the ability since its been shown in header.
            TSharedPtr<IPropertyHandle> child = struct_property_handle->GetChildHandle(i);
            if (child->GetPropertyDisplayName().ToString() != ability_property_name)
            {
                struct_builder.AddProperty(child.ToSharedRef());
            }
        }
    }
}


#undef LOCTEXT_NAMESPACE
