if(ofGetFrameNum() % [[UPDATE PATHS]] == 0){

  for(int i=1;i<q_guide.size()-1;i++)
  {
    q_guide_d.at(i).x=original_position.x+ofRandom(-guide_step,guide_step)*[[RANDOM FACTOR]];
    q_guide_d.at(i).y=y+ofRandom(-guide_step,guide_step)*[[RANDOM FACTOR]];
  }

}

void    draw()
{
  ofPushStyle();
  ofEnableAlphaBlending();

  ofSetColor(0,100);

  for(int i=1;i<q_guide.size();i++)
  {
    ofSetLineWidth([[LINE WEIGHT]]);

    ofDrawLine(q_guide.at(i-1).x, q_guide.at(i-1).y, q_guide.at(i).x, q_guide.at(i).y);
  }

  ofSetLineWidth([[LINE WEIGHT]]+1);

  ofSetColor(255, 0, 0);

  ofDrawLine(guide.x, guide.y, d_guide.x,d_guide.y);

  ofSetColor(0);
  for (int i=0; i<q_guide.size(); i++) {
    ofDrawCircle(q_guide.at(i).x,q_guide.at(i).y, 2);
  }

  ofSetColor(255, 0, 0,100);
  ofDrawCircle(q_guide.at(current_point-1).x, q_guide.at(current_point-1).y, e*20.0);

  ofDisableAlphaBlending();
  ofPopStyle();
};
