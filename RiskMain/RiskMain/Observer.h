/*
 * Observer.h
 *
 *  Created on: Nov 8, 2015
 *      Author: Sean-Frankel Gaon Canlas
 */

#ifndef OBSERVER_H_
#define OBSERVER_H_

class Subject;

class Observer {
public:
	~Observer();
	virtual void Update() = 0;
protected:
	Observer();

};

#endif /* OBSERVER_H_ */
