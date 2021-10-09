#pragma once

#include "Heat/Core/Input.h"

namespace Heat {
	class WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;

		bool IsMouseButtonPressedImpl(int button) const override;
		float GetMouseXImpl() const override;
		float GetMouseYImpl() const override;
		std::pair<float, float> GetMousePositionImpl() const override;
	};
}

