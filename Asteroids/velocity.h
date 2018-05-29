#ifndef VELOCITY_H
#define VELOCITY_H


// Put your velocity class here, or overwrite this file with your own
// velocity class from the previous project
class Velocity
{
private:
	float dx;
	float dy;

public:
	//constructor
	Velocity();

	//non default constructor
	Velocity(float dx, float dy);
	~Velocity();

	// getters
	float getDx() const { return dx; };
	float getDy() const { return dy; };

	// setters
	void setDx(float Dx);
	void setDy(float Dy);

	void addDx(float Dx);
	void addDy(float Dy);


};

#endif /* velocity_h */
