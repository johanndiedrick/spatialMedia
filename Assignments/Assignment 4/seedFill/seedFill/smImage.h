//
//  smImage.h
//  seedFill
//
//  Created by Johann Diedrick on 2/18/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef seedFill_smImage_h
#define seedFill_smImage_h

#include "poTexture.h"

class smImage{
  
public:
    //the image constructor
    smImage( const char* fileName, int W, int H);
    smImage( int W, int H);
    
    //draw image methods
    void fastDraw( float x, float y);
    
    //get and set pixel methods
    int getPixel( int x, int y);
    void setPixel( int x, int y, int grayValue);
    
    int width;
    int height;
    unsigned char* imageData;
    
    //poTexture used for the fastDraw method
    poTexture* imageAsTexture;
    
    int grayLabel;
    int colorLabel;
   
    bool seedFill(int x, int y, smImage* labelImage, int colorLabel);
   
    };

#endif
