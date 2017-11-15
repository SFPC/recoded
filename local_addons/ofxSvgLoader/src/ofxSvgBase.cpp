//
//  ofxSvgBase.cpp
//
//  Created by Nick Hardeman on 7/31/15.
//

#include "ofxSvgBase.h"

map< string, ofxSvgText::Font > ofxSvgText::fonts;
ofTrueTypeFont ofxSvgText::defaultFont;

#pragma mark - ofxSvgBase
//--------------------------------------------------------------
string ofxSvgBase::getTypeAsString() {
    switch (type) {
        case OFX_SVG_TYPE_GROUP:
            return "Group";
            break;
        case OFX_SVG_TYPE_RECTANGLE:
            return "Rectangle";
            break;
        case OFX_SVG_TYPE_IMAGE:
            return "Image";
            break;
        case OFX_SVG_TYPE_ELLIPSE:
            return "Ellipse";
            break;
        case OFX_SVG_TYPE_CIRCLE:
            return "Circle";
            break;
        case OFX_SVG_TYPE_PATH:
            return "Path";
            break;
        case OFX_SVG_TYPE_TEXT:
            return "Text";
            break;
        default:
            break;
    }
    return "Unknown";
}

//--------------------------------------------------------------
string ofxSvgBase::toString( int nlevel ) {
    
    string tstr = "";
    for( int k = 0; k < nlevel; k++ ) {
        tstr += "   ";
    }
    tstr += getTypeAsString() + " - " + getName() + "\n";
    
    return tstr;
}

#pragma mark - ofxSvgText

//--------------------------------------------------------------
void ofxSvgText::create() {
    meshes.clear();
    
    // now lets sort the text based on meshes that we need to create //
    vector< TextSpan > tspans = textSpans;
    
    map< string, map< int, vector<TextSpan> > > tspanFonts;
    for( int i = 0; i < tspans.size(); i++ ) {
        if( tspanFonts.count( tspans[i].fontFamily ) == 0 ) {
            map< int, vector<TextSpan> > tmapap;
            tspanFonts[ tspans[i].fontFamily ] = tmapap;
        }
        map< int, vector<TextSpan> >& spanMap = tspanFonts[ tspans[i].fontFamily ];
        if( spanMap.count(tspans[i].fontSize) == 0 ) {
            vector< TextSpan > tvec;
            spanMap[ tspans[i].fontSize ] = tvec;
        }
        spanMap[ tspans[i].fontSize ].push_back( tspans[i] );
    }
    
    
    bool bHasFontDirectory = false;
//    cout << "checking directory: " << fdirectory+"/fonts/" << endl;
    string fontsDirectory = ofToDataPath("", true);
    if( fdirectory != "" ) {
        fontsDirectory = fdirectory;//+"/fonts/";
    }
    if( ofFile::doesFileExist( fontsDirectory )) {
        bHasFontDirectory = true;
    }
    
    map< string, map< int, vector<TextSpan> > >::iterator mainIt;
    for( mainIt = tspanFonts.begin(); mainIt != tspanFonts.end(); ++mainIt ) {
        if( fonts.count(mainIt->first) == 0 ) {
            Font tafont;
            tafont.fontFamily = mainIt->first;
            fonts[ mainIt->first ] = tafont;
        }
        
        // now create a mesh for the family //
        // map< string, map<int, ofMesh> > meshes;
        if( meshes.count(mainIt->first) == 0 ) {
            map< int, ofMesh > tempMeshMap;
            meshes[ mainIt->first ] = tempMeshMap;
        }
        
        Font& tfont = fonts[ mainIt->first ];
        map< int, ofMesh >& meshMap = meshes[ mainIt->first ];
        
        map< int, vector<TextSpan> >::iterator vIt;
        for( vIt = mainIt->second.begin(); vIt != mainIt->second.end(); ++vIt ) {
            vector<TextSpan>& spanSpans = vIt->second;
            bool bFontLoadOk = true;
			if (tfont.sizes.count(vIt->first) == 0) {
//                string _filename, int _fontSize, bool _bAntiAliased, bool _bFullCharacterSet, bool _makeContours, float _simplifyAmt, int _dpi
                // first let's see if the fonts are provided. Some system fonts are .dfont that have several of the faces
                // in them, but OF isn't setup to parse them, so we need each bold, regular, italic, etc to be a .ttf font //
				string tfontPath = tfont.fontFamily;
				if (bHasFontDirectory) {

					cout << "ofxSvgBase :: starting off searching directory : " << fontsDirectory << endl;
					string tNewFontPath = "";
					bool bFoundTheFont = _recursiveFontDirSearch(fontsDirectory, tfont.fontFamily, tNewFontPath);
					if (bFoundTheFont) {
						tfontPath = tNewFontPath;
					}

					/*ofDirectory tfDir;
					tfDir.listDir( fontsDirectory );
					for( int ff = 0; ff < tfDir.size(); ff++ ) {
						ofFile tfFile = tfDir.getFile(ff);
						if( tfFile.getExtension() == "ttf" || tfFile.getExtension() == "otf" ) {
							cout << ff << " - font family: " << tfont.fontFamily << " file name: " << tfFile.getBaseName() << endl;
							if( ofToLower(tfFile.getBaseName()) == ofToLower(tfont.fontFamily) ) {
								ofLogNotice(" >> ofxSvgText found font file for " ) << tfont.fontFamily;
								tfontPath = tfFile.getAbsolutePath();
								break;
							}
						}
					}*/
				}

				cout << "Trying to load font from: " << tfontPath << endl;

				if (tfontPath == "") {
					bFontLoadOk = false;
				}
				else {
                    // load(const std::string& _filename, int _fontSize, bool _bAntiAliased, bool _bFullCharacterSet, bool _makeContours, float _simplifyAmt, int _dpi)
					bFontLoadOk = tfont.sizes[vIt->first].load(tfontPath, vIt->first, true, true, false, 0.5, 72);
				}
                if(bFontLoadOk) {
//                    tfont.sizes[ vIt->first ].setSpaceSize( 0.57 );
//                    tfont.sizes[ vIt->first ]       = datFontTho;
                    tfont.textures[ vIt->first ]    = tfont.sizes[ vIt->first ].getFontTexture();
                } else {
                    ofLogError("ofxSvgLoader - error loading font family: ") << tfont.fontFamily << " size: " << vIt->first;
					tfont.sizes.erase(vIt->first);
                }
            }
            if( !bFontLoadOk ) continue;
            
            if( meshMap.count(vIt->first) == 0 ) {
                meshMap[ vIt->first ] = ofMesh();
            }
            ofMesh& tmesh = meshMap[ vIt->first ];
            
            if( !tfont.sizes.count( vIt->first ) ) {
                ofLogError("ofxSvgLoader - ") << "Could not find that font size in the map: " << vIt->first << endl;
                continue;
            }
            
            ofTrueTypeFont& ttfont = tfont.sizes[ vIt->first ];
            for( int i = 0; i < spanSpans.size(); i++ ) {
                // create a mesh here //
                TextSpan& cspan = spanSpans[i];
                if( cspan.text == "" ) continue;
//                cout << "font family: " << cspan.fontFamily << " size: " << cspan.fontSize << " text: " << cspan.text << endl;
                
//                const ofMesh& stringMesh  = ttfont.getStringMesh( "please work", 20, 20 );
                
                ofRectangle tempBounds = ttfont.getStringBoundingBox( cspan.text, 0, 0 );
                float tffontx = bCentered ? cspan.rect.x - tempBounds.width/2 : cspan.rect.x;
                const ofMesh& stringMesh  = ttfont.getStringMesh( cspan.text, tffontx-ogPos.x, cspan.rect.y-ogPos.y );
                int offsetIndex     = tmesh.getNumVertices();
                
                vector<ofIndexType> tsIndices = stringMesh.getIndices();
                for( int k = 0; k < tsIndices.size(); k++ ) {
                    tsIndices[k] = tsIndices[k] + offsetIndex;
                }
                
                ofFloatColor tcolor = cspan.color;
                vector< ofFloatColor > tcolors;
                tcolors.assign( stringMesh.getVertices().size(), tcolor );
                
                tmesh.addIndices( tsIndices );
                tmesh.addVertices( stringMesh.getVertices() );
                tmesh.addTexCoords( stringMesh.getTexCoords() );
                tmesh.addColors( tcolors );
            }
        }
    }
    
    // now loop through and set the width and height of the text spans //
    for( int i = 0; i < textSpans.size(); i++ ) {
        TextSpan& tempSpan = textSpans[i];
        ofTrueTypeFont& tfont = tempSpan.getFont();
        if( tfont.isLoaded() ) {
            ofRectangle tempBounds  = tfont.getStringBoundingBox( tempSpan.text, 0, 0 );
            tempSpan.rect.width     = tempBounds.width;
            tempSpan.rect.height    = tempBounds.height;
            tempSpan.lineHeight     = tfont.getStringBoundingBox("M", 0, 0).height;
//            tempSpan.rect.x         = tempSpan.rect.x - ogPos.x;
//            tempSpan.rect.y         = tempSpan.rect.x - ogPos.x;
            //tempSpan.rect.y         -= tempSpan.lineHeight;
        }
    }
}

//--------------------------------------------------------------
void ofxSvgText::draw() {
    if( !isVisible() ) return;
//    map< string, map<int, ofMesh> > meshes;
    ofSetColor( 255, 255, 255, 255.f * alpha );
    map< string, map<int, ofMesh> >::iterator mainIt;
    
    ofPushMatrix(); {
        ofTranslate( pos.x, pos.y );
        if( rotation > 0 ) ofRotateZ( rotation );
        ofTexture* tex;
        for( mainIt = meshes.begin(); mainIt != meshes.end(); ++mainIt ) {
            string fontFam = mainIt->first;
            map< int, ofMesh >::iterator mIt;
            for( mIt = meshes[ fontFam ].begin(); mIt != meshes[ fontFam ].end(); ++mIt ) {
                int fontSize = mIt->first;
                // let's check to make sure that the texture is there, so that we can bind it //
                bool bHasTexture = false;
                // static map< string, Font > fonts;
                if( fonts.count( fontFam ) ) {
                    if( fonts[ fontFam ].textures.count( fontSize ) ) {
                        bHasTexture = true;
                        tex = &fonts[ fontFam ].textures[ fontSize ];
                    }
                }
                
                if( bHasTexture ) tex->bind();
                ofMesh& tMeshMesh = mIt->second;
                vector< ofFloatColor >& tcolors = tMeshMesh.getColors();
                for( auto& tc : tcolors ) {
                    if( bOverrideColor ) {
                        tc = _overrideColor;
                    } else {
                        tc.a = alpha;
                    }
                }
                tMeshMesh.draw();
                if( bHasTexture ) tex->unbind();
            }
        }
    } ofPopMatrix();
    
}

//--------------------------------------------------------------
bool ofxSvgText::_recursiveFontDirSearch(string afile, string aFontFamToLookFor, string& fontpath) {
	if (fontpath != "") {
		return true;
	}
	ofFile tfFile( afile, ofFile::Reference );
	if (tfFile.isDirectory()) {
		cout << "ofxSvgText :: searching in directory : " << afile << " | " << ofGetFrameNum() << endl;
		ofDirectory tdir;
		tdir.listDir(afile);
		for (int i = 0; i < tdir.size(); i++) {
			bool youGoodOrWhat = _recursiveFontDirSearch(tdir.getPath(i), aFontFamToLookFor, fontpath);
            if( youGoodOrWhat ) {
                return true;
            }
		}
	}
	else {
		if ( tfFile.getExtension() == "ttf" || tfFile.getExtension() == "otf") {
			if (ofToLower( tfFile.getBaseName() ) == ofToLower(aFontFamToLookFor)) {
				ofLogNotice("ofxSvgText found font file for ") << aFontFamToLookFor;
				fontpath = tfFile.getAbsolutePath();
				return true;
			}
		}
	}
    return false;
}

// must return a reference for some reason here //
//--------------------------------------------------------------
ofTrueTypeFont& ofxSvgText::TextSpan::getFont() {
    if( ofxSvgText::fonts.count( fontFamily ) ) {
        Font& tfont = fonts[ fontFamily ];
        if( tfont.sizes.count(fontSize) ) {
            ofTrueTypeFont& tempFont = tfont.sizes[ fontSize ];
            return tempFont;
        }
    }
    return defaultFont;
}

// get the bounding rect for all of the text spans in this svg'ness
// should be called after create //
//--------------------------------------------------------------
ofRectangle ofxSvgText::getRectangle() {
    ofRectangle temp( 0, 0, 1, 1 );
    for( int i = 0; i < textSpans.size(); i++ ) {
        ofRectangle trect = textSpans[i].rect;
        trect.x = trect.x - ogPos.x;
        trect.y = trect.y - ogPos.y;
        trect.y -= textSpans[i].lineHeight;
        if( i == 0 ) {
            temp = trect;
        } else {
            temp.growToInclude( trect );
        }
    }
    
    
    temp.x += pos.x;
    temp.y += pos.y;
    return temp;
}










