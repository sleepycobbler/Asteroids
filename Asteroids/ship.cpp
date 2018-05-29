#include "ship.h"
#include "uiDraw.h"
#include "cmath"
# define M_PI           3.14159265358979323846  /* pi */

// Put your ship methods here

Ship::Ship()
{
	orientation = 0;
	thrust = false;
}

void Ship::rotateLeft()
{
	orientation += 6;
}

void Ship::rotateRight()
{
	orientation -= 6;
}

void Ship::boost()
{
	vel.addDx(cos( M_PI/180 * (orientation + 90)) * 0.5);
	vel.addDy(sin( M_PI/180 * (orientation + 90)) * 0.5);
}

void Ship::draw()
{
	drawShip(pos, orientation, thrust);
}