/////////////////////////////////////////
//
// pocode application configuration
//
/////////////////////////////////////////


#include "poApplication.h"
#include "spatialMediaApp.h"

poObject *createObjectForID(uint uid) {
	return new spatialMediaApp();
}

void setupApplication() {
	applicationCreateWindow(0, WINDOW_TYPE_NORMAL, "spatialMedia02", 100, 100, 1200, 800);
}

void cleanupApplication() {
}