#pragma once

#include "Event.h"

namespace Heat
{
	class HEAT_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	protected:
		// Protected constructor so only derived classes can build it
		KeyEvent(int keycode) : m_KeyCode(keycode) {}

		int m_KeyCode;
	};

	class HEAT_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount) :
			KeyEvent(keycode), m_RepeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override 
		{
			std::stringstream ss;
			ss << "KeyPressEvent: " << " (" << m_RepeatCount << "repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		int m_RepeatCount;
	};
}