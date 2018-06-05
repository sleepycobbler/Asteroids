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
	int size;
public:
	virtual void draw()   = 0;
	virtual void rotate() = 0;
	void rotate(int angle);
	virtual int getSize() = 0;
};

//   BigRock
class BigRock : public Rock
{
private:
	
public:
	BigRock();
	BigRock(Point pos);
	~BigRock();
	int getSize();
	void draw();
	void rotate();
};

//   MediumRock
class MedRock : public Rock
{
public:
	MedRock();
	MedRock(Point pos);
	~MedRock();
	int getSize();
	void draw();
	void rotate();
};

//   SmallRock
class SmRock : public Rock
{
public:
	SmRock();
	SmRock(Point pos);
	~SmRock();
	int getSize();
	void draw();
	void rotate();
};

#endif /* rocks_h */
