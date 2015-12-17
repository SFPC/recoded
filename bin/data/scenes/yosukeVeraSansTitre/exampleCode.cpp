void veraSansTitre::draw(){
  for (int i = 0; i < [[number-of-row]]; i++) {
    for (int j = 0; j< [[number-of-colmn]]; j++) {
      // Add spacing
      translate([[space-x]], [[space-y]]);

      // Get a random value with a seed
      float randomValue = random([[displacementZ]]);
        
      // Add random movement only in Y axis
      translate(0, [[displacement-coef]] * randomValue);
      drawRectangle(i, j, rectWidth, rectHeight);
    }
  }
}
