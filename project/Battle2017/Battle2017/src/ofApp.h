#pragma once //TODO: Remove this and replace it with an if/define/endif tag/statement.

#include "ofMain.h"
#include "Fighter.h"
#include "Platform.h"
#include "Projectile.h"

using std::vector;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		Fighter red = new Fighter(true);
		//Fighter redd = *red;
		Fighter blue = new Fighter(false);
		//Fighter blued = *blue;
		Platform p1 = Platform();
		//Platform p1d = *p1;
		ofImage backgroundImage;
		ofImage minusOneRed;
		ofImage minusOneBlue;
		ofImage redWins;
		ofImage blueWins;
		bool showingDamage1;
		int damageLength1;
		bool showingDamage2;
		int damageLength2;
		//bool canProjectile;
		bool running;
		bool redProj;
		bool blueProj;

		vector<Projectile> activeProjectiles;
		//std::vector<Projectile>::iterator it;

		//Projectile to_remove;
};