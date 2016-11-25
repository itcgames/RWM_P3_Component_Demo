#include "EventHandler.h"




void EventHandler::AddListener(std::string eventName, EventListener *listener)
{
	//check if there is already a list for this event
	if (listeners.find(eventName) == listeners.end()) { //event not in map add it.
		listeners[eventName] = new std::vector<EventListener*>();
	}

	listeners[eventName]->push_back(listener);

}

//Send the events to interested objects
void EventHandler::dispatch(const Event e)
{

	// find the list of listners for this event name
	if (listeners.find(e.name) != listeners.end()) {

		for (auto const &listener : *listeners[e.name]) { //go through all listeners for this event
			listener->onEvent(e); //Call onEvent for the listener

		}
	}

}