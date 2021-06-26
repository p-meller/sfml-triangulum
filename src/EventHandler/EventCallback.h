//
// Created by Piotr Meller on 20.06.2021.
//

#ifndef TRIANGULUM_EVENTCALLBACK_H
#define TRIANGULUM_EVENTCALLBACK_H

namespace sf
{
	class Event;
}

class EventCallback
{
public:
	virtual void doAction(sf::Event event) = 0;

};

#endif //TRIANGULUM_EVENTCALLBACK_H
