/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#include "Base.h"
#include "Gwen/BaseRender.h"

namespace Gwen 
{
	namespace ControlsInternal
	{
		class GWEN_EXPORT Highlight : public Controls::Base
		{
			public:

				GWEN_CONTROL_INLINE( Highlight, Controls::Base )
				{

				}

				void Render( Skin::Base* skin )
				{
					skin->DrawHighlight( this );
				}
		};
	}

}
