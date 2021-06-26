//
// Created by Piotr Meller on 23.05.2021.
//

#include "FpsCounter.h"

FpsCounter::FpsCounter(sf::RenderWindow& window) : m_window(window)
{

}


void FpsCounter::update()
{
	++m_frameCount;

	if (m_delayTimer.getElapsedTime().asSeconds() > 0.5)
	{
		m_fps = m_frameCount / m_fpsTimer.restart().asSeconds();
		m_frameCount = 0;
		m_delayTimer.restart();
	}

	std::string fps = std::to_string(m_fps) + " FPS";
	m_window.setTitle(fps);
}

float FpsCounter::getFps() const
{
	return m_fps;
}