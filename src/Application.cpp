//
// Created by Piotr Meller on 23.05.2021.
//

#include <SFML/Window/Event.hpp>
#include "Application.h"

Application::Application() : Application(1280,720,"window")
{
}

Application::Application(unsigned int width, unsigned int height, const std::string& title) : m_window({ width, height }, title), m_eventHandler(m_window), m_fpsCounter(m_window)
{

}

void Application::run()
{

	m_eventHandler.addEventCallback(sf::Event::Closed, "closeApp", [this](sf::Event event)
	{
		exit();
		m_window.close();
	});

	m_window.setFramerateLimit(240);

	while (m_window.isOpen())
	{
		m_fpsCounter.update();
		m_eventHandler.handleEvents();
		m_window.clear(sf::Color::Black);
		m_window.display();
	}
}

void Application::exit()
{
}

const sf::RenderWindow& Application::getWindow() const
{
	return m_window;
}
