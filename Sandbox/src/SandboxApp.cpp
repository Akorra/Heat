#include <Heat.h>
#include <imgui/imgui.h>
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

	virtual void OnImGuiRender() 
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World!");
		ImGui::End();
	}

	void OnEvent(Heat::Event& event) override
	{
		if (event.GetEventType() == Heat::EventType::KeyPressed)
		{  
			Heat::KeyPressedEvent& e = (Heat::KeyPressedEvent&)event;
			HT_INFO("{0}", (char)e.GetKeyCode());
		}
	}
};

class Sandbox : public Heat::Application
{
public:
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox() {}
};

Heat::Application* Heat::CreateApplication()
{
	return new Sandbox();
}