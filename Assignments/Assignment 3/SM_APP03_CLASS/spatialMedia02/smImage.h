
//  smImage.h
//  spatialMedia

#ifndef spatialMedia_smImage_h
#define spatialMedia_smImage_h

#include "poTexture.h"

class smImage
{
public:
    // the image constructor
    smImage( const char* fileName, int W, int H );
    smImage( int W, int H );
    
    // draw image methods
    void    draw();
    void    fastDraw( float x, float y );
    
    // get and set pixel methods
    int     getPixel( int x, int y );
    void    setPixel( int x, int y, int grayValue );
    
    // something there?
    bool isSomethingThere;
    bool somethingThere(int x0, int y0, int x1, int y1);
    
    // image data variables
    int             width, height;
    unsigned char*  imageData;

    // this poTexture is used for the fastDraw method
    poTexture*      imageAsTexture;
};


#endif
