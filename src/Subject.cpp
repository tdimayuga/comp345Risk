/*
 * Subject.cpp
 *
 *  Created on: Nov 8, 2015
 *      Author: Sean
 */

#include <list>

#include "Subject.h"
#include "Observer.h"

using namespace std;

namespace risk {

Subject::Subject() {
	observers = new list<Observer*>;
};

Subject::~Subject() {
	delete observers;
};

void Subject::Attach(Observer* o) {
	observers->push_back(o);
};

void Subject::Detach(Observer* o) {
	observers->remove(o);
};

void Subject::Notify() {
	 list<Observer *>::iterator i = observers->begin();
	  for (; i != observers->end(); ++i)
		(*i)->Update();
};

} /* namespace GameDriver */
