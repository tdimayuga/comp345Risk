/*
 * Subject.h
 *
 *  Created on: Nov 8, 2015
 *      Author: Sean-Frankel Gaon Canlas
 */

#ifndef Subject_H_
#define Subject_H_

#include <list>

using namespace std;

class Observer;

class Subject {
public:
	virtual void Attach(Observer* o);
	virtual void Detach(Observer* o);
	virtual void Notify();
	Subject();
	~Subject();
private:
	list<Observer*> *observers;
};

#endif /* Subject_H_ */
