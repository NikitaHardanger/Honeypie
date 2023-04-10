#include "HP_pch.h"

#include "Application.h"
#include "HoneyPie/Log.h"

#include <GLFW/glfw3.h>

namespace Honeypie {

	// This macro is used to bind member functions of the Application class to event callbacks.
#define BIND_EVENT_FUNC(x) std::bind(&Application::x, this, std::placeholders::_1)
	
	// Constructor for the Application class, which creates a Window object and sets its event callback to OnEvent().
	Application::Application() 
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FUNC(OnEvent));
	}

	Application::~Application() 
	{

	}

	// This function is the event callback for the Window object created in the constructor. 
	// It dispatches events to the appropriate member function using EventDispatcher.
	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FUNC(OnWindowCLose));

		// Outputs a trace log message containing the event's details.
		HP_CORE_TRACE("{0}", e);
	}

	// This function runs the main loop for the application.
	void Application::Run()
	{
		while (m_Running)
		{
			// Clears the color buffer and updates the window.
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

	// This function is called when the WindowCloseEvent is dispatched. 
	// It sets the running flag to false to exit the main loop.
	bool Application::OnWindowCLose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
	
}