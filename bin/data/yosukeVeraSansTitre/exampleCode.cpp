void veraSansTitre::draw(){
    for (int i = 0; i < row; i++) {
        for(int j=0; j<col; j++ ){
            drawRectangle( j * rectWidth + margin * j + displacementCoef_X * noise,
                          i * rectHeight + margin * i + displacementCoef_Y * noise,
                          rectWidth, rectHeight);
        }
    }
}
