#pragma once

#include "Event.h"

namespace Heat 
{
	class HEAT_API ApplicationEvent : public Event
	{
	public:
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	protected:
		// Protected constructor so only derived classes can build it
		ApplicationEvent() = default;
	};

	class HEAT_API WindowResizeEvent : public ApplicationEvent
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height) : m_Width(width), m_Height(height) {}

		inline unsigned int GetWidth()  const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height;  }

		std::string ToString() const override 
		{
			std::stringstream ss;
			ss << "Window Resize Event: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)

	private:
		unsigned int m_Width, m_Height;
	};

	class HEAT_API WindowCloseEvent : public ApplicationEvent
	{
	public:
		WindowCloseEvent() = default;

		EVENT_CLASS_TYPE(WindowClose)
	};
}