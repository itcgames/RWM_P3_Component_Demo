#pragma once
#include "Events.h"
#include "IEventListener.h"
#include "Map"
#include "vector"

class Event;//forward decl

class EventHandler
{
	std::map<
		Events,
		std::vector<EventListener*>* //pointer to vec of eventlisteners
	> listeners;

public:
	//implement singleton
	static EventHandler& getInstance()
	{
		static EventHandler    instance; // Guaranteed to be destroyed.
										// Instantiated on first use.
		return instance;
	}

	void AddListener(Events, EventListener * listener);
	void dispatch(const Event);


private:
	EventHandler() {};


};


