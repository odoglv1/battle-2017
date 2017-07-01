#include "Fighter.h"
#include "ofMain.h"

Fighter::Fighter(bool isRed) {
	if (isRed) {
		stationaryR.load("right/redStationary.png");
		punchR.load("right/redPunching.png");
		stationaryL.load("left/redStationary.png");
		punchL.load("left/redPunching.png");

		x = 924;
		y = 350;
	}
	else {
		stationaryR.load("right/blueStationary.png");
		punchR.load("right/bluePunching.png");
		stationaryL.load("left/blueStationary.png");
		punchL.load("left/bluePunching.png");

		x = 100;
		y = 350;
	}

	isRedPublic = isRed;

	health = 50;
}

void Fighter::setup(bool isRed) {
	gravity = 0;
	jumping = false;

	if (isRed) {
		stationaryR.load("right/redStationary.png");
		punchR.load("right/redPunching.png");
		stationaryL.load("left/redStationary.png");
		punchL.load("left/redPunching.png");

		x = 824*2;
		y = 250;
	}
	else {
		stationaryR.load("right/blueStationary.png");
		punchR.load("right/bluePunching.png");
		stationaryL.load("left/blueStationary.png");
		punchL.load("left/bluePunching.png");

		x = 100;
		y = 200;
	}

	isRedPublic = isRed;

	health = 50;
}

void Fighter::update() {
	if (movingR) {
		x += 30;
		didLastMoveLeft = false;
	}
	else if (movingL) {
		x -= 30;
		didLastMoveLeft = true;
	}

	if (punchingR) {

	}
	else if (punchingL) {

	}

	if (jumping) {
		y += jumpAcceleration;
		jumpAcceleration += 1;
		if (jumpAcceleration >= 0) {
			jumping = false;
		}
	}

	if (getImage().getHeight() + y > ofGetWindowHeight() - 64) { //if below ground
		y = ofGetWindowHeight() - 64 - getImage().getHeight();
		gravity = 0;
	}
	if (getImage().getHeight() + y < ofGetWindowHeight() - 64) { //if jumping
		gravity += 2;
	}
	if (getImage().getHeight() + y == ofGetWindowHeight() - 64) { //if on ground
		gravity = 0;
		jumpAcceleration = 0;
	}

	y += gravity;
}

ofImage Fighter::getImage() {
	ofImage nowImage;

	if (movingR) {
		nowImage = stationaryR;
	}
	else if (movingL) {
		nowImage = stationaryL;
	}

	else if (punchingR || projingR) {
		nowImage = punchR;
	}
	else if (punchingL || projingL) {
		nowImage = punchL;
	}
	else {
		if (!didLastMoveLeft) {
			nowImage = stationaryR;
		}
		else if (didLastMoveLeft) {
			nowImage = stationaryL;
		}
	}

	return nowImage;
}

float Fighter::getX() {
	return x;
}

float Fighter::getY() {
	return y;
}

void Fighter::setJumping(bool _jump) {
	if (_jump && !jumping) {
		jumping = _jump;
		jumpAcceleration = -60;
	}
	else {

	}
}