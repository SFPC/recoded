
#include "runchalMolnar.h"

void runchalMolnar::setup(){
  
// setup pramaters
// if your original code use an ofxPanel instance dont use it here, instead
// add your parameters to the "parameters" instance as follows.
// param was declared in runchalMolnar.h
    //parameters.add(param.set("param", 5, 0, 100));
//    ofBackground(250);
    parameters.add(emotion.set("emotion", 0.5,0,20));
    parameters.add(height.set("height",10,5,30));
    parameters.add(width.set("width",50,10,100));
    parameters.add(length.set("length",10,1,30));

    setAuthor("Amit Runchal");
    setOriginalArtist("Vera Molnar");
    loadCode("scenes/runchalMolnar/exampleCode.cpp");
	
	    /*TO DO
     * MAKE THE WIDTH AND HEIGHT FOLLOW BETTER STROKE RULES
     * TRY TO BOUND HOW MUCH EMOTION INTERFERES WITH THE PREVIOUS LETTERS?
     * FIX STROKE LENGTH
     */
    
    //it's in reproducing the art that I realize that I am about to get my ass kicked and that the work I need to focus on is my emotional state of being and how attempting to reproduce mastery makes me feel
    
    //how do I feel about the piece currently? Its still not human enough
    
    


	
}

void runchalMolnar::update(){
    
}

void runchalMolnar::draw(){
	ofSeedRandom(0); // put this in to fix the emotional scale of response
    ofBackground(255);
    ofSetColor(0);
    float vertSpacer = 40;
    
    //line drawing
    
    for (int h = 0; h < 40; h++){
        ofPolyline myLine;
        for (int i = 0; i < 80; i++){
            
//            float yDown = ofRandom(20,40);
            float yDown = ofRandom(height);
            float yUp = ofRandom(20);
            float xForward = ofRandom(width);
            float xBack = ofRandom(10);
            
            //what this is does is take a percentage of the range to map and create more chaos later in the function. Is this linear?
//            float pct = ofMap(i, 0, 20, 0, 1); //the more the second value is increased, the more controlled this gets
            
            float pct = ofMap(i*(h*500*0.01), 0, 1000, 0, 1); //the more the second value is increased, the less jagged the line gets
            
            if (i % 2 == 0){
//                float x = 10 + i * 20 + ofRandom(-pct*10, pct*10);//                float x = 60 + i * 20 + ofRandom(-pct*10, pct*10); // this is before i made a param for emotion. It created sort of an effect where the program got more emotional the more they were writing to you
                float x = xBack + i * length + ofRandom(-emotion*10*h*0.3, emotion*10*h*0.3);
                // one thing with this param being coded in this way is that it makes the emotional state of the piece constant — it is more a reflection of mental health than it is of an emotional response to a person which grows stronger over time
                float y = -yDown + (i*0) + h * vertSpacer;
                myLine.addVertex(x,y);
            } else {
//                float x = 60 + i * 20 + ofRandom(-pct*10, pct*10); // this is before i made a param for emotion. It created sort of an effect where the program got more emotional the more they were writing to you
                float x = xBack + xForward + i * length + ofRandom(-emotion*10*h*0.3, emotion*10*h*0.3); // one thing with this param is that it makes the emotional state of the piece constant — it is more a reflection of mental health than it is of an emotional response to a person which grows stronger over time
                float y = yDown + (i*0) +  h * vertSpacer;
                myLine.addVertex(x,y);
            }
        myLine.draw();
        }
    }
}
