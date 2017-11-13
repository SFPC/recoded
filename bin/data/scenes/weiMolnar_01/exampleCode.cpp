
float time = getElapsedSeconds();
ofSetColor(map(sin(time*2), -1,1, 0, 255),
           map(sin(time*10), -1,1, 100, 255),
           map(cos(time*4), -1,1, 0, 255));


for (int i = 0; i < count; i++){
    for (int j = 0; j < count; j++){
        float x = map(i + 1, 0, count + 1, 0, MIN(width, height));
        float y = map(j + 1, 0, count + 1, 0, MIN(width, height));
        beginShape();
        addVertex(x + random(-xOffset, xOffset) +
                    map(sin(time*5), -1, 1, 0, 10),
                  y + random(-yOffset, yOffset));
        addVertex(x + random(-xOffset, xOffset) + 
                    map(cos(time) * 2, -1, 1, -0, 0),
                  y + map(cos(time * 10), -1, 1, -10, 10));
        addVertex(x + random(-xOffset, xOffset) + 
                    map(sin(time), -1, 1, -20, 0), 
                  y + random(-yOffset, yOffset) +
                  map(sin(time * 2) * 2, -1, 1, 0, 10));
        addVertex(x + random(-xOffset, xOffset),
                  y + map(cos(time * 20), -1, 1, -10, 0) +
                   random(-yOffset, yOffset));
        endShape();
    }
}
