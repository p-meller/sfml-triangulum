//
// Created by Piotr Meller on 06.06.2021.
//

#ifndef TRIANGULUM_EVENTHANDLER_H
#define TRIANGULUM_EVENTHANDLER_H


#include <SFML/Window/Event.hpp>
#include <unordered_map>
#include <functional>
#include "EventCallback.h"

namespace sf
{
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

	void addEventCallback(sf::Event::EventType eventType, const std::string& eventName,
			std::function<void(sf::Event)> eventCallback);

	void addEventCallback(sf::Event::EventType eventType, const std::string& eventName,
			std::function<void(sf::Event)> eventCallback, std::function<bool(sf::Event)> eventCondition);

	void addEventCallback(sf::Event::EventType eventType, const std::string& eventName,
			std::unique_ptr<EventCallback> eventCallback);

	void addKeyPressesEventCallback(sf::Keyboard::Key key, const std::string& eventName, const std::function<void(
			sf::Event)>& eventCallback);

	void addKeyReleasedEventCallback(sf::Keyboard::Key key, const std::string& eventName,
			const std::function<void(sf::Event)>& eventCallback);

	void addMouseButtonPressedEventCallback(sf::Mouse::Button button, const std::string& eventName,
			const std::function<void(sf::Event)>& eventCallback);

	void addMouseButtonReleasedEventCallback(sf::Mouse::Button button, const std::string& eventName,
			const std::function<void(sf::Event)>& eventCallback);

};


#endif //TRIANGULUM_EVENTHANDLER_H
