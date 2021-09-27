#pragma once

#include "htpch.h"
#include "Heat/Core.h"

//TODO: Add Event support, with a callback function

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
		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		//Window attributes
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		//Platform Dependent
		static Window* Create(const WindowProps& props = WindowProps());
	};
}