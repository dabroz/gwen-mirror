/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_CONTROLS_PROPERTY_TEXT_H
#define GWEN_CONTROLS_PROPERTY_TEXT_H

#include "Gwen/Controls/Property/BaseProperty.h"
#include "Gwen/Controls/TextBox.h"

namespace Gwen 
{
	namespace Controls
	{
		namespace Property
		{
			class GWEN_EXPORT Text : public Property::Base
			{
				public:

					GWEN_CONTROL_INLINE( Text, Property::Base )
					{
						m_TextBox = new TextBox( this );
						m_TextBox->Dock( Pos::Fill );
						m_TextBox->SetShouldDrawBackground( false );
						m_TextBox->onTextChanged.Add( this, &BaseClass::OnPropertyValueChanged );
					}

					virtual UnicodeString GetPropertyValue()
					{
						return m_TextBox->GetText();
					}

					virtual void SetPropertyValue( const TextObject& v, bool bFireChangeEvents )
					{
						m_TextBox->SetText( v, bFireChangeEvents );
					}

					virtual bool IsEditing()
					{
						return m_TextBox->HasFocus();
					}

					virtual bool IsHovered()
					{
						return BaseClass::IsHovered() || m_TextBox->IsHovered();
					}

					TextBox* m_TextBox;
			};
		}
	}
}
#endif
