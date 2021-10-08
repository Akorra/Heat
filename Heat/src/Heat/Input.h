#pragma once

#include "Heat/Core.h"

namespace Heat 
{
	class HEAT_API Input
	{
	public:
		inline static bool IsKeyPressed(int keycode) { return m_Instance->IsKeyPressedImpl(keycode); }
		
		inline static bool  IsMouseButtonPressed(int button)		{ return m_Instance->IsMouseButtonPressedImpl(button); }
		inline static float GetMouseX()								{ return m_Instance->GetMouseXImpl(); }
		inline static float GetMouseY()								{ return m_Instance->GetMouseYImpl(); }
		inline static std::pair<float, float> GetMousePosition()	{ return m_Instance->GetMousePositionImpl(); }

	protected:
		virtual bool IsKeyPressedImpl(int keycode) = 0;

		virtual bool  IsMouseButtonPressedImpl(int button) const = 0;
		virtual float GetMouseXImpl() const = 0; 
		virtual float GetMouseYImpl() const = 0;
		virtual std::pair<float, float> GetMousePositionImpl() const = 0;
		 
	private: 
		static Input* m_Instance;
	};
}