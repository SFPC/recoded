// image from Rosa Menkman's Flickr :)
// https://www.flickr.com/photos/r00s/4351749559/
// CC BY-NC 2.0

draw() {
    // copy the input image to the output image, deleting
    // lines of the JPG code based on the input
    glitchImage([[startLine]], [[numberOfLines]]);
    outputImage.draw();
}

glitchImage([[startLine]], [[numberOfLines]]) {
    lineNumber = 0;
    // go through each line in the input image and
    for(line in inputImage) {
    
        // if the current line is within the range (from
        // `startLine` to `startLine + maxLines`)
        if(lineNumber >= [[startLine]] && lineNumber < [[startLine]] + [[numberOfLines]]) {
            // don't add the line to the output image
            // (same as deleting it)
        } else {
            // otherwise, add this line to the image
            outputImage.append(line);
        }
        lineNumber++;
    }
    outputImage.save();
}
