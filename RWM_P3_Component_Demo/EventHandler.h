#pragma once
#include "EventListener.h"
#include "Map"
#include "vector"


class EventHandler
{
	std::map<
		std::string,
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

	void AddListener(std::string eventName, EventListener * listener);
	void Dispatch(std::string eventName);



private:
	EventHandler() {};


};

