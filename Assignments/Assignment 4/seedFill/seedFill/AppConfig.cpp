/////////////////////////////////////////
//
// pocode application configuration
//
/////////////////////////////////////////


#include "poApplication.h"
#include "seedFillApp.h"

poObject *createObjectForID(uint uid) {
	return new seedFillApp();
}

void setupApplication() {
	applicationCreateWindow(0, WINDOW_TYPE_NORMAL, "seedFill", 100, 100, 1024, 768);
}

void cleanupApplication() {
}