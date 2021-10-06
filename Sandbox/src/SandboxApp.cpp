#include <Heat.h>

class ExampleLayer : public Heat::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{}

	void OnUpdate() override
	{
		HT_INFO("Example Layer Update");
	}

	void OnEvent(Heat::Event& event) override
	{
		HT_TRACE("{0}", event);
	}
};

class Sandbox : public Heat::Application
{
public:
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Heat::ImGuiLayer());
	}

	~Sandbox() {}
};

Heat::Application* Heat::CreateApplication()
{
	return new Sandbox();
}