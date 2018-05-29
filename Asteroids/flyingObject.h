#ifndef flyingObject_h
#define flyingObject_h
#include "point.h"
#include "velocity.h"


// Put your FlyingObject class here
class FlyingObject
{
private:
	bool alive;
protected:
	Point pos;
	Velocity vel;
public:
	FlyingObject();
	~FlyingObject();

	// Shrodiner's Flying Object
	bool isAlive() { return alive; };

	// Set alive equal to not true
	void kill() { alive = false; }

	// Setters
	void setPoint(Point newPos);
	void setVel(Velocity vel);

	// Getters
	Point getPoint() const { return pos; };
	Velocity getVelocity() const { return vel; };

	// Move forward
	void advance()
	{
		pos.addX(vel.getDx());
		pos.addY(vel.getDy());
	};

	void wrap();
};



#endif /* flyingObject_h */
