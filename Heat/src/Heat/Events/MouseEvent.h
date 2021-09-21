#pragma once

#include "Event.h"

namespace Heat 
{
	class HEAT_API MouseEvent : public Event
	{
	public:
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	protected:
		// Protected constructor so only derived classes can build it
		MouseEvent() = default;
	};

	class HEAT_API MouseMovedEvent : public MouseEvent
	{
	public:
		MouseMovedEvent(float x, float y) : m_X(x), m_Y(y) {}

		inline float GetX() const { return m_X; }
		inline float GetY() const { return m_Y; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Moved Event: " << m_X << ", " << m_Y;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)

	private:
		float m_X, m_Y;
	};

	class HEAT_API MouseScrolledEvent : public MouseEvent
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset) : m_XOffset(xOffset), m_YOffset(yOffset) {}

		inline float GetX() const { return m_XOffset; }
		inline float GetY() const { return m_YOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Scrolled Event: " << m_XOffset << ", " << m_YOffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)

	private:
		float m_XOffset, m_YOffset;
	};

	class HEAT_API MouseButtonEvent : public MouseEvent
	{
	public:
		inline int GetMouseButton() const { return m_Button; }

	protected:
		MouseButtonEvent(int button) : m_Button(button) {}

		int m_Button;
	};

	class HEAT_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override 
		{
			std::stringstream ss;
			ss << "Mouse Button Pressed Event: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class HEAT_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Button Released Event: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}