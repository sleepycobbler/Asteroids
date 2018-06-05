/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *
 *********************************************************************/

#include "game.h"

#define OFF_SCREEN_BORDER_AMOUNT 5

// These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>
using namespace std;

bool Game::isOnScreen(const Point & point)
{
	return (point.getX() >= topLeft.getX() - OFF_SCREEN_BORDER_AMOUNT
		&& point.getX() <= bottomRight.getX() + OFF_SCREEN_BORDER_AMOUNT
		&& point.getY() >= bottomRight.getY() - OFF_SCREEN_BORDER_AMOUNT
		&& point.getY() <= topLeft.getY() + OFF_SCREEN_BORDER_AMOUNT);
}

void Game::advanceAsteroids()
{
	for (int i = 0; i < asteroids.size(); i++)
	{
		asteroids[i]->advance();
		asteroids[i]->rotate();
		asteroids[i]->wrap();
	}
}

Game::Game(Point tl, Point br)
	: topLeft(tl), bottomRight(br)
{
	state = GS_MENU;
	select.setY(6);
	select.setX(-100);
	createBigRock(Point(-125, 150));
	createBigRock(Point(125, 150));
}

Game::~Game()
{
}


// You may find this function helpful...

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/

float Game :: getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const
{
   // find the maximum distance traveled
   float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
   dMax = max(dMax, abs(obj2.getVelocity().getDx()));
   dMax = max(dMax, abs(obj2.getVelocity().getDy()));
   dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.
   
   float distMin = std::numeric_limits<float>::max();
   for (float i = 0.0; i <= dMax; i++)
   {
      Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
                     obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
      Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
                     obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));
      
      float xDiff = point1.getX() - point2.getX();
      float yDiff = point1.getY() - point2.getY();
      
      float distSquared = (xDiff * xDiff) +(yDiff * yDiff);
      
      distMin = min(distMin, distSquared);
   }
   
   return sqrt(distMin);
}

void Game::advanceBullets()
{

	// Move each of the bullets forward if it is alive
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].isAlive())
		{
			// this bullet is alive, so tell it to move forward
			bullets[i].advance();
			bullets[i].wrap();

		}
	}
}

void Game::advance()
{

	switch (state)
	{
	case GS_MENU:
		for (int i = 0; i < asteroids.size(); i++)
		{
			asteroids[i]->rotate();
		}
		break;
	case GS_START:
		for (int i = 0; i < 5; i++)
		{
			Point pos(200, random(-200, 200));
			createBigRock(pos);
		}
		state = GS_RUN;
	case GS_RUN:
		if (ship.isAlive())
		{
			advanceAsteroids();
			ship.advance();
			ship.wrap();
			advanceBullets();
			handleCollisions();
		}
		break;
	default:
		break;
	}

	cleanUp();
}

void Game::draw(const Interface & ui)
{
   switch(state)
   {
   case GS_MENU:
	   drawLargeText(Point(-45, 150), "Asteroids");

	   drawAsteroids();

	   drawText(Point(-70, 100), "By Max Schuhmacher");

	   drawText(Point(-170, 50), "Use the Up and Down arrows to navigate, press Space to select");

	   drawShip(select, 270, true);

	   drawLargeText(Point(-65, 0), "Start");
	   drawLargeText(Point(-65, -50), "Credits");
	   break;
   case GS_START:
   case GS_RUN:
	   drawAsteroids();

	   if (ship.isAlive())
		   ship.draw();

	   for (int i = 0; i < bullets.size(); i++)
	   {
		   if (bullets[i].isAlive())
		   {
			   bullets[i].draw();
		   }
	   }
	   break;
   case GS_OPTIONS:
	   break;
   case GS_PAUSE:
	   break;
   case GS_OVER:
	   break;
   default:
	   break;
   }
}

void Game::handleInput(const Interface & ui)
{
	switch (state)
	{
	case GS_MENU:
		break;
	case GS_START:
	case GS_RUN:
		if (ship.isAlive())
		{
			if (ui.isLeft())
			{
				ship.rotateLeft();
			}

			if (ui.isRight())
			{
				ship.rotateRight();
			}

			if (ui.isUp())
			{
				ship.boost();
				ship.setThrust(true);
			}
			else
			{
				ship.setThrust(false);
			}

			if (ui.isSpace())
			{
				Bullet newBullet;
				newBullet.fire(ship.getPoint(), ship.getOrientation(), ship.getVelocity());

				bullets.push_back(newBullet);
				cout << ui.isSpace();
			}
		}
		break;
	case GS_OPTIONS:
		break;
	case GS_PAUSE:
		break;
	case GS_OVER:
		break;
	default:
		break;
	}
}

void Game::handleCollisions()
{
	vector<Rock*> newRocks;

	for (vector<Rock*>::iterator iRock = asteroids.begin(); iRock != asteroids.end(); iRock++)
	{
		for (vector<Bullet>::iterator iBullet = bullets.begin(); iBullet != bullets.end(); iBullet++)
		{
			switch ((*iRock)->getSize()) 
			{
				case BIG_ROCK_SIZE:
					if (BIG_ROCK_SIZE > getClosestDistance(**iRock, *iBullet))
					{
						if ((*iBullet).isAlive() && (**iRock).isAlive())
						{
							(*iBullet).kill();
							breakBigRock(newRocks, *iRock);
							(**iRock).kill();
						}
						
					}
					break;
				case MEDIUM_ROCK_SIZE:
					if (MEDIUM_ROCK_SIZE > getClosestDistance(**iRock, *iBullet))
					{
						if ((*iBullet).isAlive() && (**iRock).isAlive())
						{
							(*iBullet).kill();
							breakMedRock(newRocks, *iRock);
							(**iRock).kill();
						}
					}
					break;
				case SMALL_ROCK_SIZE:
					if (SMALL_ROCK_SIZE > getClosestDistance(**iRock, *iBullet))
					{
						if ((*iBullet).isAlive() && (**iRock).isAlive())
						{
							(*iBullet).kill();
							(**iRock).kill();
						}
					}
					break;
				default:
					break;
			}
		}

		if (getClosestDistance(ship, **iRock) < BIG_ROCK_SIZE    && (*iRock)->getSize() == BIG_ROCK_SIZE    ||
			getClosestDistance(ship, **iRock) < MEDIUM_ROCK_SIZE && (*iRock)->getSize() == MEDIUM_ROCK_SIZE ||
			getClosestDistance(ship, **iRock) < SMALL_ROCK_SIZE  && (*iRock)->getSize() == SMALL_ROCK_SIZE)
		{
			ship.kill();
		}
	}

	for (vector<Rock*>::iterator iRock = newRocks.begin(); iRock != newRocks.end(); iRock++)
	{
		asteroids.push_back(*iRock);
	}

	newRocks.clear();
}

void Game::cleanUp()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (!bullets[i].isAlive())
		{
			bullets.erase(bullets.begin() + i);
		}
	}

	for (int i = 0; i < asteroids.size(); i++)
	{
		if (!asteroids[i]->isAlive())
		{
			asteroids.erase(asteroids.begin() + i);
		}
	}
}

void Game::createBigRock(Point pos)
{
	Rock* newAsteroid = new BigRock(pos);
	asteroids.push_back(newAsteroid);
}

void Game::breakBigRock(std::vector<Rock*> & newRocks, Rock * copy)
{
	newRocks.push_back(new MedRock(copy->getPoint()));
	newRocks.push_back(new MedRock(copy->getPoint()));
	newRocks.push_back(new  SmRock(copy->getPoint()));
}

void Game::breakMedRock(std::vector<Rock*> & newRocks, Rock * copy)
{
	newRocks.push_back(new SmRock(copy->getPoint()));
	newRocks.push_back(new SmRock(copy->getPoint()));
}

void Game::drawAsteroids()
{
	for (int i = 0; i < asteroids.size(); i++)
	{
		if (asteroids[i]->isAlive())
		{
			asteroids[i]->draw();
		}
	}
}

