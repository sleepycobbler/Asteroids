/*********************************************************************
 * File: game.h
 * Description: Defines the game class for Asteroids
 *

 switch(state)
 {
 case GS_MENU:
    break;
 case GS_START:
    break;
 case GS_RUN:
    break;
 case GS_OPTIONS:
    break;
 case GS_PAUSE:
    break;
 case GS_OVER:
    break;
 case default:
	break;
 }
 *********************************************************************/

#ifndef GAME_H
#define GAME_H

#include "bullet.h"
#include <vector>
#include "ship.h"
#include "rocks.h"
#include "uiInteract.h"
#include "uiDraw.h"

#define SM_ROCK 0x00000
#define MD_ROCK 0x00001
#define LG_ROCK 0x00002

//GS means game state
#define GS_RUN     0x00000
#define GS_PAUSE   0x00001
#define GS_MENU    0x00002
#define GS_OPTIONS 0x00003
#define GS_START   0x00004
#define GS_OVER    0x00005
#define GS_LVL1    0x00001
#define GS_LVL2    0x00002
#define GS_LVL3    0x00003

class Game
{
private:
	std::vector<Bullet> bullets;
	std::vector<Rock*> asteroids;
	Ship ship;
	Point select;

	int state;

	bool isOnScreen(const Point & point);
	void advanceBullets();
	void advanceAsteroids();
	void drawAsteroids();

	Point topLeft;
	Point bottomRight;

public:
	Game(Point tl, Point br);
	~Game();

	void advance();
	void draw(const Interface & ui);
	void handleInput(const Interface & ui);
	void handleCollisions();
	void cleanUp();

	void createBigRock(Point pos);

	void breakBigRock(std::vector<Rock*> & newRocks, Rock* copy);
	void breakMedRock(std::vector<Rock*> & newRocks, Rock* copy);

	float getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const;





};



#endif /* GAME_H */
