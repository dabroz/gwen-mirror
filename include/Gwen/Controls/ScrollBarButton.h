/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once

#include "ScrollBar.h"

namespace Gwen 
{
	namespace ControlsInternal
	{
		class GWEN_EXPORT ScrollBarButton : public Controls::Button
		{
			public:

				GWEN_CONTROL( ScrollBarButton, Controls::Button );

				void Render( Skin::Base* skin );

				void SetDirectionUp();
				void SetDirectionDown();
				void SetDirectionLeft();
				void SetDirectionRight();

			protected:

				int m_iDirection;
		};
	}
}