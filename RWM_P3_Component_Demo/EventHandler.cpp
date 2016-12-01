#include "Event.h"
#include "EventHandler.h"




void EventHandler::AddListener(Events eventType, EventListener *listener)
{
	//check if there is already a list for this event
	if (listeners.find(eventType) == listeners.end()) { //event not in map add it.
		listeners[eventType] = new std::vector<EventListener*>();
	}

	listeners[eventType]->push_back(listener);

}

//Send the events to interested objects
void EventHandler::dispatch(const Event e)
{

	// find the list of listners for this event name
	if (listeners.find(e.type) != listeners.end()) {

		for (auto const &listener : *listeners[e.type]) { //go through all listeners for this event
			listener->onEvent(e); //Call onEvent for the listener

		}
	}

}