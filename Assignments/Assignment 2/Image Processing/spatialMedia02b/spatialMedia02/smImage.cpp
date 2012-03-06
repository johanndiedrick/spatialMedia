//  smImage.cpp
//  spatialMedia


#include <iostream>
#include "smImage.h"
#include "poSimpleDrawing.h"
#include "poApplication.h"


smImage::smImage( const char* fileName, int W, int H )
{  
    // set the image width and height
    width = W;
    height = H;
    
    // load in the image data from file
    FILE* F = fopen( fileName, "rb" );                  // open a file
    if ( F==NULL )
    {
        printf("ERROR: can't find file: %s\n", fileName );
        exit(0);
    }
    imageDataOriginal = new unsigned char [width*height]; //a duplicate copy of imageData that we never touch
    imageData = new unsigned char [ width*height ];     // allocate memory for the image
    

    fread( imageData, 1, width*height, F );             // read file date into the memory
    fclose( F );                                        // close the file
    
    for(int i=0; i<width*height; i++)
    {
        imageDataOriginal[i] = imageData[i];
    }
    
        // used for fastDraw method
    imageAsTexture = new poTexture( width, height, imageData, poTextureConfig(GL_LUMINANCE) );
}

int     smImage::getPixel( int x, int y )
{
    int index = x + y*width;                    // calculate the pixel index
    if ( index < 0 || index >= width*height )
    {
        printf("ERROR: getPixel out of bounds\n");
        return 0;
    }
    return imageData[index];                    // return the pixel
}

int  smImage::getOriginalPixel( int x, int y )
{
    int index = x + y*width;                    // calculate the pixel index
    if ( index < 0 || index >= width*height )
    {
        printf("ERROR: getPixel out of bounds\n");
        return 0;
    }
    return imageDataOriginal[index];                    // return the pixel
}


void smImage::original(){
    for(int i=0; i<width*height; i++){
        imageData[i] = imageDataOriginal[i];
    }
}



void    smImage::setPixel( int x, int y, int grayValue )
{
    int index = x + y*width;                    // calculate the pixel index
    if ( index < 0 || index >= width*height )
    {
        printf("ERROR: setPixel out of bounds\n");
        return 0;
    }
    imageData[index] = grayValue;               // set the pixel
}

void    smImage::draw()
{
    // this is an inefficent, but simple mode of drawing an image
    // we draw one rectangle for every pixel
    // use the fastDraw() method if you want something faster
    for( int x=0; x<width; x++ )
    {
        for( int y=0; y<height; y++ )
        {
            float grayValue = getPixel(x,y);            // get the gray value
            grayValue = grayValue / 255;                // convert from 0-255 to 0.0-1.0
            po::setColor( poColor( grayValue, grayValue, grayValue) );  // set the color
            po::drawFilledRect( x*5,y*5, 5, 5 );        // draw the "pixel" rectangle
        }
    }
}

void    smImage::fastDraw()
{
    // replace the image data int the texture
    imageAsTexture->replace( imageData );
    // draw the texture
    po::drawTexturedRect( imageAsTexture, poRect(0,500,500,-500) );
}


void smImage::drawOriginal(){
    for(int x=0; x<width; x++){
        for (int y=0; y<height;y++)
        {
            float grayValue = getPixel(x,y);
            float newGrayValue = getOriginalPixel(x, y);
            setPixel(x,y,newGrayValue);
        }
    }
}

void smImage::invert(){
    original();
    for(int x=0; x<width; x++){
        for (int y=0; y<height;y++)
    {
        float grayValue = getPixel(x,y);
        float newGrayValue = 255 - grayValue;
        setPixel(x,y,newGrayValue);
        }
    }
}

//work on
void smImage::flipVertical(){
    original();
    for(int x=0; x<width; x++){
        for (int y=0;y<height;y++){
            
          //  float grayValue = getPixel(x,y);
            float flipValue = getOriginalPixel(x,height-y-1);
            setPixel(x,y,flipValue);
            
        }
    }
}


void smImage::blackandwhite(){
    original();
    for(int x=0; x<width; x++){
        for (int y=0; y<height; y++){
            float grayValue=getPixel(x,y);
            
            if(grayValue>255/2){
                setPixel(x,y,255);
            }
            
               else setPixel(x,y,0);
            
        }
    }
}

//work on
void smImage::threshold(int T){
    
    original();
    
    int threshold = T;
    printf("%d \n", threshold);
    for(int x=0; x<width-1; x++){
        for (int y=0;y<height-1;y++){
            float grayValue=getPixel(x,y);
            if(grayValue>threshold){
                setPixel(x,y,255);
            }
            else setPixel(x,y,0);
            
        }
    }
}

void smImage::edgeDetect(int T){
    
    int threshold = T;
   
    for(int x=0; x<width-1; x++){
        for(int y=0;y<height-1;y++){
            
            float grayValue = getPixel(x, y);
            float grayValueToRight = getPixel(x+1, y+1);
            
            if (grayValue - grayValueToRight > threshold){
                setPixel(x,y,0);
            }
            else setPixel(x,y,255);
            }
            
            }
        
    
    
    //printf("%d \n", threshold);
}




