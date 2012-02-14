
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
    
    // draw image methods
    void    draw();
    void    fastDraw();
    
    // get and set pixel methods
    int     getPixel( int x, int y );
    void    setPixel( int x, int y, int grayValue );
    
    int getOriginalPixel(int x, int y);
    
    void original();
    
    void drawOriginal();
    
    //invert method
    void    invert();
    
    //flip vertical method
    void    flipVertical();
    
    //blackandwhite method
    void    blackandwhite();
    
    //threshold method
    void    threshold(int T);
    
    //edge detect method
    void    edgeDetect(int T);
    
    // image data variables
    int             width, height;
    unsigned char*  imageData;
    unsigned char*  imageDataOriginal;

    // this poTexture is used for the fastDraw method
    poTexture*      imageAsTexture;
};


#endif
