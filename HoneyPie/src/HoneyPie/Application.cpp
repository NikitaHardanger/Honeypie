#include "HP_pch.h"

#include "Application.h"
#include "HoneyPie/Events/ApplicationEvent.h"
#include "HoneyPie/Log.h"

#include <GLFW/glfw3.h>

namespace Honeypie {

	
	Application::Application() 
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application() 
	{

	}

	void Application::Run()
	{
		while (m_Running)
		{
			
			m_Window->OnUpdate();
		}
	}
	
}