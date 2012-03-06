//
//  smImage.cpp
//  seedFill
//
//  Created by Johann Diedrick on 2/18/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "smImage.h"
#include "poSimpleDrawing.h"
#include "poApplication.h"
using namespace std;

smImage::smImage(const char* fileName, int W, int H){
    
    //set the image width and height
    width = W;
    height = H;
    colorLabel = 50;
    
    //load in the image data from file
    
    FILE* F = fopen(fileName, "rb"); //open a file
    if(F == NULL){
        printf("Error: can't find file: %s\n", fileName);
        exit(0);
    }
    
    imageData = new unsigned char [width*height]; //allocate memory for image
    
    fread(imageData, 1, width*height, F); //read file data into the memory
    
    fclose(F); // close the file
    
    imageAsTexture = new poTexture(width, height, imageData, poTextureConfig(GL_LUMINANCE));
    
    
}

smImage::smImage(int W, int H){
    
    //set the image width and height
    width = W;
    height = H;

    //load in the image data from file
    imageData = new unsigned char[width*height]; // allocate memory for the image
    memset(imageData, 255, width*height);
    
    //use for the fastDraw method
    imageAsTexture = new poTexture(width, height, imageData, poTextureConfig(GL_LUMINANCE));
}

int smImage::getPixel(int x, int y){
    
    int index = x + y*width; // calculate the pixel index
    
    //error condition if getPixel goes outside the boundaries of the image
    if(index < 0 || index>= width*height){
        printf("ERROR: getPixel out of bounds\n");
        return 0;
    }
    return imageData[index]; // return the pixel
}

void smImage::setPixel(int x, int y, int grayValue){
    int index = x + y*width; //calculate the pixel index
    
    //bounds check
    if(index<0 || index>=width*height){
        printf("ERROR: setPixel out of bounds\n");
        return 0;
    }
    
    imageData[index] = grayValue;
    
}

void smImage::fastDraw(float x, float y){
    
    //replace the image data in the texture
    imageAsTexture -> replace(imageData);
    
    //draw the texture
    po::drawTexturedRect(imageAsTexture, poRect(x+0,y+height, width,-height));
}




bool smImage::seedFill(int x, int y, smImage* labelImage, int colorLabel){
    
    printf("%d \n", colorLabel);
    
    if(getPixel(x,y) == 0){
        return false;
    }
    
    if(labelImage->getPixel(x,y) !=0){
        return false; //if its not black, that means we have already labeled it
    }
    
    labelImage->setPixel(x,y, colorLabel);
    seedFill(x+1, y, labelImage, colorLabel);
    seedFill(x-1, y, labelImage, colorLabel);
    seedFill(x, y+1, labelImage, colorLabel);
    seedFill(x,y-1, labelImage, colorLabel);

    return true;
}

