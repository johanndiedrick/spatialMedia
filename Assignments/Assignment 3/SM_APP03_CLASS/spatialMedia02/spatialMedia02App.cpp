

#include "spatialMedia02App.h"
#include "poApplication.h"
#include "poCamera.h"
#include "poShapeBasics2d.h"
#include "poTextBoxLayout.h"
#include "poSimpleDrawing.h"

using namespace std;
#include <iostream>

// APP CONSTRUCTOR. Create all objects here.
spatialMedia02App::spatialMedia02App() {
	addModifier(new poCamera2D(poColor::black));
    
    // register for mouse and key events
    addEvent( PO_MOUSE_MOVE_EVENT, this );
    addEvent( PO_KEY_DOWN_EVENT, this );

    // make a new smImage
    myImage1 = new smImage( "ladder_background.raw", 400, 300 );
    
    myImage2 = new smImage( "ladder_foreground.raw", 400, 300 );
    
    myImage4 = new smImage( "bottle_background.raw", 400, 300 );
    
    myImage5 = new smImage( "bottle_foreground.raw", 400, 300 ); 
    
    myImage6 = new smImage( "model_background.raw", 400, 300 );
    
    myImage7 = new smImage( "model_foreground.raw", 400, 300 ); 
    
    myImage3 = new smImage( 400,300 );
    
    //threshold = 20;
    //isSomethingThere = true;
    
    
    //stringstream for passing mouse position to textbox
    stringstream s;
    s << "Threshold: " << threshold << "\nIs Something There?: " << isSomethingThere;
    
    B = new poTextBox(280, 120);
	B->setText(s.str());	// Set the text
	B->setTextAlignment(PO_ALIGN_TOP_RIGHT);			// Set the text alignment within the text box
	B->setFont( poGetFont("Helvetica", "Bold") );		// Set the font to Helvetica Bold
	B->setTextSize(22);									// Set the text size
	//B->textColor = poColor::blue;						// Set the text color
	B->doLayout();										// Always call doLayout() after you make any change
	B->drawBounds = false;								// Show the bounds of the text box
	B->position.set(100, 500, 0);
	addChild( B );
    
    
    
}

// APP DESTRUCTOR. Delete all objects here.
spatialMedia02App::~spatialMedia02App() {
}

// UPDATE. Called once per frame. Animate objects here.
void spatialMedia02App::update() {
	
    threshold = (mouseX/getWindowWidth()*255);
    
    for(int x=0; x<400; x++){
        for (int y=0; y<300; y++){
            
            int backgroundPix = myImage1->getPixel(x, y);
            int foregroundPix = myImage2->getPixel(x, y);
            
            if(foregroundPix - backgroundPix > threshold){
                myImage3->setPixel(x, y, 255);
            }
            else myImage3->setPixel(x, y, 0);
            
        }
    }

    //isSomethingThere = myImage3->somethingThere(125,125,75,10);

    if(lastKeyDown=='1'){
    for(int x=0; x<400; x++){
        for (int y=0; y<300; y++){
            
           int backgroundPix = myImage1->getPixel(x, y);
            int foregroundPix = myImage2->getPixel(x, y);
            
            if(foregroundPix - backgroundPix > threshold){
                myImage3->setPixel(x, y, 255);
            }
            else myImage3->setPixel(x, y, 0);
                
            }
        }
        
        isSomethingThere = myImage3->somethingThere(125,125,75,10);

    }
    
    if(lastKeyDown=='2'){
        
        for(int x=0; x<400; x++){
            for (int y=0; y<300; y++){
                
                int backgroundPix = myImage4->getPixel(x, y);
                int foregroundPix = myImage5->getPixel(x, y);
                
                if(foregroundPix - backgroundPix > threshold){
                    myImage3->setPixel(x, y, 255);
                }
                else myImage3->setPixel(x, y, 0);
                
            }
        }

        isSomethingThere = myImage3->somethingThere(175,175,25,15);

    }

    if(lastKeyDown=='3'){
        
        for(int x=0; x<400; x++){
            for (int y=0; y<300; y++){
                
                int backgroundPix = myImage6->getPixel(x, y);
                int foregroundPix = myImage7->getPixel(x, y);
                
                if(foregroundPix - backgroundPix > threshold){
                    myImage3->setPixel(x, y, 255);
                }
                else myImage3->setPixel(x, y, 0);
                
            }
        }
        isSomethingThere = myImage3->somethingThere(175,75,25,10);

    }

    
    
    stringstream s;
    s << "Threshold: " << threshold << "\nIs Something There?: " << isSomethingThere;
    
	B->setText(s.str());	// Set the text
	B->doLayout();


    }
    


// DRAW. Called once per frame. Draw objects here.
void spatialMedia02App::draw() {

    
    // draw the image
    myImage1->fastDraw(100,50);
    
    myImage2->fastDraw(600,50);
    
    myImage3->fastDraw(600,400);
    
    po::drawStrokedRect(725, 475, 75, 200);

    
    if(lastKeyDown=='1'){
        myImage1->fastDraw(100,50);
        
        myImage2->fastDraw(600,50);
        
        myImage3->fastDraw(600,400);
        
        po::drawStrokedRect(725, 475, 75, 200);

    }
    
    if(lastKeyDown=='2'){
        myImage4->fastDraw(100,50);
        
        myImage5->fastDraw(600,50);
        
        myImage3->fastDraw(600,400);
        
        po::drawStrokedRect(750, 500, 50, 125);


    }
    
    if(lastKeyDown=='3'){
        myImage6->fastDraw(100,50);
        
        myImage7->fastDraw(600,50);
        
        myImage3->fastDraw(600,400);
        
        po::drawStrokedRect(750, 425, 75, 200);
    }
    
   
}

// EVENT HANDLER. Called when events happen. Respond to events here.
void spatialMedia02App::eventHandler(poEvent *event) {
	
    if ( event->type == PO_MOUSE_MOVE_EVENT )
    {
        mouseX = event->globalPosition.x;
        mouseY = event->globalPosition.y;
        threshold = mouseX;
    }
    
    if ( event->type == PO_KEY_DOWN_EVENT )
    {
        lastKeyDown = event->keyChar;
    }
}

// MESSAGE HANDLER. Called from within the app. Use for message passing.
void spatialMedia02App::messageHandler(const std::string &msg, const poDictionary& dict) {
	
}





