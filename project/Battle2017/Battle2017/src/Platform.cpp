#include "Platform.h"
#include "ofMain.h"

Platform::Platform() {

}

void Platform::setup(float _x, float _y) {
	platformImage.load("ext/platform.png");
	platformImage.resize(ofGetWindowWidth(), platformImage.getHeight() / 3);

	x = _x;
	y = _y;
	i = 0;
}

void Platform::update() {
	if (i <= 60) {
		platformImage.resize(ofGetWindowWidth(), 500/3);

		y = ofGetWindowHeight() - (64);
		i++;
	}
}

ofImage Platform::getImage() {
	return platformImage;
}

float Platform::getX() {
	return x;
}

float Platform::getY() {
	return y;
}