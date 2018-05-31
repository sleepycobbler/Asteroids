#include "bullet.h"
#include "uiDraw.h"
#include <cmath>

#define M_PI 3.1415926535897932


Bullet::Bullet()
{
	bulletLife = BULLET_LIFE;
}


Bullet::~Bullet()
{
}

void Bullet::fire(Point point, float angle)
{
	pos = point;
	vel.setDx(10.0 * cos(M_PI / 180.0 * (angle + 90)));
	vel.setDy(10.0 * sin(M_PI / 180.0 * (angle + 90)));
}

void Bullet::fire(Point point, float angle, Velocity vel)
{
	pos = point;
	this->vel.setDx(10.0 * cos(M_PI / 180.0 * (angle + 90)) + vel.getDx());
	this->vel.setDy(10.0 * sin(M_PI / 180.0 * (angle + 90)) + vel.getDy());

}

void Bullet::draw()
{
	drawDot(pos);
	bulletLife--;

	if (bulletLife <= 0)
	{
		kill();
	}
}