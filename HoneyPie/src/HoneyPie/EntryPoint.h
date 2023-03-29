#pragma once

#ifdef HP_PLATFORM_WINDOWS

extern Honeypie::Application* Honeypie::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Honeypie::CreateApplication();
	app->Run();
	delete app;
}

#endif // HP_PLATFORM_WINDOWS
