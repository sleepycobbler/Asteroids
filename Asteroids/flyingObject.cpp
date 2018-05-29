#include "flyingObject.h"


// Put your FlyingObject method bodies here
FlyingObject::FlyingObject()
{
	alive = true;
	vel.setDx(0);
	vel.setDy(0);
}


FlyingObject::~FlyingObject()
{
}

void FlyingObject::setPoint(Point newPos)
{
	pos = newPos;
}

void FlyingObject::setVel(Velocity vel)
{
	this->vel = vel;
}

void FlyingObject::wrap()
{
	if (pos.getX() > 200)
	{
		pos.setX(-200);
	}

	if (pos.getX() < -200)
	{
		pos.setX(200);
	}

	if (pos.getY() > 200)
	{
		pos.setY(-200);
	}

	if (pos.getY() < -200)
	{
		pos.setY(200);
	}
}
