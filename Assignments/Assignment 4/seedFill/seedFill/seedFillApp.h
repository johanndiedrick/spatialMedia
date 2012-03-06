/*	Created by Johann Diedrick on 2/18/12.
 *	Copyright 2012 __MyCompanyName__. All rights reserved.
 */

#include "poObject.h"
#include "smImage.h"
#include "poTextBox.h"

class seedFillApp : public poObject {
public:
	seedFillApp();
	virtual ~seedFillApp();
	
    virtual void update();
    
    virtual void draw();
	
    virtual void eventHandler(poEvent *event);
	
    virtual void messageHandler(const std::string &msg, const poDictionary& dict=poDictionary());
    
    char lastKeyDown;
    
    smImage* myImage1;
    smImage* myImage2;
    smImage* myImage3;
    
    smImage* labelImage;
    
    int colorLabel;
        
    poTextBox* B;

   
};

