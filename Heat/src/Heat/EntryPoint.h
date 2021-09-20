#pragma once

#ifdef HT_PLATFORM_WINDOWS

extern Heat::Application* Heat::CreateApplication();

int main(int argc, char** argv)
{
	printf("Heat Engine\n");
	auto app = Heat::CreateApplication();
	app->Run();
	delete app;
}

#else
	#error Heat only supports Windows!
#endif