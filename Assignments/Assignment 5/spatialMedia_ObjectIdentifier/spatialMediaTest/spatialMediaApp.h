
#include "poObject.h"
#include "smImage.h"
#include "smObject.h"


class spatialMediaApp : public poObject {
public:
	spatialMediaApp();
	virtual ~spatialMediaApp();
	
    virtual void update();
    
    virtual void draw();
	
    virtual void eventHandler(poEvent *event);
	
    virtual void messageHandler(const std::string &msg, const poDictionary& dict=poDictionary());
    
    
    smImage*    image1;
    smImage*    image2;
    smImage*    image3;
    
    smImage*    sourceImage;
    smImage*    labelImage;
    
    float       mouseX, mouseY;
    char        lastKeyDown;
    
    void        processImage();
    bool        seedFill( int x, int y, int label );

    std::vector< smObject* >    objectSet;
};















