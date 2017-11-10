
#include "niklasMorisawa.h"

void niklasMorisawa::setup(){
    
    
    setAuthor("Niklas May");
    setOriginalArtist("John Maeda");
    loadCode("scenes/niklasMorisawa/exampleCode.cpp");
    
    pattern.set("Mod", 2, 1, 10);
        parameters.add(pattern);
    remainder.set("Remainder", 1, 0, 1);
//        parameters.add(remainder);
    
    myRect.set(0, 0, 300, 100);
    myText.setup();
    myText.update();
    

}

void niklasMorisawa::update(){
    myText.update();

}

void niklasMorisawa::draw(){
//    ofSetBackgroundColor(240);
    ofSetColor(15);
    ofNoFill();
    
    
    ofPushStyle();
        ofSetColor(240);
        ofFill();
        ofDrawRectangle(dimensions);
    ofPopStyle();
    
    float frame = 0.95;
    float width = dimensions.width * frame;
    float height = dimensions.height * frame;
    ofTranslate((dimensions.width - width) * 0.5, (dimensions.height - height) * 0.5);
    

    
    float totalHeight = 0;
    float y = 0;
    
    int counter = 0;

    
    for (int i = 0; i < 9 ; i++) {
        float numElements ;
        if(numElements < 6){
            numElements += 1;
        }    if(numElements > 6){
            numElements /= 2;
        }

        float grid = width / numElements;
        float scale = grid / myText.bound1.getWidth();
        
        float x = 0;
        
        for (int j = 0; j < numElements; j++) {
            counter += 1;
            
            ofPushMatrix();
            // position in grid
            ofTranslate(x , y);
            
            //align top and left
            ofTranslate(scale * myText.bound1.getWidth() * 0.5,
                        scale * (myText.bound1.getHeight()*1.1) * 0.5);
            
            //draw from center and scale
            ofScale(scale, scale);
            ofTranslate(-myText.bound1.getWidth() * 0.5, -(myText.bound1.getHeight()*1.1) * 0.5);
            
            
            if(pattern == 1){
                myText.draw(counter % 2);
            }
            if(counter % pattern == remainder){
                myText.draw(counter % 2);

            }
            
            ofPopMatrix();
            
            x += scale * myText.bound1.getWidth();
        }
        y += scale * (myText.bound1.getHeight()*1.1);
        totalHeight += (myText.bound1.getHeight()*1.1) * scale;
        
        
    }

}



float function_DoubleExponentialSigmoid (float x, float a){
    float min_param_a = 0.0 + FLT_EPSILON;
    float max_param_a = 1.0 - FLT_EPSILON;
    a = ofClamp(a, min_param_a, max_param_a);
    a = 1-a;
    
    float y = 0;
    if (x<=0.5){
        y = (pow(2.0*x, 1.0/a))/2.0;
    }
    else {
        y = 1.0 - (pow(2.0*(1.0-x), 1.0/a))/2.0;
    }
    return y;
}




//---------------------------------------------------------------
void textSqueez::setup(){
    
    //    const std::string& _filename, int _fontSize, bool _bAntiAliased, bool _bFullCharacterSet, bool _makeContours, float _simplifyAmt, int _dpi
    
    myType.load("fonts/GT-America-Trial-Compressed-Bold.otf", 500, true, false, true);
    bound1.set(myType.getStringBoundingBox("HUMAN", 0, 0));
    
    //std::exit(0);
    
    word1.clear();
    word2.clear();
    vector<ofTTFCharacter> path1 = myType.getStringAsPoints("HUMAN");
    for(int i = 0; i < path1.size(); i++){
        word1.push_back(path1[i].getTessellation());
    }
    
    vector<ofTTFCharacter> path2 = myType.getStringAsPoints("BEING");
    for(int i = 0; i < path2.size(); i++){
        word2.push_back(path2[i].getTessellation());
    }
    
    startTime = ofGetElapsedTimef();
    durationS = 1;
    counter = 0;
    counter2 = 0;
    
    widthA = 1;
    widthB = 0.0;
    
}

//---------------------------------------------------------------
void textSqueez::update(){
    float elapsedTime = ofGetElapsedTimef() - startTime;
    float  pctS = elapsedTime / durationS;
    pctS = powf(pctS, .5);
    if(pctS > 0.99){
        startTime = ofGetElapsedTimef();
        counter += 1;
        pctS = 0;
    }

    cout << pctS << endl;
    if(pctS > 0.99){
        startTime = ofGetElapsedTimef();
        counter += 1;
        pctS = 0;
    }
    
    bound1.set(myType.getStringBoundingBox("HUMAN", 0, 0));
    bound2.set(myType.getStringBoundingBox("BEING", 0, 0));
    diffW1to2 = bound1.width / bound2.width;
    
    scaleA1 = ofMap((pctS-1) * widthA + pctS * widthB, -1, -0, 1, 0);
    

    scaleA2 = ofMap((pctS-1) * widthA + pctS * widthB, -1, -0, 0, 1);
    
    scaleB1 = ofMap((pctS-1) * widthA + pctS * widthB, -1, -0, 0, diffW1to2);
    scaleB2 = ofMap((pctS-1) * widthA + pctS * widthB, -1, -0, diffW1to2, 0);
    
    
}

//---------------------------------------------------------------
void textSqueez::draw(int counterIn){
    
    ofSetColor(15);
    
    
    counter += counterIn;
    cout << "cIn: " << counterIn << " c: " << counter << endl;

    ofTranslate(0, bound1.height);
//    if( counter % 2 == 0){

    if( counterIn % 2 == 0){
        ofPushMatrix();
        ofScale(scaleA1, 1);
        ofTranslate(-bound1.x, 0);
        for(int i = 0; i < word1.size(); i++){
            word1[i].draw();
        }
        ofPopMatrix();
        
        ofPushMatrix();
        ofTranslate(bound1.getWidth() * scaleA1, 0);
        ofScale(scaleB1, 1);
        ofTranslate(-bound2.x, 0);
        for(int i = 0; i < word2.size(); i++){
            word2[i].draw();
        }
        ofPopMatrix();
    }else{
        ofPushMatrix();
        ofScale(scaleB2, 1);
        //            myType.drawString("BEING", -bound2.x, 0);
        ofTranslate(-bound2.x, 0);
        for(int i = 0; i < word2.size(); i++){
            word2[i].draw();
        }
        
        ofPopMatrix();
        
        ofPushMatrix();
        ofTranslate(bound2.getWidth() * scaleB2, 0);
        ofScale(scaleA2, 1);
        //            myType.drawString("HUMAN", -bound2.x, 0);
        ofTranslate(-bound2.x, 0);
        for(int i = 0; i < word1.size(); i++){
            word1[i].draw();
        }
        
        ofPopMatrix();
    }
    
}
