#pragma once

#include "Core.h"

#include "Window.h"
#include "Events/Event.h"
#include "HoneyPie/Events/ApplicationEvent.h"
#include "HoneyPie/LayerStack.h"

namespace Honeypie {

	class HONEYPIE_API Application
	{

	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:

		bool OnWindowCLose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;
	};

	// To be defined in Client
	Application* CreateApplication();
	 
}
