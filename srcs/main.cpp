#include <iostream>

#include "Entity.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"
#include "Windows.hpp"
#include "EntityGroup.hpp"
#include "Player.hpp"
#include "Decor.hpp"

int main(void) {
	clock_t	clockTmp;
	Windows	win;
	EntityGroup group;
	Player  *player = new Player;

    group.append(player);
	clockTmp = clock();
    int time = 0;
	while(!win.isKeyPress(QUIT) && !player->isDead()) {
		win.keyPress();
		if (clock() - clockTmp >= CLOCKS_PER_SEC / FPS) {
            player->setDir(win);
			group.run();
            clear();
			for (int i = 0; i < group.length(); i++)
					win.drawEntity(*(group.getElem(i)));
            win.drawText(0, 0, time);
            clockTmp = clock();
			win.initKey();
            player->setDir(win);
            time++;
		}
	}

	return 0;
}