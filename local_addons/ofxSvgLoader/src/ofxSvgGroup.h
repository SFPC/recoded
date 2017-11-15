//
//  ofxSvgGroup.h
//
//  Created by Nick Hardeman on 7/31/15.
//

#pragma once
#include "ofxSvgBase.h"

class ofxSvgGroup : public ofxSvgBase {
public:
    ofxSvgGroup() { type = OFX_SVG_TYPE_GROUP; }
    
    virtual void draw();
    
    vector< shared_ptr<ofxSvgBase> >& getElements();
    vector< shared_ptr<ofxSvgBase> > getAllElements();
    
    template<typename ofxSvgType>
    vector< shared_ptr<ofxSvgType> > getElementsForType( string aPathToGroup="", bool bStrict= false ) {
        
        shared_ptr< ofxSvgType > temp( new ofxSvgType() );
        int sType = temp->getType();
        
        vector< shared_ptr<ofxSvgType> > telements;
        
        vector< shared_ptr<ofxSvgBase> > elementsToSearch;
        if( aPathToGroup == "" ) {
            elementsToSearch = elements;
        } else {
            shared_ptr< ofxSvgBase > temp = getElementForName( aPathToGroup, bStrict );
            if( temp ) {
                if( temp->isGroup() ) {
                    shared_ptr< ofxSvgGroup > tgroup = dynamic_pointer_cast< ofxSvgGroup>( temp );
                    elementsToSearch = tgroup->elements;
                }
            }
        }
        
        if( !elementsToSearch.size() && elements.size() ) {
            elementsToSearch = elements;
        }
        
        for( int i = 0; i < elementsToSearch.size(); i++ ) {
            if( elementsToSearch[i]->getType() == sType ) {
                telements.push_back( dynamic_pointer_cast< ofxSvgType>(elementsToSearch[i]) );
            }
        }
        return telements;
    }
    
    shared_ptr< ofxSvgBase > getElementForName( string aPath, bool bStrict = false );
    
    template<typename ofxSvgType>
    shared_ptr< ofxSvgType > get( string aPath, bool bStrict = false ) {
        shared_ptr< ofxSvgType > stemp = dynamic_pointer_cast< ofxSvgType >( getElementForName( aPath, bStrict ) );
        return stemp;
    }
    
    template<typename ofxSvgType>
    shared_ptr< ofxSvgType > get( int aIndex, bool bStrict = false ) {
        shared_ptr< ofxSvgType > stemp = dynamic_pointer_cast< ofxSvgType >( elements[ aIndex ] );
        return stemp;
    }
    
    virtual string toString(int nlevel = 0);
    
    int getNumChildren();
    
protected:
    void getElementForNameRecursive( vector< string >& aNamesToFind, shared_ptr< ofxSvgBase >& aTarget, vector< shared_ptr<ofxSvgBase> >& aElements, bool bStrict = false );
    void _getAllElementsRecursive( vector< shared_ptr< ofxSvgBase > >& aElesToReturn, shared_ptr<ofxSvgBase> aele );
    
    vector< shared_ptr<ofxSvgBase> > elements;
};

















