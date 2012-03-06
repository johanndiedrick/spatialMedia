//
//  smObject.cpp
//  spatialMediaTest
//
//  Created by Jared Schiffman on 2/23/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "smImage.h"
#include "smObject.h"

smObject::smObject( int _ID )
{
    ID = _ID;
     totalPixels = 0;
    //int midPixel = 0;
     totalX = 0;
     totalY = 0;
    
    lowestX = 0;
     highestX = 320;
     lowestY = 0;
      highestY = 240;

}

void    smObject::acceptPixel( int x, int y )
{
    
    //add 1 to total number of pixels for every pixel of a particular label   
    totalPixels++;
    
    totalX = x + totalX;
    totalY = y + totalY;
    
    if(x>highestX) {
        highestX = x;
    }
    if(x<lowestX){
        lowestX = x;   
    }
    if(y>highestY){ 
        highestY = y;
    }
    if(y<lowestY){
        lowestY = y;
    }
   
    
    

    
    
}








