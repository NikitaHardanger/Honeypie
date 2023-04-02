#include "HP_pch.h"

#include "Application.h"
#include "HoneyPie/Events/ApplicationEvent.h"
#include "HoneyPie/Log.h"

namespace Honeypie {

	
	Application::Application() 
	{

	}

	Application::~Application() 
	{

	}

	void Application::Run()
	{
		WindowResizeEvent event(1600, 900);
		
		HP_TRACE(event);
		while (true);
	}
	
}