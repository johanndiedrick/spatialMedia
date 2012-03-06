//
//  smObject.h
//  spatialMediaTest
//
//  Created by Jared Schiffman on 2/23/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef spatialMediaTest_smObject_h
#define spatialMediaTest_smObject_h

#include "smImage.h"

class smObject
{
public:
    smObject( int _ID );
    
    void    acceptPixel( int x, int y );
    
    int     ID;
    
    int totalX;
    int totalY;
    
    int totalPixels;
    
    int midPixel;
    
    int lowestX;
    int  highestX;
    int  lowestY;
    int highestY;
    
  
};


#endif
