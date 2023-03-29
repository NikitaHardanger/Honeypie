#pragma once

#ifdef HP_PLATFORM_WINDOWS

extern Honeypie::Application* Honeypie::CreateApplication();

int main(int argc, char** argv)
{
	Honeypie::Log::Init();
	HP_CORE_WARN("Initialized Log!");
	HP_CORE_INFO("Hello!");
	HP_CORE_ERROR("ERROR!");

	auto app = Honeypie::CreateApplication();
	app->Run();
	delete app;
}

#endif // HP_PLATFORM_WINDOWS
