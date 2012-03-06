
#include "poObject.h"
#include "smImage.h"
#include "poTextBox.h"

class spatialMedia02App : public poObject {
public:
	spatialMedia02App();
	virtual ~spatialMedia02App();
	
    virtual void update();
    
    virtual void draw();
	
    virtual void eventHandler(poEvent *event);
	
    virtual void messageHandler(const std::string &msg, const poDictionary& dict=poDictionary());
    

    smImage*    myImage1;
    smImage*    myImage2;
    smImage*    myImage3;
    smImage*    myImage4;
    smImage*    myImage5;
    smImage*    myImage6;
    smImage*    myImage7;
    
    
    int         threshold;
    bool isSomethingThere;
    
    bool somethingThere();
  
    
    float       mouseX, mouseY;
    char        lastKeyDown;
    
    poTextBox* B;

};

