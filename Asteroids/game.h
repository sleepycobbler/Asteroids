/*********************************************************************
 * File: game.h
 * Description: Defines the game class for Asteroids
 *
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

class Game
{
private:
	std::vector<Bullet> bullets;
	std::vector<Rock*> asteroids;
	Ship ship;

	bool isOnScreen(const Point & point);
	void advanceBullets();
	void advanceAsteroids();

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
