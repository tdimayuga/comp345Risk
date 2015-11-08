/*
 * PlayerView.h
 *
 *  Created on: Nov 8, 2015
 *      Author: Sean
 */

#ifndef PLAYERVIEW_H_
#define PLAYERVIEW_H_

#include "Observer.h"
#include "player.h"

namespace risk {

class PlayerView : public Observer {
private:
	Player *player;
public:
	PlayerView();
	PlayerView(Player* player);
	~PlayerView();
	void Update();
	void display();

};

} /* namespace GameDriver */

#endif /* PLAYERVIEW_H_ */
