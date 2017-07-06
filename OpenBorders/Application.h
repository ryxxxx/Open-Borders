#pragma once
#include <map>
#include <typeindex>
#include <typeinfo>
#include <memory>
#include <exception>
#include "Component.h"

namespace ob {
	class Application
	{
	public:
		Application() {};
		virtual ~Application() {};
		
		template<typename T>
		std::shared_ptr<T> getComponent() {
			return components[typeid(T)];
		};

		template<typename T>
		void addComponent(std::shared_ptr<T> component) {
			static_assert(std::is_base_of<BaseComponent, T>(), "T has to inherit from Component");
			if (components.count(typeid(T)) != 0)
			{
				throw std::exception("Component-Type already added!");
			}
			else
			{
				components[typeid(T)] = component;
				component->setApplication(*this);
			}
		};
	protected:
		std::map<std::type_index, std::shared_ptr<BaseComponent>> components;
	};
};