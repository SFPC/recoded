#include "ofxPoissonDiskSampling.h"
#include "bluenoise.h"

vector<float> ofxPoissonDiskSampling::sample1D(float w, float density, bool borders) {
    vector<float> result;

    // create positions
    {
        vector<Vec<1,float>> found;
        bluenoise_sample(density, Vec<1,float>(density), Vec<1,float>(w - density), found);

        for(auto v : found) {
            result.push_back(v[0]);
        }
    }

    if(borders) {
        // create border positions
        result.push_back(0);
        result.push_back(w);
    }

    return result;
}

vector<ofVec2f> ofxPoissonDiskSampling::sample2D(float w, float h, float density, bool borders, int *bordersStart) {
    vector<ofVec2f> result;

    // create positions
    {
        vector<Vec<2,float>> found;
        bluenoise_sample(density, Vec<2,float>(density,density), Vec<2,float>(w - density,h - density), found);

        for(auto v : found) {
            result.push_back(ofVec2f(v[0],v[1]));
        }
    }

    if(borders) {
        if(bordersStart != NULL)
            *bordersStart = result.size();

        // create border positions
        {
            for(int i=0; i<w/density; ++i) {
                result.push_back(ofVec2f(i * density, 0));
                result.push_back(ofVec2f(i * density, h));
            }

            for(int i=0; i<h/density; ++i) {
                result.push_back(ofVec2f(0, i * density));
                result.push_back(ofVec2f(w, i * density));
            }
        }
    }

    return result;
}

vector<ofVec3f> ofxPoissonDiskSampling::sample3D(float w, float h, float d, float density, bool borders, int *bordersStart) {
    // ofLogNotice("ofxPoissonDiskSampling", "start sampling");
    vector<ofVec3f> result;

    // create positions
    {
        vector<Vec<3,float>> found;
        float xmaxX = w - density; 
        float xmaxY = h - density; 
        float xmaxZ = d - density;
        bool densityTooLarge = false;
        if(xmaxX < density + 1) { xmaxX = density + 1; densityTooLarge = true; }
        if(xmaxY < density + 1) { xmaxY = density + 1; densityTooLarge = true; }
        if(xmaxZ < density + 1) { xmaxZ = density + 1; densityTooLarge = true; }
        // ofLogNotice("ofxPoissonDiskSampling", "presample (%f %f %f) (%f %f %f) %f", w, h, d, xmaxX, xmaxY, xmaxZ, density);
        if(densityTooLarge)
            ofLogWarning("ofxPoissonDiskSampling", "density too large (or dimensions too small to actually get samples");
        
        bluenoise_sample(density, Vec<3,float>(density,density,density), Vec<3,float>(xmaxX,xmaxY,xmaxZ), found);
        // ofLogNotice("ofxPoissonDiskSampling", "postsample");

        for(auto v : found) {
            result.push_back(ofVec3f(v[0],v[1],v[2]));
        }
        // ofLogNotice("ofxPoissonDiskSampling", "added samples");
    }
    // ofLogNotice("ofxPoissonDiskSampling", "created positions");

    if(borders) {
        // ofLogNotice("ofxPoissonDiskSampling", "borders");
        if(bordersStart != NULL)
            *bordersStart = result.size();

        // create border positions
        result.push_back(ofVec3f(0,0,0));
        result.push_back(ofVec3f(w,0,0));
        result.push_back(ofVec3f(0,h,0));
        result.push_back(ofVec3f(0,0,d));
        result.push_back(ofVec3f(w,h,0));
        result.push_back(ofVec3f(w,h,d));

        // boundary positions
        vector<Vec<2,float>> foundBorders;
        bluenoise_sample(density, Vec<2,float>(0,0), Vec<2,float>(w,h), foundBorders); result.reserve(result.size() + foundBorders.size());
        for(auto v : foundBorders) result.push_back(ofVec3f(v[0],v[1],0));

        foundBorders.clear();
        bluenoise_sample(density, Vec<2,float>(0,0), Vec<2,float>(w,h), foundBorders);
        for(auto v : foundBorders) result.push_back(ofVec3f(v[0],v[1],d));

        foundBorders.clear();
        bluenoise_sample(density, Vec<2,float>(0,0), Vec<2,float>(w,d), foundBorders);
        for(auto v : foundBorders) result.push_back(ofVec3f(v[0],0,v[1]));
        foundBorders.clear();
        bluenoise_sample(density, Vec<2,float>(0,0), Vec<2,float>(w,d), foundBorders);
        for(auto v : foundBorders) result.push_back(ofVec3f(v[0],h,v[1]));

        foundBorders.clear();
        bluenoise_sample(density, Vec<2,float>(0,0), Vec<2,float>(h,d), foundBorders);
        for(auto v : foundBorders) result.push_back(ofVec3f(0, v[0],v[1]));
        foundBorders.clear();
        bluenoise_sample(density, Vec<2,float>(0,0), Vec<2,float>(h,d), foundBorders);
        for(auto v : foundBorders) result.push_back(ofVec3f(w, v[0],v[1]));
    }

    return result;
}
