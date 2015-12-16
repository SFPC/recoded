void veraSansTitre::draw(){
    for (int i = 0; i < [[number-of-row]]; i++) {
        for(int j=0; j<[[number-of-colmn]]; j++ ){
            drawRectangle( topLeftPoint.x + rectWidth * [[space-x]] * j,
                          topLeftPoint.y + rectHeight * [[space-y]]i + [[displacement-coef]] * noise,
                          rectWidth, rectHeight);
        }
    }
}
