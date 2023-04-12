#include <Honeypie.h>

class ExampleLayer : public Honeypie::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		HP_INFO("ExampleLayer::Update");
	}

	void OnEvent(Honeypie::Event& event) override
	{
		HP_TRACE("{0}", event);
	}
};


class Sandbox : public Honeypie::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Honeypie::Application* Honeypie::CreateApplication()
{
	return new Sandbox();
}

