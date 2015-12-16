
ofPushMatrix();
ofTranslate(VISUALS_WIDTH/2,VISUALS_HEIGHT/2,[[CAM_Z_POS]]);

for(int i=0;i<lines.size();i++)
    {        
        int _e_limit = 1+[[EXTRUDE_LINES]]*(1.0-show_original_val);
        float _l_z = ofMap(show_original_val, 0.0, 1.0, lines.at(i).z, 200.0);
        
        for(int e=0;e<_e_limit;e++){
            ofPushMatrix();
            ofTranslate(lines.at(i).x, lines.at(i).y,_l_z+(e*(4.0*1.0-show_original_val)));
            
            float x0 = cos(lines.at(i).angle);
            float y0 = sin(lines.at(i).angle);
            float x1 = cos(lines.at(i).angle)*lines.at(i).lon;
            float y1 = sin(lines.at(i).angle)*lines.at(i).lon;
            
            float _col =255.0;
            float _final_col =(255*_col)+(show_original_val*255.0);
            _final_col = ofClamp(_final_col, 0.0, 255.0);
            
            ofSetColor(_final_col);
            
            ofDrawLine(x0, y0, x1, y1);
            ofPopMatrix();

        }
    }

    ofPopMatrix();
