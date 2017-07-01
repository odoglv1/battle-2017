#include "ofApp.h"
#include "Fighter.h"
#include "Platform.h"
#include <cmath>

//--------------------------------------------------------------
void ofApp::setup(){
	//ofSetWindowShape(1024*2, 768*2);
	ofSetFrameRate(60);

	//activeProjectiles = std::vector<Projectile> (0);

	//it = activeProjectiles.begin();

	//canProjectile = true;

	running = true;

	redProj = false;
	blueProj = false;

	minusOneRed.load("ext/minusOne.png");
	minusOneBlue.load("ext/minusOneBlue.png");
	redWins.load("ext/redWins.png");
	blueWins.load("ext/blueWins.png");
	backgroundImage.load("ext/sky.jpg");
	backgroundImage.resize(ofGetWindowWidth(), ofGetWindowHeight());
	red.setup(true);
	blue.setup(false);
	p1.setup(0, ofGetWindowHeight() - (64));
	ofSetWindowTitle("Battle2017");
}

//--------------------------------------------------------------
void ofApp::update(){
	if (running) {
		red.update();
		blue.update();
		p1.update();

			for (Projectile &p : activeProjectiles) {
				if (!(p.getX() < 0 || p.getX() + p.getImage().getWidth() > ofGetWindowWidth())) {
					//p.update();
					if (p.isLeftPublic) {
						float g = p.getX();
						float f = g - (60);
						p.setX(f);
						//std::cout << "UPDATED PROJECTILE - 60" << std::endl;
						//std::cout << p.getX() << " to " << p.getX() - (60) << std::endl;
					}
					else if (!p.isLeftPublic) {
						float g = p.getX();
						float f = g + (60);
						p.setX(f);
						//std::cout << "UPDATED PROJECTILE + 60" << std::endl;
						//std::cout << p.getX() << " to " << p.getX() - (60) << std::endl;
					}

					if (p.isRedPublic) {
						//TODO damage
					}
				}
				else {
					//p.shouldDelete = true;
				}
			}

			//activeProjectiles.erase(std::remove(activeProjectiles.begin(), activeProjectiles.end(), to_remove), activeProjectiles.end());

		backgroundImage.resize(ofGetWindowWidth(), ofGetWindowHeight());

		//Check collision
		if (red.getX() > blue.getX() && red.getX() < blue.getX() + blue.getImage().getWidth()) { //If red is colliding with blue
			if (std::abs(red.getY() - blue.getY()) < 5) { //If red and blue's heights are close enough together
				red.canMelee = true;
				blue.canMelee = true;
				//std::cout << "YES" << std::endl;
			}
		}
		if (blue.getX() > red.getX() && blue.getX() < red.getX() + red.getImage().getWidth()) { //If blue is colliding with red
			if (std::abs(blue.getY() - red.getY()) < 5) { //If blue and red's heights are close enough together
				red.canMelee = true;
				blue.canMelee = true;
				//std::cout << "YES" << std::endl;
			}
		}
		else if (!(blue.getX() > red.getX() && blue.getX() < red.getX() + red.getImage().getWidth()) && !(red.getX() > blue.getX() && red.getX() < blue.getX() + blue.getImage().getWidth())) {
			red.canMelee = false;
			blue.canMelee = false;
			red.punchingL = false;
			red.punchingR = false;
			blue.punchingL = false;
			blue.punchingR = false;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	//if (running) {
		glPolygonMode(GL_BACK, GL_FILL);
		backgroundImage.draw(0, 0);

		glPolygonMode(GL_FRONT, GL_FILL);
		red.getImage().draw(red.getX(), red.getY());
		blue.getImage().draw(blue.getX(), blue.getY());
		p1.getImage().draw(p1.getX(), p1.getY());

		if (showingDamage1 && damageLength1 < 30) {
			minusOneRed.draw(red.getX(), red.getY() - 15);
			damageLength1++;
		}

		if (showingDamage2 && damageLength2 < 30) {
			minusOneBlue.draw(blue.getX(), blue.getY() - 15);
			damageLength2++;
		}

		//if (redProj || blueProj) {
			for (Projectile &p : activeProjectiles) {
				if (!(p.getX() < 0 || p.getX() + p.getImage().getWidth() > ofGetWindowWidth())) {
					p.getImage().draw(p.getX(), p.getY());
				}
				//std::cout << "DRAWING!" << p.getX() << std::endl;
			}
		//}

		if (blueProj) {
			if (blue.didLastMoveLeft) {
				blue.projingL = true;
			}
			else if (!blue.didLastMoveLeft) {
				blue.projingR = true;
			}
		}
		else if (!blueProj) {
			blue.projingL = false;
			blue.projingR = false;
		}

		if (redProj) {
			if (red.didLastMoveLeft) {
				red.projingL = true;
			}
			else if (!red.didLastMoveLeft) {
				red.projingR = true;
			}
		}
		else if (!redProj) {
			red.projingL = false;
			red.projingR = false;
		}

	//}

		if (red.health <= 0) {
			//Blue wins!
			running = false;
			blueWins.draw(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
		}
		else if (blue.health <= 0) {
			//Red wins!
			running = false;
			redWins.draw(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
		}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 97 /*A*/) {
		blue.movingL = true;
	}
	if (key == 100 /*D*/) {
		blue.movingR = true;
	}
	if (key == 356 /*Left Arrow*/) {
		red.movingL = true;
	}
	if (key == 358 /*Right Arrow*/) {
		red.movingR = true;
	}
	/*if (key == 32) {
		red.setJumping(true);
		blue.setJumping(true);
	}*/
	if (key == 119 /*W*/) {
		blue.setJumping(true);
	}
	if (key == 357 /*Up Arrow*/) {
		red.setJumping(true);
	}
	if (key == 115 /*S*/) {
		if (blue.canMelee && running) {
			if (blue.didLastMoveLeft) {
				blue.punchingL = true;
				//std::cout << "YES" << std::endl;
				damageLength1 = 0;
				showingDamage1 = true;

				red.health -= 1;
			}
			else if (!blue.didLastMoveLeft) {
				blue.punchingR = true;
				//std::cout << "YES" << std::endl;
				damageLength1 = 0;
				showingDamage1 = true;

				red.health -= 1;
			}
			else {
				blue.punchingL = false;
				blue.punchingR = false;
			}
		}
		else {
			blue.punchingL = false;
			blue.punchingR = false;
		}
	}
	if (key == 359 /*Down Arrow*/) {
		if (red.canMelee && running) {
			if (red.didLastMoveLeft) {
				red.punchingL = true;
				damageLength2 = 0;
				showingDamage2 = true;

				blue.health -= 1;
			}
			else if (!red.didLastMoveLeft) {
				red.punchingR = true;
				damageLength2 = 0;
				showingDamage2 = true;

				blue.health -= 1;
			}
			else {
				red.punchingL = false;
				red.punchingR = false;
			}
		}
		else {
			red.punchingL = false;
			red.punchingR = false;
		}
	}
	if (key == 101 /*E*/ && running && !blueProj) {
		//std::cout << "CREATED NEW PROJECTILE" << std::endl;
		Projectile newP = Projectile(false, blue.didLastMoveLeft, blue.getX(), blue.getY() + (blue.getImage().getHeight() / 2));
		//newP.setX();
		//newP.setY();
		//newP.setup(false, blue.didLastMoveLeft, blue.getX(), blue.getY() + (blue.getImage().getHeight() / 2));
		activeProjectiles.push_back(newP);
		blueProj = true;
	}
	if (key == 2306 /*Right Shift*/ && running && !redProj) {
		Projectile newP = Projectile(true, red.didLastMoveLeft, red.getX(), red.getY() + (red.getImage().getHeight() / 2));
		//newP.setX();
		//newP.setY();
		//newP.setup(true, red.didLastMoveLeft, red.getX(), red.getY() + (red.getImage().getHeight() / 2));
		activeProjectiles.push_back(newP);
		redProj = true;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == 97 /*A*/) {
		blue.movingL = false;
	}
	if (key == 100 /*D*/) {
		blue.movingR = false;
	}
	if (key == 356 /*Left Arrow*/) {
		red.movingL = false;
	}
	if (key == 358 /*Right Arrow*/) {
		red.movingR = false;
	}
	if (key == 115 /*S*/) {
		blue.punchingL = false;
		blue.punchingR = false;
	}
	if (key == 359 /*Down Arrow*/) {
		red.punchingL = false;
		red.punchingR = false;
	}
	if (key == 101 && blueProj) {
		blueProj = false;
	}
	if (key == 2306 && redProj) {
		redProj = false;
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}