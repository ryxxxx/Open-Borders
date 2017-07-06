#pragma once
#include <memory>
#include <functional>
#include <vector>

namespace ob {
	class Application;
	class BaseSystem;
	template<typename T>
	class System;

	class BaseComponent
	{
	public:
		BaseComponent() {};
		virtual ~BaseComponent() {};

		virtual std::shared_ptr<Application> getApplication() final { return application; };
		virtual void setApplication(Application& app) final { application = std::shared_ptr<Application>(&app); };
	protected:
		std::shared_ptr<Application> application;
	};

	template<typename T>
	class Component : public BaseComponent
	{
	public:
		Component() {
			static_assert(std::is_base_of<Component, T>(), "T has to inherit from Component");
			for(std::shared_ptr<System<T>> &i : systems)
			{
				reinterpret_cast<BaseSystem*>(i.get())->registerComponent(std::shared_ptr<BaseComponent>(this));
			}
		};
		virtual ~Component() {};

		static void registerSystem(std::shared_ptr<System<T>> system) { systems.push_back(system); };
	protected:
		static std::vector<std::shared_ptr<System<T>>> systems;
	};
	template<typename T>
	std::vector<std::shared_ptr<System<T>>> Component<T>::systems;
};