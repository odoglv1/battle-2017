#include "Projectile.h"
#include "ofMain.h"

Projectile::Projectile(bool isRed, bool isLeft, float _x, float _y) {
	this->isRedPublic = isRed;
	this->isLeftPublic = isLeft;

	if (isRed) {
		projectileImage.load("ext/redProjectile.png");
	}

	if (!isRed) {
		projectileImage.load("ext/blueProjectile.png");
	}

	this->x = _x;
	this->y = _y;
}

void Projectile::setup(bool isRed, bool isLeft, float _x, float _y) {
	this->isRedPublic = isRed;
	this->isLeftPublic = isLeft;

	if (isRed) {
		projectileImage.load("ext/redProjectile.png");
	}

	if (!isRed) {
		projectileImage.load("ext/blueProjectile.png");
	}

	this->x = _x;
	this->y = _y;
}

void Projectile::update() {
	if (isLeftPublic) {
		x -= 45;
	}
	else if (!isLeftPublic) {
		x += 45;
	}
}

ofImage Projectile::getImage() {
	return projectileImage;
}

float Projectile::getX() {
	//float& __x = x;
	return x;
}

float Projectile::getY() {
	//float& __y = y;
	return y;
}

void Projectile::setX(float &_x) {
	this->x = _x;
}

void Projectile::setY(float &_y) {
	this->y = _y;
}