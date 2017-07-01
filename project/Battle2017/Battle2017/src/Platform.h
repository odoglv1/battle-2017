#pragma once
#include "ofMain.h"

class Platform {
public:
	float x, y, i;
	ofImage platformImage;

	Platform();

	void setup(float _x, float _y);
	void update();
	ofImage getImage();

	float getX();
	float getY();
};