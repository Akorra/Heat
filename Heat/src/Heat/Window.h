#pragma once

#include "htpch.h"

#include "Heat/Core.h"
#include "Heat/Events/Event.h"

namespace Heat {
	struct WindowProps
	{
		const char*  Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const char* title = "Heat::Engine",
					unsigned int width = 1280,
					unsigned int height = 720)
			: Title(title), Width(width), Height(height)
		{}
	};

	// Desktop System based window interface
	class HEAT_API Window 
	{
	public:
		using EventCallbackFunction = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		//Window attributes
		virtual void SetEventCallback(const EventCallbackFunction& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		//Platform Dependent
		static Window* Create(const WindowProps& props = WindowProps());
	};
}