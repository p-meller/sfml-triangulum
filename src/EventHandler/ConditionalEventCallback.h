
//
// Created by Piotr Meller on 04.07.2021.
//

#ifndef TRIANGULUM_CONDITIONALEVENTCALLBACK_H
#define TRIANGULUM_CONDITIONALEVENTCALLBACK_H

#include "EventCallback.h"
#include <functional>
#include <utility>
#include <SFML/Window/Event.hpp>

class ConditionalEventCallback final : public EventCallback
{
	std::function<void(sf::Event)> m_callback;
	std::function<bool(sf::Event)> m_condition;
public:
	explicit ConditionalEventCallback(std::function<void(sf::Event)> callback, std::function<bool(sf::Event)> condition)
			: m_callback(std::move(callback)), m_condition(std::move(condition))
	{

	}

	void doAction(sf::Event event) override
	{
		if (m_condition(event))
		{
			m_callback(event);
		}
	}

};


#endif //TRIANGULUM_CONDITIONALEVENTCALLBACK_H
