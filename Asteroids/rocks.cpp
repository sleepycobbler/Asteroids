#include "rocks.h"
#include "uiDraw.h"
#include <cmath>

void Rock::rotate(int angle)
{
	rotation += angle;
}

// Put your Rock methods here
BigRock::BigRock()
{
	rotation = 2;
	angle = random(0, 359);
	vel.setDx(cos(angle));
	vel.setDy(sin(angle));

}

BigRock::BigRock(Point pos)
{
	this->pos = pos;
	rotation = 2;
	angle = random(0, 359);
	vel.setDx(cos(angle));
	vel.setDy(sin(angle));
}

BigRock::~BigRock()
{
}

void BigRock::draw()
{
	drawLargeAsteroid(pos, rotation);
}

MedRock::MedRock()
{
}

MedRock::~MedRock()
{
}

void MedRock::draw()
{
}

SmRock::SmRock()
{
}

SmRock::~SmRock()
{
}

void SmRock::draw()
{
}
