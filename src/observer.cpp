/*
 * observer.cpp
 *
 *  Created on: Nov 23, 2017
 *      Author: efarhan
 */

#include <observer.h>
#include <iostream>

void Subject::add_observer(Observer* observer)
{
	observers.push_back(observer);
}
void Subject::remove_observer(Observer* observer)
{
	observers.remove(observer);
}

void Subject::notify()
{
	for(auto observer : observers)
	{
		observer->onNotify();
	}
}

PrintObserver::PrintObserver(int id)
{
	this->id = id;
}

void PrintObserver::onNotify()
{
	std::cout << "ON NOTIFY FROM ID: "<<id<<"\n";
}
