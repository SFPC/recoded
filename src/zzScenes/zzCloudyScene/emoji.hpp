//
//  emoji.hpp
//  cloudZZRecode1
//
//  Created by Ann Kidder on 11/13/17.
//
//

#ifndef emoji_hpp
#define emoji_hpp

#include <stdio.h>
#include "ofMain.h"

class Emoji {
    public:
    
    void setup(int x_start, int y_start, ofImage * icon);
    void update();
    void draw();
    
    float x_start;
    float y_val;
    float creation_time;
    
    float emojiSpeed;
    float emojiSize;
    
    float randomOffset;
    float randomSpeed;
    
    ofImage * img;
    Emoji();
};

#endif /* emoji_hpp */
