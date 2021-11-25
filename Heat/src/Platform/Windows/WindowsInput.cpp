#include "htpch.h"
#include "WindowsInput.h"

#include "Heat/Core/Application.h"

#include <GLFW/glfw3.h>

namespace Heat 
{
	Input* Input::m_Instance = new WindowsInput(); //since it is static 

	bool WindowsInput::IsKeyPressedImpl(int keycode)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state  = glfwGetKey(window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool WindowsInput::IsMouseButtonPressedImpl(int button) const
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state  = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}

	float WindowsInput::GetMouseXImpl() const
	{
		auto [x, y] = GetMousePositionImpl();
		return x;
	}

	float WindowsInput::GetMouseYImpl() const
	{
		auto[x, y] = GetMousePositionImpl();
		return y;
	}

	std::pair<float, float> WindowsInput::GetMousePositionImpl() const
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
	
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		return { (float)xpos, (float)ypos };
	} 
}
