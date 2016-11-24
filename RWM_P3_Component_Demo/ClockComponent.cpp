
#include "ClockComponent.h"

#include <ctime>
#include <chrono>
#include <sstream>




void ClockComponent::init()
{
}

std::string ClockComponent::getTimeAsString()
{
	//adapted from http://stackoverflow.com/questions/15957805/extract-year-month-day-etc-from-stdchronotime-point-in-c

	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

	time_t tt = std::chrono::system_clock::to_time_t(now);


	tm local_tm;
	localtime_s(&local_tm, &tt);

	std::stringstream timeStr;
	timeStr << local_tm.tm_hour << ':';
	timeStr << local_tm.tm_min << ':';
	timeStr << local_tm.tm_sec;

	return timeStr.str();

}




