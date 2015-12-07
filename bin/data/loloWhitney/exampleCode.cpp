
shader_rip.begin();
shader_rip.setUniform1f("disor", [[Disort]]);
shader_rip.setUniform1f("wave_am", [[Wave Size]]);


ofPushMatrix();
    ofTranslate(center.x,center.y);
    ofNoFill();
    for (int i=0; i<q_main_val.size(); i++) {
        ofFloatColor _color = ofFloatColor(255);
        _color.setHsb(ofMap(i, 0, q_main_val.size(), 0.0, 1.0), 1.0, 1.0);
        float   _size = sin(q_main_val.at(i));
        ofRotateZ(q_main_val.at(i)*[[Rotation Val]]);
        ofSetColor(_color);
        float   _noi = ofNoise(q_main_val.at(i)*.1,ofGetFrameNum()*.01);
        _noi*=100.0;
        
        ofDrawEllipse(q_main_val.at(i)*.2)*100.0, (q_main_val.at(i)*.2)*100.0, _size*ellipse_size/2.0, _size*[[Ellipse Size]]);
    }
 ofPopMatrix();

 shader_rip.end();