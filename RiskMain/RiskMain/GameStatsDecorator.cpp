/*
 * GameStatsDecorator.cpp
 *
 *  Created on: Nov 26, 2015
 *      Author: Sean
 */

#include "GameStatsDecorator.h"

#include <iostream>


GameStatsDecorator::~GameStatsDecorator() {
}

void GameStatsDecorator::Update() {
	display();
}

void GameStatsDecorator::display() {
	cout << "Decorator Display";
}