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

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};
}

