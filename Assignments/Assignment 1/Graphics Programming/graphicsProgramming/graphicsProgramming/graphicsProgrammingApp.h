/*	Created by Johann Diedrick on 1/30/12.
 *	Copyright 2012 __MyCompanyName__. All rights reserved.
 */

#include "poObject.h"
#include "poTextBox.h"


class graphicsProgrammingApp : public poObject {
public:
	graphicsProgrammingApp();
	virtual ~graphicsProgrammingApp();
	
    virtual void update();
    
    virtual void draw();
	
    virtual void eventHandler(poEvent *event);
	
    virtual void messageHandler(const std::string &msg, const poDictionary& dict=poDictionary());
    
    //drawGrid1 and variables for part 1
    virtual void drawGrid1();
    int W;
    int H;
    
    //drawGrid2 and variables for part 2
    virtual void drawGrid2();
    int X;
    int Y;
    int initialX;
    int initialY;
    
    virtual void drawGrid3();
    
    //keydown events
    char keyDown ;
    
    //mouse events
    int mouseX, mouseY;
    
    int checkerboard;
    
    poTextBox* B;
    
};

