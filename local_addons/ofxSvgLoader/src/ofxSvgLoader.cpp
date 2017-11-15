//
//  ofxSvgLoader.cpp
//
//  Created by Nick Hardeman on 7/31/15.
//

#include "ofxSvgLoader.h"
#include "svgtiny.h"

//--------------------------------------------------------------
ofxSvgLoader::ofxSvgLoader() {
    svgPath     = "";
    folderPath  = "";
    fontsDirectory  = "";
}

//--------------------------------------------------------------
bool ofxSvgLoader::load( string aPathToSvg ) {
    elements.clear();
    
    ofFile mainXmlFile( aPathToSvg, ofFile::ReadOnly );
    ofBuffer tMainXmlBuffer( mainXmlFile );
    
    svgPath     = aPathToSvg;
    folderPath  = ofFilePath::getEnclosingDirectory( aPathToSvg, false );
    
    Poco::XML::DOMParser parser;
    Poco::XML::Document* document;
    
    try {
        document = parser.parseMemory( tMainXmlBuffer.getData(), tMainXmlBuffer.size() );
        document->normalize();
    } catch( exception e ) {
        short msg = atoi(e.what());
        ofLogError() << "loadFromBuffer " << msg << endl;
        if( document ) {
            document->release();
        }
        return false;
    }
    
    if( document ) {
        Poco::XML::Element *svgNode     = document->documentElement();
        
        Poco::XML::Attr* viewBoxNode = svgNode->getAttributeNode("viewbox");
        
        bounds.x        = ofToFloat( cleanString( svgNode->getAttribute("x"), "px") );
        bounds.y        = ofToFloat( cleanString( svgNode->getAttribute("y"), "px" ));
        bounds.width    = ofToFloat( cleanString( svgNode->getAttribute("width"), "px" ));
        bounds.height   = ofToFloat( cleanString( svgNode->getAttribute("height"), "px" ));
        viewbox = bounds;
        
        if( viewBoxNode ) {
            string tboxstr = viewBoxNode->getNodeValue();
            vector< string > tvals = ofSplitString( tboxstr, " " );
            if( tvals.size() == 4 ) {
                viewbox.x = ofToFloat(tvals[0] );
                viewbox.y = ofToFloat( tvals[1] );
                viewbox.width = ofToFloat( tvals[2] );
                viewbox.height = ofToFloat( tvals[3] );
            }
        }
        
        parseXmlNode( document, svgNode, elements );
        
        document->release();
    }
    
    return true;
}

//--------------------------------------------------------------
bool ofxSvgLoader::reload() {
    if( svgPath == "" ) {
        ofLogError("ofxSvgLoader svg path is empty, please call load with file path before calling reload");
        return false;
    }
    return load( svgPath );
}

//--------------------------------------------------------------
void ofxSvgLoader::setFontsDirectory( string aDir ) {
    fontsDirectory = aDir;
    if( fontsDirectory.back() != '/' ) {
        fontsDirectory += '/';
    }
}

//--------------------------------------------------------------
string ofxSvgLoader::toString(int nlevel) {
    
    string tstr = "";
    if( elements.size() ) {
        for( int i = 0; i < elements.size(); i++ ) {
            tstr += elements[i]->toString( nlevel );
        }
    }
    
    return tstr;
}

//--------------------------------------------------------------
string ofxSvgLoader::cleanString( string aStr, string aReplace ) {
    ofStringReplace( aStr, aReplace, "");
    return aStr;
}

//--------------------------------------------------------------
void ofxSvgLoader::parseXmlNode( Poco::XML::Document* document, Poco::XML::Node* aParentNode, vector< shared_ptr<ofxSvgBase> >& aElements ) {
    if( aParentNode->hasChildNodes() ) {
        Poco::XML::NodeList *list = aParentNode->childNodes();
        for(int i=0; i < (int)list->length(); i++) {
            if(list->item(i) && list->item(i)->nodeType() == Poco::XML::Node::ELEMENT_NODE) {
                Poco::XML::Node* tnode  = (Poco::XML::Element*) list->item(i);
                
                if( tnode->hasChildNodes() && tnode->nodeName() == "g" ) {
                    shared_ptr< ofxSvgGroup > tgroup( new ofxSvgGroup() );
                    aElements.push_back( tgroup );
                    string attributePath = "[@id]";
                    Poco::XML::Node *atNode = tnode->getNodeByPath(attributePath);
                    if( atNode ) {
                        tgroup->name = atNode->getNodeValue();
                    }
                    
                    parseXmlNode( document, tnode, tgroup->getElements() );
//                    }
                } else {
                    bool bAddOk = addElementFromXmlNode( document, (Poco::XML::Element*)tnode, aElements );
                }
            }
        }
        list->release();
    }
}

//--------------------------------------------------------------
bool ofxSvgLoader::addElementFromXmlNode(Poco::XML::Document* document, Poco::XML::Element* tnode, vector< shared_ptr<ofxSvgBase> >& aElements ) {
    shared_ptr< ofxSvgElement > telement;
    
    if( tnode->nodeName() == "image" ) {
        telement = shared_ptr< ofxSvgImage >( new ofxSvgImage() );
        shared_ptr< ofxSvgImage > image = dynamic_pointer_cast< ofxSvgImage>( telement );
        image->rectangle.width  = ofToFloat(tnode->getAttribute("width"));
        image->rectangle.height = ofToFloat(tnode->getAttribute("height"));
        if( tnode->hasAttribute("xlink:href") ) {
            image->filepath = folderPath+tnode->getAttribute("xlink:href");
//            cout << "image->path = " << image->getFilePath() << endl;
        }
        
    } else if( tnode->nodeName() == "ellipse" ) {
        telement = shared_ptr< ofxSvgEllipse >( new ofxSvgEllipse() );
        telement->pos.x = ofToFloat(tnode->getAttribute("cx"));
        telement->pos.y = ofToFloat(tnode->getAttribute("cy"));
        
        shared_ptr< ofxSvgEllipse > ellipse = static_pointer_cast< ofxSvgEllipse>( telement );
        ellipse->radiusX = ofToFloat( tnode->getAttribute( "rx" ));
        ellipse->radiusY = ofToFloat( tnode->getAttribute( "ry" ));
        
        parseWithSvgTiny( document, tnode, telement );
        
    } else if( tnode->nodeName() == "circle" ) {
        telement = shared_ptr< ofxSvgCircle >( new ofxSvgCircle() );
        telement->pos.x = ofToFloat(tnode->getAttribute("cx"));
        telement->pos.y = ofToFloat(tnode->getAttribute("cy"));
        
        shared_ptr< ofxSvgCircle > ellipse = static_pointer_cast< ofxSvgCircle>( telement );
        ellipse->radius = ofToFloat( tnode->getAttribute( "r" ));
        parseWithSvgTiny( document, tnode, telement );
        
    } else if( tnode->nodeName() == "path" || tnode->nodeName() == "line" || tnode->nodeName() == "polyline" || tnode->nodeName() == "polygon" ) {
        telement = shared_ptr< ofxSvgPath >( new ofxSvgPath() );
        parseWithSvgTiny( document, tnode, telement );
    } else if( tnode->nodeName() == "rect" ) {
        telement = shared_ptr< ofxSvgRectangle >( new ofxSvgRectangle() );
        
        shared_ptr< ofxSvgRectangle > rect = dynamic_pointer_cast< ofxSvgRectangle>( telement );
        rect->rectangle.x       = ofToFloat(tnode->getAttribute("x"));
        rect->rectangle.y       = ofToFloat(tnode->getAttribute("y"));
        rect->rectangle.width   = ofToFloat(tnode->getAttribute("width"));
        rect->rectangle.height  = ofToFloat(tnode->getAttribute("height"));
        rect->pos.x = rect->rectangle.x;
        rect->pos.y = rect->rectangle.y;
        
        parseWithSvgTiny( document, tnode, telement );
        
        // this shouldn't be drawn at all, may be a rect that for some reason is generated
        // by text blocks //
        if( !rect->isFilled() && !rect->hasStroke() ) {
            telement.reset();
        }
        
    } else if( tnode->nodeName() == "text" ) {
        telement = shared_ptr< ofxSvgText >( new ofxSvgText() );
        shared_ptr< ofxSvgText > text = dynamic_pointer_cast< ofxSvgText>( telement );
//        cout << "has kids: " << tnode->hasChildNodes() << " node value: " << tnode->innerText() << endl;
        if( tnode->hasChildNodes() ) {
            Poco::XML::NodeList *list = tnode->childNodes();
            for(int i=0; i < (int)list->length(); i++) {
                if(list->item(i) && list->item(i)->nodeType() == Poco::XML::Node::ELEMENT_NODE) {
                    Poco::XML::Element* babyNode  = (Poco::XML::Element*) list->item(i);
                    if( babyNode->nodeName() == "tspan" ) {
                        text->textSpans.push_back( getTextSpanFromXmlNode( babyNode ) );
                    }
                }
            }
            list->release();
            
            // this may not be a text block or it may have to text //
            if( text->textSpans.size() == 0 ) {
                if( tnode->hasAttribute("font-family")) {
//                    cout << "Trying to add in a text span " << tnode->innerText() << endl;
                    text->textSpans.push_back( getTextSpanFromXmlNode( tnode ) );
                }
            }
            
        }
        
        string tempFolderPath = folderPath;
        if( tempFolderPath.back() != '/' ) {
            tempFolderPath += '/';
        }
        if( ofDirectory::doesDirectoryExist( tempFolderPath+"fonts/" )) {
            text->setFontDirectory( tempFolderPath+"fonts/" );
        }
        if( fontsDirectory != "" ) {
            if( ofDirectory::doesDirectoryExist(fontsDirectory)) {
                text->setFontDirectory( fontsDirectory );
            }
        }
        
    } else if( tnode->nodeName() == "g" ) {
//        if( tnode->hasChildNodes() ) {
//            telement = shared_ptr< ofxSvgGroup >( new ofxSvgGroup() );
//        }
    }
    
    if( !telement ) {
        return false;
    }
    
    if( telement->getType() == ofxSvgBase::OFX_SVG_TYPE_RECTANGLE || telement->getType() == ofxSvgBase::OFX_SVG_TYPE_IMAGE || telement->getType() == OFX_SVG_TYPE_TEXT ) {
        if( tnode->hasAttribute("transform") ) {
            getTransformFromSvgMatrix( tnode->getAttribute("transform"), telement->pos, telement->scale.x, telement->scale.y, telement->rotation );
        }
        if( telement->getType() == ofxSvgBase::OFX_SVG_TYPE_IMAGE ) {
            shared_ptr< ofxSvgImage > timg = dynamic_pointer_cast<ofxSvgImage>( telement );
            timg->rectangle.x = timg->pos.x;
            timg->rectangle.y = timg->pos.y;
        }
    }
    
    if( telement->getType() == ofxSvgBase::OFX_SVG_TYPE_TEXT ) {
        shared_ptr< ofxSvgText > text = dynamic_pointer_cast< ofxSvgText>( telement );
        text->ogPos = text->pos;
        text->create();
    }
    
    if( tnode->hasAttributes() ) {
        string attributePath = "[@id]";
        Poco::XML::Node *atNode = tnode->getNodeByPath(attributePath);
        if( atNode ) {
            telement->name = atNode->getNodeValue();
        }
        
        string displayPath = "[@display]";
        Poco::XML::Node *displayNode = tnode->getNodeByPath(displayPath);
        if( displayNode ) {
            //            telement->name = atNode->getNodeValue();
            if( displayNode->getNodeValue() == "none" ) {
                telement->setVisible( false );
            }
        }
    }
    
//    cout << "name: " << telement->name << " type: " << telement->getTypeAsString() << endl;
    
    
    aElements.push_back( telement );
    return true;
}

//--------------------------------------------------------------
void ofxSvgLoader::parseWithSvgTiny( Poco::XML::Document* document, Poco::XML::Element* tnode, shared_ptr<ofxSvgElement> aElement ) {
    
    struct svgtiny_diagram * diagram = svgtiny_create();
    
//    Poco::XML::Element *path;
//    struct svgtiny_parse_state state;
    aElement->path.clear();
    
    if( aElement->getType() == ofxSvgBase::OFX_SVG_TYPE_PATH ) {
        if( tnode->nodeName() == "line" ) {
            svgtiny_parseLine( document, tnode, diagram );
        } else if( tnode->nodeName() == "path" ) {
            svgtiny_parsePath( document, tnode, diagram );
        } else if( tnode->nodeName() == "polyline" ) {
            svgtiny_parsePolyline( document, tnode, diagram );
        } else if( tnode->nodeName() == "polygon" ) {
            svgtiny_parsePolygon( document, tnode, diagram );
        }
    } else if( aElement->getType() == ofxSvgBase::OFX_SVG_TYPE_ELLIPSE ) {
        svgtiny_parseEllipse( document, tnode, diagram );
    } else if( aElement->getType() == ofxSvgBase::OFX_SVG_TYPE_CIRCLE ) {
        svgtiny_parseCircle( document, tnode, diagram );
    } else if( aElement->getType() == ofxSvgBase::OFX_SVG_TYPE_RECTANGLE ) {
        svgtiny_parseRectangle( document, tnode, diagram );
    }
    
    for(int i = 0; i < (int)diagram->shape_count; i++) {
        if( diagram->shape[i].path ) {
//            cout << ">>>>>>> path " << i << " " << (int)diagram->shape[i].path_length << endl;
            setupShape( &diagram->shape[i], aElement->path );
            
//            cout << " path length  = " << aElement->paths.back().getOutline().size() << endl;
        }
    }
    
    svgtiny_free( diagram );
}

// taken from ofxSvg //
void ofxSvgLoader::setupShape( struct svgtiny_shape* shape, ofPath& path ) {
	float * p = shape->path;
    
    
	path.setFilled(false);
    path.setStrokeWidth( 0 );
    
	if(shape->fill != svgtiny_TRANSPARENT){
		path.setFilled(true);
		path.setFillHexColor(shape->fill);
		//path.setPolyWindingMode(OF_POLY_WINDING_NONZERO);
    }
    
	if(shape->stroke != svgtiny_TRANSPARENT){
		path.setStrokeWidth(shape->stroke_width);
		path.setStrokeHexColor(shape->stroke);
	}
    
	for(int i = 0; i < (int)shape->path_length;){
		if(p[i] == svgtiny_PATH_MOVE){
			path.moveTo(p[i + 1], p[i + 2]);
			i += 3;
		}
		else if(p[i] == svgtiny_PATH_CLOSE){
			path.close();
            
			i += 1;
		}
		else if(p[i] == svgtiny_PATH_LINE){
			path.lineTo(p[i + 1], p[i + 2]);
			i += 3;
		}
		else if(p[i] == svgtiny_PATH_BEZIER){
			path.bezierTo(p[i + 1], p[i + 2],
                          p[i + 3], p[i + 4],
                          p[i + 5], p[i + 6]);
			i += 7;
		}
		else{
			ofLogError("ofxSVG") << "setupShape(): SVG parse error";
			i += 1;
		}
//        cout << "parse path " << i << endl;
	}
    
    
    //cout << "getting up path " << path.getOutline().size() <<  endl;
    
    
}

//--------------------------------------------------------------
bool ofxSvgLoader::getTransformFromSvgMatrix( string matrix, ofVec2f& apos, float & scaleX, float & scaleY, float & arotation ){
    
    scaleX = 1.0;
    scaleY = 1.0;
    arotation = 0.0;
    
    ofStringReplace(matrix, "matrix(", "");
    ofStringReplace(matrix, ")", "");
    vector <string> matrixNum = ofSplitString(matrix, " ", false, true);
    vector <float> matrixF;
    for(int i = 0; i < matrixNum.size(); i++){
        matrixF.push_back(ofToFloat(matrixNum[i]));
        //cout << " matrix[" << i << "] = " << matrixF[i] << " string version is " << matrixNum[i] << endl;
    }
    
    if( matrixNum.size() == 6 ) {
        
        apos.x = matrixF[4];
        apos.y = matrixF[5];
        
        scaleX = sqrt(matrixF[0] * matrixF[0] + matrixF[1] * matrixF[1]) * (float)ofSign(matrixF[0]);
        scaleY = sqrt(matrixF[2] * matrixF[2] + matrixF[3] * matrixF[3]) * (float)ofSign(matrixF[3]);
        
        arotation = atan(matrixF[2]/matrixF[3]) * RAD_TO_DEG;
        arotation *= -1.0;
        
        //cout << " rotation is " << rotation << endl;
        
        return true;
    }
    return false;
}

//--------------------------------------------------------------
ofColor ofxSvgLoader::getColorFromXmlAttr( string aAtt ) {
    ofStringReplace( aAtt, "#", "" );
    aAtt = "0x"+aAtt;
    ofColor tcolor;
    tcolor.setHex( ofHexToInt( aAtt ) );
    return tcolor;
}

//--------------------------------------------------------------
ofxSvgText::TextSpan ofxSvgLoader::getTextSpanFromXmlNode( Poco::XML::Element* aNode ) {
    ofxSvgText::TextSpan tspan;
    
    string tText = aNode->innerText();
    string tFontFam = "Arial";
    if( aNode->hasAttribute("font-family") ) {
        tFontFam = aNode->getAttribute("font-family");
        ofStringReplace( tFontFam, "'", "" );
    }
    int tFontSize = 18;
    if( aNode->hasAttribute("font-size")) {
        tFontSize = ofToInt( aNode->getAttribute("font-size"));
    }
    float tx = 0;
    if( aNode->hasAttribute("x")) {
        tx = ofToFloat( aNode->getAttribute("x") );
    }
    float ty = 0;
    if( aNode->hasAttribute("y")) {
        ty = ofToFloat( aNode->getAttribute("y") );
    }
    ofColor tcolor;
    if( aNode->hasAttribute("fill")) {
        tcolor = getColorFromXmlAttr( aNode->getAttribute("fill") );
    }
    
    // try to figure out the transform //
    if( aNode->hasAttribute("transform") ) {
        // we just need the rect.x and rect.y
        ofVec2f tpos; float tscalex, tscaley, trotation;
        getTransformFromSvgMatrix( aNode->getAttribute("transform"), tpos, tscalex, tscaley, trotation );
        tx = tpos.x;
        ty = tpos.y;
    }
    
    tspan.text          = tText;
    tspan.fontFamily    = tFontFam;
    tspan.fontSize      = tFontSize;
    tspan.rect.x        = tx;
    tspan.rect.y        = ty;
    tspan.color         = tcolor;
    
    return tspan;
}

//--------------------------------------------------------------
const ofRectangle ofxSvgLoader::getBounds(){
	return bounds;
}

//--------------------------------------------------------------
const ofRectangle ofxSvgLoader::getViewbox(){
	return viewbox;
}
