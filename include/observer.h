/*
 * observer.h
 *
 *  Created on: Nov 23, 2017
 *      Author: efarhan
 */

#ifndef OBSERVER_H_
#define OBSERVER_H_

#include <list>

class Observer
{
public:
  virtual ~Observer() {}
  virtual void onNotify() = 0;
};

class Subject
{
private:
	std::list<Observer*> observers;
public:
	virtual void notify();
	void add_observer(Observer* observer);
	void remove_observer(Observer* observer);
};

class PrintObserver: public Observer
{
public:
	PrintObserver(int id);
	virtual void onNotify() override;
private:
	int id;
};




#endif /* INCLUDE_OBSERVER_H_ */
