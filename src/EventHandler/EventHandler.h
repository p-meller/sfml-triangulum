//
// Created by Piotr Meller on 06.06.2021.
//

#ifndef TRIANGULUM_EVENTHANDLER_H
#define TRIANGULUM_EVENTHANDLER_H


#include <SFML/Window/Event.hpp>
#include "EventCallback.h"

namespace sf{
	class RenderWindow;
}

using CallbackRegisterType = std::unordered_map<std::string, std::unique_ptr<EventCallback>>;
using EventRegisterType = std::unordered_map<sf::Event::EventType, CallbackRegisterType>;

class EventHandler
{
	sf::RenderWindow& m_window;
	EventRegisterType eventRegister;

public:
	explicit EventHandler(sf::RenderWindow& window);

	void handleEvents();

	void addEventCallback(sf::Event::EventType eventType, const std::string& eventName, std::function<void(sf::Event)> eventCallback);

	void addEventCallback(sf::Event::EventType eventType, const std::string& eventName, std::unique_ptr<EventCallback> eventCallback);
};


#endif //TRIANGULUM_EVENTHANDLER_H
