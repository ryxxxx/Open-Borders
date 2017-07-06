#pragma once
#include <vector>
#include <memory>
#include <type_traits>
#include "Component.h"

namespace ob {
	class BaseSystem
	{
	public:
		BaseSystem() {};
		virtual ~BaseSystem() {};


		virtual void update() = 0;
		virtual void registerComponent(std::shared_ptr<BaseComponent> component) final { components.push_back(component); };
	protected:
		std::vector<std::shared_ptr<BaseComponent>> components;
	};

	template<typename T>
	class System : public BaseSystem
	{
	public:
		System() { 
			static_assert(std::is_base_of<BaseComponent, T>(), "T has to inherit from Component");
			T* temp = new T;
			reinterpret_cast<Component<T>*>(temp)->registerSystem(std::shared_ptr<System<T>>(this));
			delete temp;
		};
		virtual ~System() {};
	};
};