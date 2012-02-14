/////////////////////////////////////////
//
// pocode application configuration
//
/////////////////////////////////////////


#include "poApplication.h"
#include "graphicsProgrammingApp.h"

poObject *createObjectForID(uint uid) {
	return new graphicsProgrammingApp();
}

void setupApplication() {
	applicationCreateWindow(0, WINDOW_TYPE_NORMAL, "graphicsProgramming", 100, 100, 1024, 768);
}

void cleanupApplication() {
}