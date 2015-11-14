for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
        int numShapes = 0;
        switch(j) {
            case 0:
                numShapes = 5;
                break;
            case 1:
                numShapes = 25;
                break;
            case 2:
                numShapes = 10;
                break;
            case 3:
                numShapes = 6;
                break;
            case 4:
                numShapes = 3;
                break;
            case 5:
                numShapes = 2;
                break;
        }
        
        for(int k = 0; k < numShapes; k++) {
            ofBeginShape();
            
            int centerX = 150 + i*110;
            int centerY = 150 + j*110;
            
            pos[i][j][k].topLeft.x = (pos[i][j][k].topLeft.x + ofRandom(-5,5));
            pos[i][j][k].topLeft.y = (pos[i][j][k].topLeft.y + ofRandom(-5,5));
            pos[i][j][k].topRight.x = (pos[i][j][k].topRight.x + ofRandom(-5,5));
            pos[i][j][k].topRight.y = (pos[i][j][k].topRight.y + ofRandom(-5,5));
            pos[i][j][k].bottomRight.x = (pos[i][j][k].bottomRight.x + ofRandom(-5,5));
            pos[i][j][k].bottomRight.y = (pos[i][j][k].bottomRight.y + ofRandom(-5,5));
            pos[i][j][k].bottomLeft.x = (pos[i][j][k].bottomLeft.x + ofRandom(-5,5));
            pos[i][j][k].bottomLeft.y = (pos[i][j][k].bottomLeft.y + ofRandom(-5,5));
            
            ofVertex( (centerX - 100 * vols[i] ) * [[smoothing]] +
                     (1-[[smoothing]]) * pos[i][j][k].topLeft.x,
                     (centerY - 100 * vols[i] ) * [[smoothing]] +
                     (1-[[smoothing]]) * pos[i][j][k].topLeft.y);
            ofVertex( (centerX + 100 * vols[i] ) * [[smoothing]] +
                     (1-[[smoothing]]) * pos[i][j][k].topRight.x,
                     (centerY - 100 * vols[i] ) * [[smoothing]] +
                     (1-[[smoothing]]) * pos[i][j][k].topRight.y);
            ofVertex( (centerX + 100 * vols[i] ) * [[smoothing]] +
                     (1-[[smoothing]]) * pos[i][j][k].bottomRight.x,
                     (centerY + 100 * vols[i] ) * [[smoothing]] +
                     (1-[[smoothing]]) * pos[i][j][k].bottomRight.y);
            ofVertex( (centerX - 100 * vols[i] ) * [[smoothing]] +
                     (1-[[smoothing]]) * pos[i][j][k].bottomLeft.x,
                     (centerY + 100 * vols[i] ) * [[smoothing]] +
                     (1-[[smoothing]]) * pos[i][j][k].bottomLeft.y);
            
            
            ofEndShape(true);
        }
    }
}