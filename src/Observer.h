/*
 * Observer.h
 *
 *  Created on: Nov 8, 2015
 *      Author: Sean
 */

#ifndef OBSERVER_H_
#define OBSERVER_H_

namespace risk {

class Subject;

class Observer {
public:
	~Observer();
	virtual void Update() = 0;
protected:
	Observer();

};

} /* namespace GameDriver */

#endif /* OBSERVER_H_ */
