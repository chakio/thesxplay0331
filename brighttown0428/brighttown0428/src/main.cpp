#include "ofMain.h"
#include "ofApp.h"

//========================================================================

int main( ){
	int winWidth = 3200;
	int winHight = 1800;
	
	ofSetupOpenGL(winWidth, winHight, OF_FULLSCREEN);
	
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	
	ofRunApp(new ofApp());

}
