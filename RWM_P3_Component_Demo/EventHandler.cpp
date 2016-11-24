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
void EventHandler::Dispatch(std::string eventname)
{

	// find the list of listners for this event name
	if (listeners.find(eventname) != listeners.end()) {

		for (auto const &listener : *listeners[eventname]) { //go through all listeners for this event
			listener->onEvent(eventname); //Call onEvent for the listener

		}
	}

}