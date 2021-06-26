//
// Created by Piotr Meller on 23.05.2021.
//

#ifndef TRIANGULUM_APPLICATION_H
#define TRIANGULUM_APPLICATION_H


#include <SFML/Graphics/RenderWindow.hpp>
#include "Utils/FpsCounter.h"
#include "EventHandler/EventHandler.h"

class Application
{
public:
	Application();
	void run();
	void exit();
	const sf::RenderWindow& getWindow() const;

private:

	sf::RenderWindow m_window;
	EventHandler m_eventHandler;
	FpsCounter m_fpsCounter;
};


#endif //TRIANGULUM_APPLICATION_H
