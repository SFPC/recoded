void drawCircles(ofVec3f center, float radius, float time, float size,  , int currentIteration){
    for (int i =0; i < numCircles; i++) {
        float angle = TWO_PI*(i/float(numCircles)) + time;
        if (currentIteration < iterations) {
            drawCircles(ofVec3f(center.x+ radius*sin(angle),
                                center.y+ radius*cos(angle)),
                        size*2,
                        time/2,
                        radius/2*(1+sin(time)*growFactor*2),
                        numCircles*2,
                        currentIteration+1);
        }else{
            ofDrawCircle(center.x+ radius*sin(angle),
                         center.y+ radius*cos(angle),
                         size);
        }
    }
}