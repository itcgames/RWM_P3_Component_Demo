#pragma once
#include <string>



/**Used as an interface for the event dispatcher*/
/*Objects wanting to receive events must inherit from this*/
class EventListener
{
public:
	virtual void onEvent(std::string eventName) = 0;
};
