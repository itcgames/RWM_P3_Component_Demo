#pragma once
#include "SDL.h"
#include "EventListener.h"
#include <string>

class ClockComponent
{
public:
	void init();
	std::string getTimeAsString();

};

