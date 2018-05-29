#ifndef bullet_h
#define bullet_h

#define BULLET_SPEED 5
#define BULLET_LIFE 40
#include "flyingObject.h"


// Put your Bullet class here
class Bullet : public FlyingObject
{
private:
	int bulletLife;

public:
	Bullet();
	~Bullet();

	// takes a position and an angle to shoot towards
	void fire(Point point, float angle);
	void draw();
};



#endif /* bullet_h */
