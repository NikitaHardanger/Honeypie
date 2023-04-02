#include <Honeypie.h>


class Sandbox : public Honeypie::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Honeypie::Application* Honeypie::CreateApplication()
{
	return new Sandbox();
}
