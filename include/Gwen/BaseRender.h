/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once

#include "Gwen/Structures.h"

namespace Gwen 
{
	struct Font;
	struct Texture;
	
	namespace Renderer
	{
		class Base;

		class ICacheToTexture
		{

		public:
			virtual void Initialize() = 0;
			virtual void ShutDown() = 0;
			virtual void SetupCacheTexture( Gwen::Controls::Base* control ) = 0;
			virtual void FinishCacheTexture( Gwen::Controls::Base* control ) = 0;
			virtual void DrawCachedControlTexture( Gwen::Controls::Base* control ) = 0;
			virtual void CreateControlCacheTexture( Gwen::Controls::Base* control ) = 0;
			virtual void UpdateControlCacheTexture( Gwen::Controls::Base* control ) = 0;
			virtual void SetRenderer( Gwen::Renderer::Base* renderer ) = 0;

		};

		class GWEN_EXPORT Base
		{
			public:

				Base();
				virtual ~Base();

				virtual void Begin() = 0;
				virtual void End() = 0;

				virtual void SetDrawColor( Color color ) = 0;

				virtual void DrawLine( int x, int y, int a, int b ) = 0;
				virtual void DrawFilledRect( Rect rect ) = 0;

				virtual void StartClip() = 0;
				virtual void EndClip() = 0;

				virtual void LoadTexture( Gwen::Texture* pTexture ) = 0;
				virtual void FreeTexture( Gwen::Texture* pTexture ) = 0;
				virtual void DrawTexturedRect( Gwen::Texture* pTexture, Gwen::Rect pTargetRect, float u1=0.0f, float v1=0.0f, float u2=1.0f, float v2=1.0f ) = 0;
				virtual void DrawMissingImage( Gwen::Rect pTargetRect );

				virtual ICacheToTexture* GetCTT() { return NULL; }

				virtual void LoadFont( Gwen::Font* pFont ) = 0;
				virtual void FreeFont( Gwen::Font* pFont ) = 0;
				virtual void RenderText( Gwen::Font* pFont, Gwen::Point pos, const Gwen::UnicodeString& text ) = 0;
				virtual Gwen::Point MeasureText( Gwen::Font* pFont, const Gwen::UnicodeString& text ) = 0;

				//
				// No need to implement these functions in your derived class, but if 
				// you can do them faster than the default implementation it's a good idea to.
				//
				virtual void DrawLinedRect( Rect rect );
				virtual void DrawPixel( int x, int y );
				virtual void DrawShavedCornerRect( Rect rect, bool bSlight = false );
				virtual Gwen::Point MeasureText( Gwen::Font* pFont, const Gwen::String& text );
				virtual void RenderText( Gwen::Font* pFont, Gwen::Point pos, const Gwen::String& text );

			public:

				//
				// Translate a panel's local drawing coordinate
				//  into view space, taking Offset's into account.
				//
				void Translate( int& x, int& y );
				void Translate( Gwen::Rect& rect );

				//
				// Set the rendering offset. You shouldn't have to 
				// touch these, ever.
				//
				void SetRenderOffset( const Point& offset ){ m_RenderOffset = offset; }
				void AddRenderOffset( const Rect& offset ){ m_RenderOffset.x += offset.x; m_RenderOffset.y += offset.y; }
				const Point& GetRenderOffset() const { return m_RenderOffset; }

			private:

				Point m_RenderOffset;

			public:

				void SetClipRegion( Rect rect );
				void AddClipRegion( Rect rect );
				bool ClipRegionVisible();
				const Gwen::Rect& ClipRegion() const;

			private:

				Rect m_rectClipRegion;
				ICacheToTexture* m_RTT;

			public:
				
				void SetScale( float fScale ){ m_fScale = fScale; }
				float Scale() const { return m_fScale; }

				float m_fScale;
		};
	}
}