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
	rotation = BIG_ROCK_SPIN;
	size = BIG_ROCK_SIZE;
	angle = random(0, 359);
	vel.setDx(cos(angle));
	vel.setDy(sin(angle));

}

BigRock::BigRock(Point pos)
{
	this->pos = pos;
	rotation = BIG_ROCK_SPIN;
	size = BIG_ROCK_SIZE;
	angle = random(0, 359);
	vel.setDx(cos(angle));
	vel.setDy(sin(angle));
}

BigRock::~BigRock()
{
}

int BigRock::getSize()
{
	return BIG_ROCK_SIZE;
}

void BigRock::draw()
{
	drawLargeAsteroid(pos, rotation);
}

MedRock::MedRock()
{
	rotation = MEDIUM_ROCK_SPIN;
	size = MEDIUM_ROCK_SIZE;
	angle = random(0, 359);
	vel.setDx(cos(angle));
	vel.setDy(sin(angle));
}

MedRock::MedRock(Point pos)
{
	this->pos = pos;
	rotation = MEDIUM_ROCK_SPIN;
	size = MEDIUM_ROCK_SIZE;
	angle = random(0, 359);
	vel.setDx(cos(angle));
	vel.setDy(sin(angle));
}

MedRock::~MedRock()
{
}

int MedRock::getSize()
{
	return MEDIUM_ROCK_SIZE;
}

void MedRock::draw()
{
	drawMediumAsteroid(pos, rotation);
}

SmRock::SmRock()
{
	rotation = SMALL_ROCK_SPIN;
	size = SMALL_ROCK_SIZE;
	angle = random(0, 359);
	vel.setDx(cos(angle));
	vel.setDy(sin(angle));
}

SmRock::SmRock(Point pos)
{
	this->pos = pos;
	rotation = SMALL_ROCK_SPIN;
	size = SMALL_ROCK_SIZE;
	angle = random(0, 359);
	vel.setDx(cos(angle));
	vel.setDy(sin(angle));
}

SmRock::~SmRock()
{
}

int SmRock::getSize()
{
	return SMALL_ROCK_SIZE;
}

void SmRock::draw()
{
	drawSmallAsteroid(pos, rotation);
}
