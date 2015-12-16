//
//  janVantommeScene.cpp
//  d4nSFPCRunner
//
//  Created by Jan Vantomme on 07/12/15.
//
//

#include "janVantommeScene.h"

void janVantommeScene::setup()
{
    numBlocksHorizontal = 80;
    numBlocksVertical   = 80;
    
    blockSize = (float)dimensions.width / numBlocksHorizontal;
    
    h1 = floor( ofRandom( 2, 20 ) ) * 2;
    h2 = floor( ofRandom( 2, 20 ) ) * 2;
    h3 = numBlocksVertical - h1 - h2;
    
    probability = floor( ofRandom( 30, 40 ) );
    
    redrawScene = true;
    
    sceneFBO.allocate( dimensions.width, dimensions.height, GL_RGBA );
    
    sceneFBO.begin();
    ofClear( 0, 0, 0 );
    sceneFBO.end();
    
    startTime = ofGetElapsedTimeMillis();
    elapsedTime = 0;
    triggerTime = 500;
    triggerRedraw = 0;
    
    triggerTime.set("triggerTime", 1000, 500, 2000 );
    parameters.add( triggerTime );
    
    loadCode("scenes/janVantommeScene/examplecode.txt");
}

void janVantommeScene::update()
{
    elapsedTime = ofGetElapsedTimeMillis() - startTime;
    
    if ( elapsedTime >= triggerRedraw ) {
        triggerRedraw += triggerTime;

        h1 = floor( ofRandom( 2, 20 ) ) * 2;
        h2 = floor( ofRandom( 2, 20 ) ) * 2;
        h3 = numBlocksVertical - h1 - h2;

        redrawScene = true;
    }
    
}

void janVantommeScene::draw()
{
    if ( redrawScene ) {
       
        sceneFBO.begin();
        
        ofClear( 0, 0, 0 );

        for ( float x = 0; x < dimensions.width; x += blockSize ) {
            if ( ofRandom( 100 ) < probability ) {
                
                for ( int i = 0; i < h1; i+= 2 ) {
                    ofPushMatrix();
                    ofTranslate( x, i * blockSize );
                    
                    ofSetColor( 255 );
                    ofFill();
                    ofDrawRectangle( 0, 0, blockSize, blockSize );
                    ofSetColor( 0 );
                    ofNoFill();
                    ofDrawRectangle( 0, 0, blockSize, blockSize );

                    ofPopMatrix();
                }
            }
        }

        for ( float x = 0; x < dimensions.width; x += blockSize ) {
            if ( ofRandom( 100 ) < probability ) {
                
                for ( int i = 0; i < h2; i+= 2 ) {
                    ofPushMatrix();
                    ofTranslate( x, i * blockSize + h1 * blockSize );
                    
                    ofSetColor( 255 );
                    ofFill();
                    ofDrawRectangle( 0, 0, blockSize, blockSize );
                    ofSetColor( 0 );
                    ofNoFill();
                    ofDrawRectangle( 0, 0, blockSize, blockSize );
                    
                    ofPopMatrix();
                }
            }
        }

        for ( float x = 0; x < dimensions.width; x += blockSize ) {
            if ( ofRandom( 100 ) < probability ) {
                
                for ( int i = 0; i < h3; i+= 2 ) {
                    ofPushMatrix();
                    ofTranslate( x, i * blockSize + ( h1 + h2 ) * blockSize );
                    
                    ofSetColor( 255 );
                    ofFill();
                    ofDrawRectangle( 0, 0, blockSize, blockSize );
                    ofSetColor( 0 );
                    ofNoFill();
                    ofDrawRectangle( 0, 0, blockSize, blockSize );
                    
                    ofPopMatrix();
                }
            }
        }

        sceneFBO.end();

        redrawScene = false;
        
    }

    ofClear( 0, 0, 0 );
    ofSetColor( 255, 255, 255 );
    ofFill();
    
    sceneFBO.draw( 0, 0 );

}
