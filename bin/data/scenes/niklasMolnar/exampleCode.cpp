grid = [[grid]];
gridUnitW = dimensions.width * framePad / ;
gridUnitH = dimensions.height * framePad / [[grid]];
randMin = [[randMin]];
randMax = [[randMax]];
rectCopy = [[rectCopy]];

void drawRectangle( ofPoint a, ofPoint b, ofPoint c, ofPoint d){
    for (int i = 0; i < rectCopy; i++) {
        
        rectCopyScaleX = ofMap(i, 0, [[rectCopy]], 0.075, 1);
        rectCopyScaleY = ofMap(i, 0, [[rectCopy]], 0.5, 1);
        ofScale(rectCopyScaleX, rectCopyScaleY);
        
        ofTranslate(- gridUnitW * 0.5, - gridUnitH * 0.5); //  square center at 0, 0
        
        ofSetLineWidth(5);
        ofDrawLine(a, b);
        ofDrawLine(c, d);
        
        ofSetLineWidth(1);
        ofDrawLine(a, c);
        ofDrawLine(b, d);
};
    for (int i = 0; i < [[grid]]; i++) {
        for (int j = 0; j < [[grid]]; j++){
            
            ofPushMatrix();
            
            ofTranslate(i * gridUnitW, j * gridUnitH);
            ofTranslate(+ gridUnitW * 0.5, + gridUnitH * 0.5);
            
            ofScale(rectSizeX, rectSizeY);
            
            ofPoint a = ofPoint(0 + ofRandom([[randMin]], [[randMax]]), 0);
            ofPoint b = ofPoint(gridUnitW + ofRandom([[randMin]], [[randMax]]), 0);
            ofPoint c = ofPoint(0 + ofRandom([[randMin]], [[randMax]]), gridUnitH);
            ofPoint d = ofPoint(gridUnitW + ofRandom([[randMin]], [[randMax]]), gridUnitH);
            drawRectangle(a, b, c, d);
            
            ofPopMatrix();
        }
    }}
