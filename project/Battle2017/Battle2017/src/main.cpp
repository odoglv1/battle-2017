#include "ofMain.h" //openFrameworks objects & library
#include "ofApp.h" //the application itself

/*
C++ main method.

Initializes the openFrameworks GL context, and starts the application.

For some reason, return 0 breaks the app. So, don't add it in. Pray that the compiler will do it for you.
*/
int main(void){
	ofSetupOpenGL(1024*2,768*2,OF_FULLSCREEN);
	ofRunApp(new ofApp());
}