#pragma once
#include "Events.h"
#include "IEventListener.h"
#include "EventHandler.h"

class Event {

public:
	Events type;

	Event(Events ev = Events::unkown, void* d = nullptr) :type(ev), data(d) {}

	//This code is used to allow events to carry aribitary objects, these are pointed to by data
	//We don't know how many listeners are going to use thsi data nor do we know how long the data is needed, os difficult
	//to assign an owner to the dataobject for  memory deallocation purposes.
	//We also don't know what type the data objects will be
	//the dataObject is cloned 
	template<class T>  void setData(const T dataObject)
	{

		//Create a new object to store the data, pointed to by smart pointer
		std::shared_ptr<T> object_ptr(new T);
		//clone the data into the new object
		*object_ptr = dataObject;

		//data will point to the shared_pointer
		data = new std::shared_ptr<T>(object_ptr);

	}


	//reverse of setData.
	template<class T>  T getData() const
	{
		//reverse the operation of setData
		//data is a pointer to a shared pointer to the dataObject


		std::shared_ptr<
			std::shared_ptr<T>
		> data_ptr((std::shared_ptr<T>*) data);


		std::shared_ptr<T> object_ptr = *data_ptr;

		return *object_ptr;

	}

private:
	void* data;
};
