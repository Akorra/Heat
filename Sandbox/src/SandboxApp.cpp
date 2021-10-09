#include <Heat.h>

class ExampleLayer : public Heat::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{}

	void OnUpdate() override
	{
		if (Heat::Input::IsKeyPressed(HT_KEY_TAB))
			HT_INFO("Tab key is pressed!");
	}

	void OnEvent(Heat::Event& event) override
	{
		//HT_TRACE("{0}", event);
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