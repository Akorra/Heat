#include "htpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Heat
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle) : m_WindowHandle(windowHandle)
	{
		HT_CORE_ASSERT(windowHandle, "Window handle is null!");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		HT_CORE_ASSERT(status, "Failed to initialize Glad!");

		HT_CORE_INFO("	Vendor: {0}", glGetString(GL_VENDOR));
		HT_CORE_INFO("	Renderer: {0}", glGetString(GL_RENDERER));
		HT_CORE_INFO("	Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
} 