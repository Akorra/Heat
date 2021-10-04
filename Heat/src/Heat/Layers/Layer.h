#pragma once

#include "Heat/Core.h"
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
		virtual void OnEvent(Event& event) {}

		inline const const char* GetName() const { return m_DebugName; }
	protected:
		const char* m_DebugName;
	};
}
