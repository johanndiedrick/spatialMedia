/////////////////////////////////////////
//
// pocode application configuration
//
/////////////////////////////////////////


#include "poApplication.h"
#include "spatialMedia02App.h"

poObject *createObjectForID(uint uid) {
	return new spatialMedia02App();
}

void setupApplication() {
	applicationCreateWindow(0, WINDOW_TYPE_NORMAL, "spatialMedia02", 100, 100, 1200, 800);
}

void cleanupApplication() {
}