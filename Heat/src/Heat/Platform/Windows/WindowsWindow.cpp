#include "htpch.h"
#include "WindowsWindow.h"

namespace Heat
{
	//static guaranteed that GLFW only gets initialized once, even with multiple windows
	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* description)
	{
		HT_CORE_ERROR("GLFW Error {0}: {1}", error, description);
	}

	//platform specific implementation for create
	Window* Window::Create(const WindowProps& props) { return new WindowsWindow(props); }

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		HT_CORE_INFO("Creating Window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized)
		{
			int succ = glfwInit();
			HT_CORE_ASSERT(success, "Could not initialize GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);

			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title, nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data); // GLFWwindow will have the data we set here (by void ptr)
		SetVSync(true);

		// GLFW callbacks
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window); //returns m_Data as void pointer
			data.Width  = width;
			data.Height = height;

			// Window resize event callback
		});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			// Window close callback
		});

		//args: key-keyboard key pressed, scancode-system-specific scancode for key; action - GLFW_PRESS GLFW_RELEASE GLFW_REPEAT, mods - held down modifier keys(bit field) 
		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			//TODO: CONVERT TO OUR OWN KEY CODES

			switch (action)
			{
				case GLFW_PRESS:
				{
					HT_INFO("Pressed key {0}", glfwGetKeyName(key, scancode));
					break;
				}
				case GLFW_RELEASE:
				{
					HT_INFO("Released key {0}", glfwGetKeyName(key, scancode));
					break;
				}
				case GLFW_REPEAT:
				{
					HT_INFO("Pressing key {0}", glfwGetKeyName(key, scancode));
					break;
				}
			}
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				
				case GLFW_PRESS:
				{
					HT_INFO("Pressed {0} button", button ? "right" : "left");
					break;
				}
				case GLFW_RELEASE:
				{
					HT_INFO("Reelased {0} button", button ? "right" : "left");
					break;
				}
			}
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			HT_INFO("Mouse scroll offsets ({0},{1})", xOffset, yOffset);

		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			HT_INFO("Mouse at ({0},{1})", xPos, yPos);
		});
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}
}