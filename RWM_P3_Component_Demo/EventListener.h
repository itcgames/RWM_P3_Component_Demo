#pragma once
#include <string>

class Event {

public:
	std::string name;

	Event(std::string n = "Unknown", void* d = nullptr) :name(n), data(d) {}

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
		data= new std::shared_ptr<T>(object_ptr);

	}


	//reverse of setData.
	template<class T>  T getData() const
	{
		//data is a pointer to a shared pointer to the dataObject
		std::unique_ptr<
			std::shared_ptr<T>
			> data_ptr((std::shared_ptr<T>*) data);
		

		std::shared_ptr<T> object_ptr = *data_ptr;

		return *object_ptr;

	}

private:
	void* data;
};



/**Used as an interface for the event dispatcher*/
/*Objects wanting to receive events must inherit from this*/
class EventListener
{
public:
	virtual void onEvent(const Event e) = 0;
};
