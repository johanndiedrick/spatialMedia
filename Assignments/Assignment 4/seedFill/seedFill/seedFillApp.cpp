/*	Created by Johann Diedrick on 2/18/12.
 *	Copyright 2012 __MyCompanyName__. All rights reserved.
 */

#include "seedFillApp.h"
#include "poApplication.h"
#include "poCamera.h"
#include "smImage.h"
#include "poTextBoxLayout.h"


using namespace std;
#include <iostream>


// APP CONSTRUCTOR. Create all objects here.
seedFillApp::seedFillApp() {
	addModifier(new poCamera2D(poColor::black));
    
    addEvent(PO_KEY_DOWN_EVENT, this);
    
    myImage1 = new smImage("flood_fill_test_01.raw", 320, 240);
    myImage2 = new smImage("flood_fill_test_02.raw", 320, 240);
    myImage3 = new smImage("flood_fill_test_03.raw", 320, 240);
    labelImage = new smImage(320, 240);
    
    
    for (int x=0; x<labelImage->width; x++){
        for (int y=0; y<labelImage->height; y++){
            labelImage->setPixel(x,y,0);
        }
    }
    
    colorLabel = 50;
    
    stringstream s;

    B = new poTextBox(320, 240);
	B->setText(s.str());	// Set the text
	B->setTextAlignment(PO_ALIGN_BOTTOM_LEFT);			// Set the text alignment within the text box
	B->setFont( poGetFont("Helvetica", "Bold") );		// Set the font to Helvetica Bold
	B->setTextSize(22);									// Set the text size
	//B->textColor = poColor::blue;						// Set the text color
	B->doLayout();										// Always call doLayout() after you make any change
	B->drawBounds = false;								// Show the bounds of the text box
	B->position.set(getWindowWidth()-300, 50, 0);
	addChild( B );

    
    
    
}

// APP DESTRUCTOR. Delete all objects here.
seedFillApp::~seedFillApp() {
}

// UPDATE. Called once per frame. Animate objects here.
void seedFillApp::update() {
  
   
	
    if(lastKeyDown == '1'){
        for (int x=0; x<320; x++){
            for (int y=0; y<240; y++){
               // myImage1->seedFill(x,y, labelImage);
                if(myImage1->seedFill(x,y, labelImage, colorLabel)){
                    //grayLabel = grayLabel + 50;
                    colorLabel +=50;
                }
                
            }
        }
           
        stringstream s;
        s << "1 ";
        
        B->setText(s.str());	// Set the text
        B->position.set(getWindowWidth()-300, 50, 0);

        B->doLayout();
    
    }
    
    if(lastKeyDown == '2'){

      
        
        for (int x=0; x<320; x++){
            for (int y=0; y<240; y++){
                if(myImage2->seedFill(x,y, labelImage, colorLabel)){
                    colorLabel +=50;
                }
                
            }
        }
        
        stringstream s;
        s << "1 " << " 2 " << " 3 ";
        
        B->setText(s.str());	// Set the text
        B->position.set(getWindowWidth()-300, 0, 0);
        
        B->doLayout();
        
        
    }
    
    
    
    if(lastKeyDown == '3'){
        
        
        for (int x=0; x<320; x++){
            for (int y=0; y<240; y++){
                if(myImage3->seedFill(x,y, labelImage, colorLabel)){
                    colorLabel +=50;
                }
                
            }
        }
        
        stringstream s;

        s << "1 " << " 2 " << " 3 " << " 4 " << " 5 " << " 6 " << " 7 " << " 8 ";
        
        B->setText(s.str());	// Set the text
        B->position.set(getWindowWidth()-300, 100, 0);

        B->doLayout();
    }
    
    
    if(lastKeyDown == '4'){
        
        
        for (int x=0; x<labelImage->width; x++){
            for (int y=0; y<labelImage->height; y++){
                labelImage->setPixel(x,y,0);
            }
        }
        stringstream s;
        s << " ";
        
        B->setText(s.str());	// Set the text
        B->doLayout();
    
    }
    
    
    
}

// DRAW. Called once per frame. Draw objects here.
void seedFillApp::draw() {
    

    
    
    if(lastKeyDown == '1'){
        
       
        
    myImage1->fastDraw(100,50);    
    labelImage->fastDraw(600,50);
    }
    
    if(lastKeyDown == '2'){
        myImage2->fastDraw(100,50);    
        labelImage->fastDraw(600,50);
    }
  
    if(lastKeyDown == '3'){
        myImage3->fastDraw(100,50);    
        labelImage->fastDraw(600,50);
    }
	
}

// EVENT HANDLER. Called when events happen. Respond to events here.
void seedFillApp::eventHandler(poEvent *event) {
    
    if(event->type == PO_KEY_DOWN_EVENT){
        
        lastKeyDown = event->keyChar;
    }
    
    if(event->type == PO_KEY_UP_EVENT){
        lastKeyDown = 'x';
    }
	
}

// MESSAGE HANDLER. Called from within the app. Use for message passing.
void seedFillApp::messageHandler(const std::string &msg, const poDictionary& dict) {
	
}





