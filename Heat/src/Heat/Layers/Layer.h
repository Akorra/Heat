#pragma once

#include "Heat/Core/Base.h"
#include "Heat/Events/Event.h"

namespace Heat
{
	class HEAT_API Layer
	{
	public:
		Layer(const char* name = "Layer") : m_DebugName(name) {}
		virtual ~Layer() {}

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		inline const char* GetName() const { return m_DebugName; }
	protected:
		const char* m_DebugName;
	};
}
