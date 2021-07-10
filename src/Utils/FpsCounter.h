//
// Created by Piotr Meller on 23.05.2021.
//

#ifndef TRIANGULUM_FPSCOUNTER_H
#define TRIANGULUM_FPSCOUNTER_H


#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class FpsCounter
{
public:
	explicit FpsCounter(sf::RenderWindow& window);

	void update();

	float getFps() const;

private:
	sf::RenderWindow& m_window;
	sf::Clock m_delayTimer;
	sf::Clock m_fpsTimer;

	float m_fps = 0;

	int m_frameCount = 0;
};


#endif //TRIANGULUM_FPSCOUNTER_H
