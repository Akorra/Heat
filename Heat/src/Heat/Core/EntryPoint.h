#pragma once

#ifdef HT_PLATFORM_WINDOWS

extern Heat::Application* Heat::CreateApplication();

int main(int argc, char** argv)
{
	Heat::Log::Init();
	HT_CORE_WARN("Initialized Log!");

	int a = 5;
	HT_INFO("Hello! Var={0}", a);

	auto app = Heat::CreateApplication();
	app->Run();
	delete app;
}

#else
	#error Heat only supports Windows!
#endif