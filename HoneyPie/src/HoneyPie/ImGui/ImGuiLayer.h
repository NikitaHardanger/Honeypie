#pragma once

#include "HoneyPie/Layer.h"

namespace Honeypie {

	class HONEYPIE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);

	protected:
		float m_Time = 0.0f;
	};
}