
#include "poObject.h"
#include "smImage.h"

class spatialMedia02App : public poObject {
public:
	spatialMedia02App();
	virtual ~spatialMedia02App();
	
    virtual void update();
    
    virtual void draw();
	
    virtual void eventHandler(poEvent *event);
	
    virtual void messageHandler(const std::string &msg, const poDictionary& dict=poDictionary());
    

    smImage*    myImage;
    
    float       mouseX, mouseY;
    char        lastKeyDown;
    
    int     T;

    
};

