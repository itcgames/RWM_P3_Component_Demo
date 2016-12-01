#pragma once
#include "SDL.h"
#include "Event.h"
#include <string>

class ClockComponent
{
public:
	void init();
	std::string getTimeAsString();

};

