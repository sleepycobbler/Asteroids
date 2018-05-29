#ifndef rocks_h
#define rocks_h

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10
#include "flyingObject.h"


// Define the following classes here:

//   Rock
class Rock : public FlyingObject
{
protected:
	int rotation;
	int angle;
public:
	virtual void draw() = 0;
	void rotate(int angle);
};

//   BigRock
class BigRock : public Rock
{
private:
	
public:
	BigRock();
	BigRock(Point pos);
	~BigRock();
	void draw();
};

//   MediumRock
class MedRock : public Rock
{
	MedRock();
	~MedRock();
	void draw();
};

//   SmallRock
class SmRock : public Rock
{
	SmRock();
	~SmRock();
	void draw();
};

#endif /* rocks_h */
