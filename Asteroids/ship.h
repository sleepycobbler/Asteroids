#ifndef ship_h
#define ship_h

#define SHIP_SIZE 10

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5
#include "flyingObject.h"


// Put your Ship class here
class Ship : public FlyingObject
{
private:
	float orientation;
	bool thrust;

public:
	float getOrientation() { return orientation; };
	void setOrientation(float orient) { orientation = orient; };

	float isThrust() { return thrust; };
	void setThrust(bool thrust) { this->thrust = thrust; };

	Ship();
	void rotateLeft();
	void rotateRight();
	void boost();
	void draw();
};

#endif /* ship_h */
