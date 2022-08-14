// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PropertyEditor/Public/IPropertyTypeCustomization.h"

class FDetailWidgetRow;
class IDetailChildrenBuilder;


class ABILITYSELECTOREDITOR_API FAbilitySelectData_Customization : public IPropertyTypeCustomization
{
public:
    static TSharedRef<IPropertyTypeCustomization> MakeInstance();

    // BEGIN IPropertyTypeCustomization interface
    virtual void CustomizeHeader(TSharedRef<IPropertyHandle> struct_property_handle, FDetailWidgetRow& header_row, IPropertyTypeCustomizationUtils& struct_customization_utils) override;
    virtual void CustomizeChildren(TSharedRef<IPropertyHandle> struct_property_handle, IDetailChildrenBuilder& struct_builder, IPropertyTypeCustomizationUtils& struct_customization_utils) override;
    // END IPropertyTypeCustomization interface
};
