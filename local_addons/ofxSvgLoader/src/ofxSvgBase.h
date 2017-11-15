//
//  ofxSvgBase.h
//
//  Created by Nick Hardeman on 7/31/15.
//

#pragma once
#include "ofMain.h"
#include <map>

class ofxSvgBase {
public:
    enum Types {
        OFX_SVG_TYPE_GROUP = 0,
        OFX_SVG_TYPE_RECTANGLE,
        OFX_SVG_TYPE_IMAGE,
        OFX_SVG_TYPE_ELLIPSE,
        OFX_SVG_TYPE_CIRCLE,
        OFX_SVG_TYPE_PATH,
        OFX_SVG_TYPE_TEXT,
        OFX_SVG_TYPE_TOTAL
    };
    
    ofxSvgBase() { name = "No Name"; type = OFX_SVG_TYPE_TOTAL; setVisible( true ); }
    
    int getType() {return type;}
    string getTypeAsString();
    
    string getName() { return name; }
    virtual int getNumChildren() { return 0; }
    bool isGroup() {
        return (getType() == OFX_SVG_TYPE_GROUP);
    }
    
    void setVisible( bool ab ) { bVisible = ab; }
    bool isVisible() { return bVisible; }
    
    virtual void draw() {}
    
    virtual string toString(int nlevel = 0);
    
    string name;
    int type;
    bool bVisible;
    ofVec2f pos;
};

class ofxSvgElement : public ofxSvgBase {
public:
    
    ofxSvgElement() {scale.set(1,1); rotation = 0.0;}
    
    ofVec2f scale;
    float rotation;
    
    ofPath path;
    
    virtual void draw() {
        if(isVisible()) path.draw();
    }
    
    bool isFilled() { return path.isFilled(); }
    bool hasStroke() { return path.hasOutline(); }
    float getStrokeWidth() { return path.getStrokeWidth(); }
    ofColor getFillColor() { return path.getFillColor(); }
    ofColor getStrokeColor() { return path.getStrokeColor(); }
};

class ofxSvgRectangle : public ofxSvgElement {
public:
    ofxSvgRectangle() { type = OFX_SVG_TYPE_RECTANGLE; }
    ofRectangle rectangle;
    
    float getWidth() { return rectangle.getWidth();}
    float getHeight() { return rectangle.getHeight();}
    
    float getWidthScaled() { return rectangle.getWidth() * scale.x;}
    float getHeightScaled() { return rectangle.getHeight() * scale.y;}
};

class ofxSvgImage : public ofxSvgRectangle {
public:
    ofxSvgImage() { type = OFX_SVG_TYPE_IMAGE; bTryLoad = false; }
    
    virtual void draw() {
        if( !bTryLoad ) {
            img.load( getFilePath() );
            bTryLoad = true;
        }
        
        if( isVisible() ) {
            if( img.isAllocated() ) {
                ofPushMatrix(); {
                    ofTranslate( pos.x, pos.y );
                    if( rotation != 0.0 ) ofRotateZ( rotation );
                    ofScale( scale.x, scale.y );
                    ofSetColor( getColor() );
                    img.draw( 0, 0 );
                } ofPopMatrix();
            }
        }
    }
    
    string getFilePath() { return filepath; }
    
    void setColor( ofColor aColor ) {
        color = aColor;
    }
    ofColor getColor() {
        return color;
    }
    
    ofColor color;
    ofImage img;
    bool bTryLoad;
    string filepath;
};

class ofxSvgCircle : public ofxSvgElement {
public:
    ofxSvgCircle() { type = OFX_SVG_TYPE_CIRCLE; }
    
    float getRadius() {return radius;}
    
    float radius;
};

class ofxSvgEllipse : public ofxSvgElement {
public:
    ofxSvgEllipse() { type = OFX_SVG_TYPE_ELLIPSE; }
    
    float radiusX, radiusY;
};

class ofxSvgPath : public ofxSvgElement {
public:
    ofxSvgPath() { type = OFX_SVG_TYPE_PATH; }
};


class ofxSvgText : public ofxSvgRectangle {
public:
    
    class Font {
    public:
        string fontFamily;
        map< int, ofTrueTypeFont > sizes;
        map< int, ofTexture > textures;
    };
    
    static map< string, Font > fonts;
    
    class TextSpan {
    public:
        TextSpan() {
            text = "";
            fontSize = 12;
            lineHeight = 0;
        }
        
        string text;
        int fontSize;
        string fontFamily;
        ofRectangle rect;
        ofColor color;
        float lineHeight;
        ofTrueTypeFont& getFont();
    };
    
    static bool sortSpanOnFontFamily( const TextSpan& a, const TextSpan& b ) {
        return a.fontFamily < b.fontFamily;
    }
    
    static bool sortSpanOnFontSize( const TextSpan& a, const TextSpan& b ) {
        return a.fontSize < b.fontSize;
    }
    
    ofxSvgText() { type = OFX_SVG_TYPE_TEXT; fdirectory=""; bCentered=false; alpha=1.0; bOverrideColor=false; }
    
    void create();
    void draw();
    
    void setFontDirectory( string aPath ) {
        fdirectory = aPath;
//		cout << "Setting the font directory to " << fdirectory << endl;
    }
    
    void overrideColor( ofColor aColor ) {
        bOverrideColor = true;
        _overrideColor = aColor;
    }
    
    ofRectangle getRectangle();
    
    map< string, map<int, ofMesh> > meshes;
    vector< TextSpan > textSpans;
    
    string fdirectory;
    bool bCentered;
    float alpha;
    ofVec2f ogPos;
    
protected:
    static ofTrueTypeFont defaultFont;
	bool _recursiveFontDirSearch(string afile, string aFontFamToLookFor, string& fontpath);
    ofFloatColor _overrideColor;
    bool bOverrideColor;
};














