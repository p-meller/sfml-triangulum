//
// Created by Piotr Meller on 23.05.2021.
//

#ifndef TRIANGULUM_APPLICATION_H
#define TRIANGULUM_APPLICATION_H


#include <SFML/Graphics/RenderWindow.hpp>
#include "Utils/FpsCounter.h"
#include "EventHandler/EventHandler.h"

template<class EventHandlerTemplate = EventHandler>
class Application
{
public:
	Application();
	Application(unsigned int width, unsigned int height, const std::string& title);
	virtual void init();
	virtual void run();
	virtual void exit();
	const sf::RenderWindow& getWindow() const;

private:

	sf::RenderWindow m_window;
	EventHandlerTemplate m_eventHandler;
	FpsCounter m_fpsCounter;
};


#endif //TRIANGULUM_APPLICATION_H
