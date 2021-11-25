#pragma once

#include "Heat/Core/Base.h"
#include "Heat/Core/Window.h"
#include "Heat/Layers/LayerStack.h"
#include "Heat/Events/Event.h"
#include "Heat/Events/ApplicationEvent.h"

#include "Heat/Layers/ImGui/ImGuiLayer.h"

namespace Heat {
	class HEAT_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& event);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *m_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& event);

		LayerStack m_LayerStack;

		bool m_Running = true;
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;			//imgui layers automatically added by Heat's runtime
		
		unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;

	private:
		static Application* m_Instance;
	};

	//To be defined in client
	Application* CreateApplication();
}

