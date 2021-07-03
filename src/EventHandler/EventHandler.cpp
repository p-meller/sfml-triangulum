//
// Created by Piotr Meller on 06.06.2021.
//

#include "EventHandler.h"

#include <utility>
#include <SFML/Graphics/RenderWindow.hpp>

#include "BasicEventCallback.h"

EventHandler::EventHandler(sf::RenderWindow& window) : m_window(window)
{

}

void EventHandler::handleEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		auto it = eventRegister.find(event.type);
		if (it != eventRegister.end())
		{
			for (auto&&[k, actionPtr] : it->second)
			{
				(*actionPtr).doAction(event);
			}
//			for (auto&&[k, conditionalCallback] : it->second)
//			{
//				if(conditionalCallback.first(event))
//				{
//					(*(conditionalCallback.second)).doAction(event);
//				}
//			}
		}
	}
}

void EventHandler::addEventCallback(sf::Event::EventType eventType, const std::string& eventName,
		std::function<void(sf::Event)> eventCallback)
{
	addEventCallback(eventType, eventName,
			std::make_unique<BasicEventCallback>(BasicEventCallback(std::move(eventCallback))));
}

void EventHandler::addEventCallback(sf::Event::EventType eventType, const std::string& eventName,
		std::unique_ptr<EventCallback> eventCallback)
{
	auto it = eventRegister.find(eventType);

	if (it == eventRegister.end())
	{
		it = eventRegister.insert({ eventType, CallbackRegisterType() }).first;
	}
	it->second.insert({ eventName, std::move(eventCallback) });
}

void
EventHandler::addKeyPressesEventCallback(sf::Keyboard::Key key, const std::string& eventName,
		const std::function<void(sf::Event)>& eventCallback)
{
	addEventCallback(sf::Event::KeyPressed, eventName, std::move([key, eventCallback](sf::Event event)
	{
		if (event.key.code == key)
		{
			eventCallback(event);
		}
	}));
}

void EventHandler::addKeyReleasedEventCallback(sf::Keyboard::Key key, const std::string& eventName,
		const std::function<void(sf::Event)>& eventCallback)
{
	addEventCallback(sf::Event::KeyReleased, eventName, std::move([key, eventCallback](sf::Event event)
	{
		if (event.key.code == key)
		{
			eventCallback(event);
		}
	}));
}

void EventHandler::addMouseButtonPressedEventCallback(sf::Mouse::Button button, const std::string& eventName,
		const std::function<void(sf::Event)>& eventCallback)
{
	addEventCallback(sf::Event::MouseButtonPressed, eventName, std::move([button, eventCallback](sf::Event event)
	{
		if (event.mouseButton.button == button)
		{
			eventCallback(event);
		}
	}));
}

void EventHandler::addMouseButtonReleasedEventCallback(sf::Mouse::Button button, const std::string& eventName,
		const std::function<void(sf::Event)>& eventCallback)
{
	addEventCallback(sf::Event::MouseButtonReleased, eventName, std::move([button, eventCallback](sf::Event event)
	{
		if (event.mouseButton.button == button)
		{
			eventCallback(event);
		}
	}));
}

