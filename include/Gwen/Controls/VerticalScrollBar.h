/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once

#include "Gwen/Controls/Base.h"
#include "Gwen/Controls/Button.h"
#include "Gwen/Gwen.h"
#include "Gwen/Skin.h"
#include "Gwen/Controls/Dragger.h"
#include "Gwen/Controls/ScrollBar.h"

namespace Gwen 
{
	namespace Controls
	{

		class GWEN_EXPORT VerticalScrollBar : public BaseScrollBar
		{
		
			GWEN_CONTROL( VerticalScrollBar, BaseScrollBar );

			virtual void Layout(Skin::Base* skin);

			virtual void OnMouseClickLeft( int x, int y, bool bDown );
			virtual void OnBarMoved( Controls::Base* control );

			virtual int GetBarSize() { return  m_Bar->Height(); }
			virtual int GetBarPos() { return m_Bar->Y() - Width(); }
			virtual void SetBarSize( int size ) { m_Bar->SetHeight( size ); }
			virtual int GetButtonSize() { return Width(); }

			virtual void ScrollToTop();
			virtual void ScrollToBottom();
			virtual void NudgeUp( Base* control );
			virtual void NudgeDown( Base* control );
			virtual float GetNudgeAmount();

			virtual float CalculateScrolledAmount();
			void SetScrolledAmount(float amount, bool forceUpdate);

		};
	}
}