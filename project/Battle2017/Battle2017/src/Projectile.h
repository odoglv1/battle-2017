#pragma once //Standard pragma once declaration
#include "ofMain.h" //openFrameworks objects & library

class Projectile { //Projectile class prototype
public: //public methods, variables
	float x, y; //the x and y of the projectile in the game
	bool isRedPublic, isLeftPublic; //whether or not the projectile is red, and whether or not it is traveling left
	ofImage projectileImage; //the projectile's image

	Projectile(bool isRed, bool isLeft, float _x, float _y);

	void setup(bool isRed, bool isLeft, float _x, float _y);
	void update();
	ofImage getImage();

	float getX();
	float getY();

	void setX(float &_x);
	void setY(float &_y);
};