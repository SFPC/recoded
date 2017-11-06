//
//  HexagonTrack.h
//  john-whitney-matrix
//
//  Created by Ying Quan Tan on 9/30/17.
//

#ifndef HexagonTrack_h
#define HexagonTrack_h
#include "ofMain.h"

#define IsInvalidSpacing(x) (x < 0.0)
#define InvalidSpacing  -1.0

class HexagonTrack {
protected:
    float numItems; // float for easy division
    float count;
    float baseSize;


    ofPoint center;
    ofRectangle screenDimensions;

    HexagonTrack(ofRectangle screenDimensions) : screenDimensions(screenDimensions)  {
        numItems = 7;
        count = numItems - 1;
        baseSize = 50;
        spacingRatio = 0.26;
        center.set(screenDimensions.width/2, screenDimensions.height/2);
    }

    void drawShape(ofPoint location, float size) {
        ofPushMatrix();
        ofSetCircleResolution(6);
        ofTranslate(location.x, location.y);
        ofRotate(30);
        ofDrawCircle(0, 0, size);
        ofPopMatrix();
    }

    // Figures out the location of each point,
    virtual ofPoint location(float time) = 0;

    // and the spacing between each of the tracks
    virtual float spacing(float time, int i) {
        return defaultSpacing(time, i);
    }

    // Figures out the size of each hexagon
    virtual float size(float time, int i) {
        return baseSize;
    }

public:
    float spacingRatioMultiplier = 1.0;
    float spacingRatio;
    float absoluteTime = 0;
    float freezeTime = 2;
    float freezeDuration = TWO_PI;
    float lastFrame = 0;

    // draw the actual thing
    virtual void draw(float time) {

        float elapsed = time - lastFrame;
        lastFrame = time;

        float offset = time - freezeTime;
        if (time >= freezeTime && time < freezeTime+freezeDuration) {
            if (offset < HALF_PI) {
                elapsed *= cos(offset); //slowly reduce elapsedtime's contribution to 0
            } else if (freezeDuration - offset < HALF_PI) {
                //slowly ease elapsed time's contribution back up by evaluating cos(1.5pi) to cos(2pi)
                float lastPart = HALF_PI -(freezeDuration - offset);
                elapsed *= cos(PI + HALF_PI + lastPart);
            } else {
                elapsed = 0; //freeze time;
            }
        }
        absoluteTime += elapsed;

        for(int i = 0; i < numItems; i++) {
            float count = numItems - 1;
            float timeForIndex = spacing(absoluteTime, i);
            ofPoint t = location(timeForIndex);
            float shapeSize = size(timeForIndex, i);
            drawShape(t, shapeSize);
        }
    }

    // collapses the spacing from the 'default'
    float freezeSpacing(float time, int i, float target, float duration) {
        i = count - i;

        if (time >= target && time < target+duration) {
            return time + i * spacingRatio * invParabola((time - target) / duration);
        } else {
            return InvalidSpacing;
        }
    }

    // default spacing
    virtual float defaultSpacing(float time, int i) {
        i = count - i;
        return time + i * spacingRatio;
    }

    //utility functions
    float parabola(float x) {
        float k = 4.0;
        return pow( 4.0*x*(1.0-x), k);
    }

    float invParabola(float x) {
        return 1 - parabola(x);
    }

    float easeOut(float t) {
        return -1 * t*(t-2);
    };
};

class HexagonTrack1 : public HexagonTrack {
public:

    HexagonTrack1(ofRectangle dimens) : HexagonTrack(dimens) {}

    ofPoint location(float time) {
        // make time stop, and even go backwards
        float r = screenDimensions.width * .25; // ~ 200 - 300
        float x = center.x + r * sin(time * 3.0);
        float y = center.y + r * cos(time * 1.0);
        x += ofSignedNoise(time) * 20;
        y += ofSignedNoise(time) * 20;
        return ofPoint(x, y);
    }

    // and the spacing between each of the tracks
    float spacing(float time, int i) {
        spacingRatio = 0.40 * sin(ofGetElapsedTimef() * 0.2 + 0.1);
        spacingRatio *= spacingRatioMultiplier;

        return defaultSpacing(time, i);
    }

    float size(float time, int i) {
        return sin(time * 0.3) * 20 + baseSize + 40 * cos(i/(count) * HALF_PI);
    }
};

#endif /* HexagonTrack_h */
