#pragma once

class Event; //forward declaration

/**Used as an interface for the event dispatcher*/
/*Objects wanting to receive events must inherit from this*/
class EventListener
{
public:
	virtual void onEvent(const Event e) = 0;
};
