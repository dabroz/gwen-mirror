/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#include "Base.h"
#include "Gwen/BaseRender.h"
#include "Gwen/Controls/MenuItem.h"
#include "Gwen/Controls/Menu.h"

namespace Gwen 
{
	namespace Controls
	{
		class GWEN_EXPORT MenuStrip : public Menu
		{
			GWEN_CONTROL( MenuStrip, Menu );

				virtual void Render( Skin::Base* skin );
				virtual void RenderUnder( Skin::Base* skin ){}
				virtual void Layout( Skin::Base* skin );

			protected:

				virtual void OnAddItem( MenuItem* item );
				virtual bool ShouldHoverOpenMenu();
				virtual void Close() {}


		};
	}

}
