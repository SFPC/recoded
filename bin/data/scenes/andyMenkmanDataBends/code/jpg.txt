// JPEG image
void glitchImage() {
  lineNumber = 0;
  // go through each line in the input image and
  for(line in inputImage) {

    // if the current line is within the range (from
    // `startLine` to `startLine + maxLines`)
    if(line.number >= [[startLine]]
       && line.number < [[startLine]] + [[numberOfLines]]) {
      // don't add the line to the output image
      // (same as deleting it)
    } else {
      // otherwise, add this line to the image
      outputImage.append(line);
    }
  }
  outputImage.save();
}
