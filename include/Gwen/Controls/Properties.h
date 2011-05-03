/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once

#include "Gwen/Controls/Base.h"
#include "Gwen/Controls/Label.h"
#include "Gwen/Gwen.h"
#include "Gwen/Skin.h"
#include "Gwen/Controls/SplitterBar.h"
#include "Gwen/Controls/Property/Text.h"


namespace Gwen 
{
	namespace Controls
	{

		class PropertyRow;

		class GWEN_EXPORT Properties : public Base
		{
			public:

				GWEN_CONTROL( Properties, Base );

				virtual void PostLayout( Gwen::Skin::Base* skin );

				PropertyRow* Add( const UnicodeString& text, const UnicodeString& value = L"" );
				PropertyRow* Add( const String& text, const String& value = "" );
				PropertyRow* Add( const UnicodeString& text, Property::Base* pProp );
				PropertyRow* Add( const String& text, Property::Base* pProp );

				virtual int GetSplitWidth();

				virtual void Clear();

			protected:

				virtual void OnSplitterMoved( Controls::Base * control );

				Controls::SplitterBar*	m_SplitterBar;

		};

		class GWEN_EXPORT PropertyRow : public Base
		{
			public:

				GWEN_CONTROL( PropertyRow, Base );

				virtual Label* GetLabel(){ return m_Label; }
				virtual void SetProperty( Property::Base* prop );
				virtual Property::Base* GetProperty(){ return m_Property; }

				virtual void Layout( Gwen::Skin::Base* skin );
				virtual void Render( Gwen::Skin::Base* skin );

				Event::Caller	onChange;

			protected:

				void OnPropertyValueChanged( Gwen::Controls::Base* control );

				Label*		m_Label;
				Property::Base*	m_Property;

		};
	}
}