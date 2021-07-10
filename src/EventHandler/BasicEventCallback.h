//
// Created by Piotr Meller on 20.06.2021.
//

#ifndef TRIANGULUM_BASICEVENTCALLBACK_H
#define TRIANGULUM_BASICEVENTCALLBACK_H

#include "EventCallback.h"
#include <functional>
#include <utility>
#include <SFML/Window/Event.hpp>

class BasicEventCallback final : public EventCallback
{
	std::function<void(sf::Event)> m_callback;

public:
	explicit BasicEventCallback(std::function<void(sf::Event)> callback) : m_callback(std::move(callback))
	{
	}

	void doAction(sf::Event event) override
	{
		m_callback(event);
	}

};

#endif //TRIANGULUM_BASICEVENTCALLBACK_H
