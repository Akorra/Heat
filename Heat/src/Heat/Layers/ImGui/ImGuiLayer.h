#pragma once

#include "Heat/Layers/Layer.h"

#include "Heat/Events/ApplicationEvent.h"
#include "Heat/Events/MouseEvent.h"
#include "Heat/Events/KeyEvent.h"

namespace Heat {
	class HEAT_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& event) override;

	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);

		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);

		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);

		bool OnWindowResizeEvent(WindowResizeEvent& e);
		bool OnWindowFocusEvent(WindowFocusEvent& e);
	
	private:
		float m_Time = 0.0f;
	};
}

