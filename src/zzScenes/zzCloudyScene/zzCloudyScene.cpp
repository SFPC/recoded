
#include "zzCloudyScene.h"

void zzCloudyScene::setup(){
  
// setup pramaters
// if your original code use an ofxPanel instance dont use it here, instead
// add your parameters to the "parameters" instance as follows.
// param was declared in zzCloudyScene.h
    //parameters.add(param.set("param", 5, 0, 100));

    parameters.add(cloud_size.set("cloud size", 200, 50, 700));
    parameters.add(emojiSpeed.set("emoji speed", 4, 1, 10));
    parameters.add(jiggle.set("jiggle", .05, .05, .25));
    
    time = 0;
    y_fall = 0;
    
    
    
    setAuthor("Put Your Name Here");
    setOriginalArtist("Put the original Artist's name here");


    loadCode("zzScenes/zzCloudyScene/exampleCode.cpp");
    
    ofDirectory dir;
    dir.listDir("zzScenes/zzCloudyScene/images");
    for (int i = 0; i < dir.size(); i++){
        ofImage temp;
        icons.push_back(temp);
        icons.back().load(dir.getPath(i));
        
    }
}

void zzCloudyScene::update(){
    for (int i=0;i<my_emojis.size();i++){
        my_emojis[i].emojiSpeed = emojiSpeed;
        my_emojis[i].emojiSize = ofMap(cloud_size, 50, 700, 0.1, 0.5);
        my_emojis[i].update();
    }
}


// check whether emoji should be removed
bool emoji_out_of_range(Emoji emoji) {
    if (emoji.y_val > 1100){
        return true;
    } else {
        return false;
    }
}


void zzCloudyScene::draw(){
    
    ofBackground(255, 163, 224);
    // cloud variables
    int cloud_width = cloud_size;
    int cloud_height = cloud_width*.72;
    
    float center_x = dimensions.width/2;
    float center_y = cloud_height/2*1.3;
    
    int x_wiggle_low = -cloud_width*.06;
    int x_wiggle_hi = cloud_width*.06;
    
    int y_wiggle_low = -cloud_height*.03;
    int y_wiggle_hi = cloud_height*.03;
    
    // verticle bounce
    time += jiggle;
    ofSetCircleResolution(100);
    int y_off = center_y;
    y_off += cloud_height*.1*sin(getElapsedTimef());
    
    // check if new emoji should be created
    float timeSinceLastEmoji = getElapsedTimef() - lastCreationTime;
    
    if (timeSinceLastEmoji < 0) lastCreationTime =getElapsedTimef();
    
    
    creationDelay = ofMap(jiggle, 0.05, 0.25, 0.9, 0.03);
    
    
    if (timeSinceLastEmoji > creationDelay){
        total_emojis += 1;
        Emoji temp;
        int index = ofRandom(0,icons.size());
        temp.setup(center_x+ofRandom(-cloud_width/2*.9,cloud_width/2*.6), center_y, &icons[index]);
        temp.emojiSize = ofMap(cloud_size, 50, 700, 0.1, 0.5);
        my_emojis.push_back(temp);
        lastCreationTime = getElapsedTimef();
    }
    
    for (int i=0;i<my_emojis.size();i++){
        my_emojis[i].draw();
    }
    
    // draw the cloud
    ofDrawCircle(center_x - cloud_width*.075+ofMap(ofNoise(10+time*.8), 0, 1, x_wiggle_low, x_wiggle_hi),
                 y_off - cloud_height*.206+ofMap(ofNoise(1000+time*.8), 0, 1, y_wiggle_low, y_wiggle_hi),
                 cloud_width*.23);
    ofDrawCircle(center_x - cloud_width*.313+ofMap(ofNoise(20+time*.8), 0, 1, x_wiggle_low, x_wiggle_hi),
                 y_off - cloud_height*.041+ofMap(ofNoise(2000+time*.8), 0, 1, y_wiggle_low, y_wiggle_hi),
                 cloud_width*.16);
    ofDrawCircle(center_x - cloud_width*.096+ofMap(ofNoise(30+time*.8), 0, 1, x_wiggle_low, x_wiggle_hi),
                 y_off + cloud_height*.212+ofMap(ofNoise(3000+time*.8), 0, 1, y_wiggle_low, y_wiggle_hi),
                 cloud_width*.18);
    ofDrawCircle(center_x + cloud_width*.194+ofMap(ofNoise(40+time*.8), 0, 1, x_wiggle_low, x_wiggle_hi),
                 y_off - cloud_height*.162+ofMap(ofNoise(4000+time*.8), 0, 1, y_wiggle_low, y_wiggle_hi),
                 cloud_width*.15);
    ofDrawCircle(center_x + cloud_width*.309+ofMap(ofNoise(50+time*.8), 0, 1, x_wiggle_low, x_wiggle_hi),
                 y_off + cloud_height*.056+ofMap(ofNoise(5000+time*.8), 0, 1, y_wiggle_low, y_wiggle_hi),
                 cloud_width*.17);
    ofDrawCircle(center_x + cloud_width*.127+ofMap(ofNoise(60+time*.8), 0, 1, x_wiggle_low, x_wiggle_hi),
                 y_off + cloud_height*.132+ofMap(ofNoise(6000+time*.8), 0, 1, y_wiggle_low, y_wiggle_hi),
                 cloud_width*.15);
    ofDrawCircle(center_x + cloud_width*.138+ofMap(ofNoise(70+time*.8), 0, 1, x_wiggle_low, x_wiggle_hi),
                 y_off + cloud_height*.206+ofMap(ofNoise(7000+time*.8), 0, 1, y_wiggle_low, y_wiggle_hi),
                 cloud_width*.13);
    
    // remove emojis that fall below the display
    std::remove_if (my_emojis.begin(), my_emojis.end(), emoji_out_of_range);
    
}
