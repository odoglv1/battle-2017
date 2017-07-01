#pragma once
#include "ofMain.h"

class Fighter {
public:
	bool movingR, movingL, punchingR, punchingL, projingR, projingL, isRedPublic, jumping, canMelee, didLastMoveLeft;
	ofImage stationaryR, stationaryL, punchR, punchL;
	float x, y, gravity, jumpAcceleration, health;

	//Fighter();
	Fighter(bool isRed);

	void setup(bool isRed);
	void update();
	ofImage getImage();
	float getX();
	float getY();
	
	void setJumping(bool _jump);
};