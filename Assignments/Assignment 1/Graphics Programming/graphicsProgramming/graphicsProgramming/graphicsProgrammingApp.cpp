/*	Created by Johann Diedrick on 1/30/12.
 *	Copyright 2012 __MyCompanyName__. All rights reserved.
 */

#include "graphicsProgrammingApp.h"
#include "poApplication.h"
#include "poCamera.h"
#include "poShapeBasics2D.h"
#include "poTextBoxLayout.h"

using namespace std;
#include <iostream>

// APP CONSTRUCTOR. Create all objects here.
graphicsProgrammingApp::graphicsProgrammingApp() {
	addModifier(new poCamera2D(poColor::black));
    
    addEvent(PO_KEY_DOWN_EVENT, this);
    addEvent(PO_MOUSE_MOVE_EVENT, this);
    
   
    
    //initialize keyDown and mouse position variables
    keyDown = '1';
    mouseX = 0;
    mouseY = 0;
    
    
    
    //w,h variables for drawGrid1 function
    W = 10;
    H=10;
    
    //x,y variables for drawGrid2 function
    X = 1;
    Y = 1;
    initialX = 0;
    initialY = 0;
    
    //switch variable for checkerboard colors
    checkerboard=1;
    
    //stringstream for passing mouse position to textbox
    stringstream s;
    s << "x: " << X << " y: " << Y;
    
    B = new poTextBox(280, 120);
	B->setText(s.str());	// Set the text
	B->setTextAlignment(PO_ALIGN_TOP_RIGHT);			// Set the text alignment within the text box
	B->setFont( poGetFont("Helvetica", "Bold") );		// Set the font to Helvetica Bold
	B->setTextSize(22);									// Set the text size
	B->textColor = poColor::blue;						// Set the text color
	B->doLayout();										// Always call doLayout() after you make any change
	B->drawBounds = false;								// Show the bounds of the text box
	B->position.set(getWindowWidth()-300, 50, 0);
	addChild( B );

    
    
    
}

// APP DESTRUCTOR. Delete all objects here.
graphicsProgrammingApp::~graphicsProgrammingApp() {
}

// UPDATE. Called once per frame. Animate objects here.
void graphicsProgrammingApp::update() {
	
}

// DRAW. Called once per frame. Draw objects here.
void graphicsProgrammingApp::draw() {
    
    if(keyDown == '1') {
    
        drawGrid1();
    }
    else if (keyDown == '3'){ drawGrid3();}
    
    else drawGrid2();
    
    printf("%d \n", mouseX);
    printf("%d \n", mouseY);
    //printf("%d \n", keyDown);
    
}

// EVENT HANDLER. Called when events happen. Respond to events here.
void graphicsProgrammingApp::eventHandler(poEvent *event) {
    
    if (event->type == PO_KEY_DOWN_EVENT)
    {
        keyDown = event->keyChar;
    }
    
    if(event->type == PO_MOUSE_MOVE_EVENT){
        mouseX = event->globalPosition.x;
        mouseY = event->globalPosition.y;
    }
    
	
}


// MESSAGE HANDLER. Called from within the app. Use for message passing.
void graphicsProgrammingApp::messageHandler(const std::string &msg, const poDictionary& dict) {
	
}

void graphicsProgrammingApp::drawGrid1(){
    
    
	for (int y=0; y<H;y++){
        for (int x=0; x<W; x++){
            
            if(mouseX>x*20 && mouseX <x*20+10 && mouseY>y*20 && mouseY < y*20+10){
                
                po::setColor(poColor::red);
            }
            else
                po::setColor(poColor::white);
            po::drawFilledRect(x*20, y*20, 10, 10);}
    }
}


void graphicsProgrammingApp::drawGrid2(){
    
    
    
    
    if (keyDown == 'w'){
        Y = Y - 1;
        initialY = initialY -1;
        keyDown='2';
    }
    
    if (keyDown == 's'){
        Y = Y + 1;
        initialY = initialY + 1;
        keyDown='2';
    }
    
    if (keyDown == 'a'){
        X = X - 1;
        initialX = initialX - 1;
        keyDown='2';
    }
    
    if (keyDown == 'd'){
        X = X + 1;
        initialX = initialX + 1;
        keyDown='2';
    }
    
    stringstream s;
    s << "x: " << X << " y: " << Y;
    
	B->setText(s.str());	// Set the text
	B->doLayout();
    
    
    
    for (int y=0; y<H;y++){
        for (int x=0; x<W; x++){
            
            
                po::setColor(poColor::white);
            po::drawFilledRect(x*20, y*20, 10, 10);}
    }

    
    for (int y = initialY; y<Y;y++){
        for (int x = initialX; x<X; x++){
            po::setColor(poColor::red);
            po::drawFilledRect(x*20, y*20, 10, 10);}
    }
    
    
}



void graphicsProgrammingApp::drawGrid3(){
    
    
    for (int y=0; y<H;y++){
        checkerboard = -checkerboard;
        for (int x=0; x<W; x++){
            
            if (checkerboard==1){
                po::setColor(poColor::white);
            }
            else 
                po::setColor(poColor::red);
            checkerboard = -checkerboard;
            po::drawFilledRect(x*20, y*20, 10, 10);}
        
        
        
    }
    
    
    
}