
#include "mattKnowlton.h"

void mattKnowlton::setup(){
    
    ofBackground(0);
    
    fbo.allocate(dimensions.width, dimensions.height, GL_RGBA);
    
    tileCount = 50;
    gridSize = dimensions.width/tileCount;
    numFlowers = tileCount * tileCount;
    
    
    //some path, may be absolute or relative to bin/data
    string path = "images/mattKnowlton/";
    ofDirectory dir(path);
    //only show png files
    dir.allowExt("png");
    //populate the directory object
    dir.listDir();
    
    //go through and print out all the paths
    for(int i = 0; i < dir.size(); i++){
        //ofLogNotice(dir.getName(i));
        
        std::stringstream ss;
        ss << "images/mattKnowlton/img" << i << ".png";
        std::string s = ss.str();
        
        ofImage tempimg;
        tempimg.load(s);
        
        imgs.push_back(tempimg);
    }
    
    // Load and resize all of the images
    ofRectangle imgRect(0,0,imgs[0].getWidth(), imgs[0].getHeight());
    ofRectangle visualsRect(0,0,dimensions.width, dimensions.height);
    imgRect.scaleTo(visualsRect, OF_SCALEMODE_FILL);
    
    for(int i=0; i<imgs.size(); i++){
        imgs[i].resize(imgRect.width, imgRect.height);
    }
  
    // setup parameters
    size.set("size", 5, 0, 25);
    parameters.add(size);
    colorshift.set("colorshift", 5, 0, imgs.size());
    parameters.add(colorshift);
    speed.set("speed", 5, 1, 20);
    parameters.add(speed);
    // Setup point grid and color grid
    int randomStart = int(ofRandom(0, imgs.size()));
    
    loadPoints();
    loadColors(imgs[randomStart]);


    
    setAuthor("Matthew Ortega");
    setOriginalArtist("Ken Knowlton");
    loadCode("scenes/mattKnowlton/exampleCode.cpp");
    
}

void mattKnowlton::update(){
    
    // Load colors to match select image via params
    loadColors(imgs[colorshift]);
    
    // Add flowers
    if (flowers.size() < numFlowers*4){
        for(int i=0; i<speed; i++){
            addFlowers();
        }
    }
    
    for (int i = 0 ; i<flowers.size(); i++) {
        flowers[i].update();
        
        if(flowers[i].isDead()){
            flowers.erase(flowers.begin()+i);
        }
    }
    
}

void mattKnowlton::draw(){
    fbo.begin();
    
    for (int i = 0 ; i<flowers.size(); i++) {
        flowers[i].draw();
    }
    fbo.end();
    
    fbo.draw(0,0);
}

//--------------------------------------------------------------
void mattKnowlton::addFlowers(){
    
    // Create a random point to specify the color and point in the grid it will be created at
    int randomPoint = (int)ofRandom(0, points.size());
    
    Flower tempFlower;
    tempFlower.setup(gridSize+size, colors[randomPoint], points[randomPoint].x, points[randomPoint].y);
    flowers.push_back(tempFlower);
    
}

//--------------------------------------------------------------
void mattKnowlton::loadColors(ofImage tempImage){
    
    // Clearing all the old colors when reloading
    colors.clear();
    
    // Loading colors into the vector to match each Vec2f point
    for (int x=0; x<=tileCount; x++){
        for (int y=0; y<=tileCount; y++){
            float posx = x * gridSize;
            float posy = y * gridSize;
            
            ofColor co = tempImage.getColor(posx, posy);
            colors.push_back(co);
            
        }
    }
    
}

//--------------------------------------------------------------
void mattKnowlton::loadPoints(){
    
    // Load all of the points int he grid
    for(int x=0; x<=tileCount; x++){
        for(int y=0; y<=tileCount; y++){
            float posx = x * gridSize;
            float posy = y * gridSize;
            
            ofVec2f point = ofVec2f(posx, posy);
            points.push_back(point);
        }
    }
}
