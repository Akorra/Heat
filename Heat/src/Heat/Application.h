#pragma once

#include "Heat/Core.h"
#include "Heat/Events/Event.h"
#include "Heat/Events/ApplicationEvent.h"

#include "Heat/Window.h"

namespace Heat {
	class HEAT_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& event);

	private:
		bool OnWindowClose(WindowCloseEvent& event);

		bool m_Running = true;
		std::unique_ptr<Window> m_Window;
	};

	//To be defined in client
	Application* CreateApplication();
}

