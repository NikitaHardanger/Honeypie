#pragma once

#include "HoneyPie/Window.h"

#include <GLFW/glfw3.h>

namespace Honeypie {

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override {
			return m_Data.Width;
		}
		inline unsigned int GetHeight() const override {
			return m_Data.Height;
		}
		inline void SetEventCallback(const EventCallbackFunc& callback) override {
			m_Data.EventCallback = callback;
		}
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;
	private:
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width;
			unsigned int Height;
			bool VSync;

			EventCallbackFunc EventCallback;
		};

		WindowData m_Data;

		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	};
}