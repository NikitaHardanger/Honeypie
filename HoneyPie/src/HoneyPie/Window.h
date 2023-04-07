#pragma once

#include "HP_pch.h"

#include "HoneyPie/Core.h"
#include "HoneyPie/Events/Event.h"

namespace Honeypie {

	struct WindowProps
	{
		unsigned int Width;
		unsigned int Height;
		std::string Title;

		WindowProps(unsigned int width = 1280,
			unsigned int height = 720,
			const std::string& title = "HoneyPie Engine")
			: Width(width), Height(height), Title(title)
		{
		}
	};

	// Interface a desktop system based Window
	class HONEYPIE_API Window
	{
	public:
		using EventCallbackFunc = std::function<void(Event&)>;

		virtual ~Window() {}
		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFunc& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}