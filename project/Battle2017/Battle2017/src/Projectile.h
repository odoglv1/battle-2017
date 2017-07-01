#pragma once
#include "ofMain.h"

class Projectile {
public:
	float x, y;
	bool isRedPublic, isLeftPublic;
	ofImage projectileImage;

	Projectile(bool isRed, bool isLeft, float _x, float _y);

	void setup(bool isRed, bool isLeft, float _x, float _y);
	void update();
	ofImage getImage();

	float getX();
	float getY();

	void setX(float &_x);
	void setY(float &_y);
};