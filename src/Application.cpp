//
// Created by Piotr Meller on 23.05.2021.
//

#include <SFML/Window/Event.hpp>
#include "Application.h"

template<class EventHandlerTemplate>
Application<EventHandlerTemplate>::Application() : Application(1280,720,"window")
{
}

template<class EventHandlerTemplate>
Application<EventHandlerTemplate>::Application(unsigned int width, unsigned int height, const std::string& title) : m_window({ width, height }, title), m_eventHandler(m_window), m_fpsCounter(m_window)
{
}

template<class EventHandlerTemplate>
void Application<EventHandlerTemplate>::init()
{
	m_window.setFramerateLimit(240);

	m_eventHandler.addEventCallback(sf::Event::Closed, "closeApp", [this](sf::Event event)
	{
		m_window.close();
	});

	m_eventHandler.addKeyPressesEventCallback(sf::Keyboard::Escape, "closeAppKeyboard", [this](sf::Event event){
		m_window.close();
	});
}

template<class EventHandlerTemplate>
void Application<EventHandlerTemplate>::run()
{
	init();

	while (m_window.isOpen())
	{
		m_fpsCounter.update();
		m_eventHandler.handleEvents();
		m_window.clear(sf::Color::Black);
		m_window.display();
	}

	exit();
}

template<class EventHandlerTemplate>
void Application<EventHandlerTemplate>::exit()
{
}

template<class EventHandlerTemplate>
const sf::RenderWindow& Application<EventHandlerTemplate>::getWindow() const
{
	return m_window;
}


template class Application<EventHandler>;

