#include <Heat.h>

class Sandbox : public Heat::Application
{
public:
	Sandbox() {}
	~Sandbox() {}
};

Heat::Application* Heat::CreateApplication()
{
	return new Sandbox();
}