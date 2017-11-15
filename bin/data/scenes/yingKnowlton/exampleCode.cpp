
void draw() {

    currentVideo = getVideo([[videoNum]]).draw();

    for (int i = 0; i < [[iterations]]; i++) {

        if (random() < [[mixRatio]]) {
            targetImage = currentVideo;
        } else {
            targetImage = originalImage;
        }

        for (int i = 0; i < imageWidth; i++) {
            for (int j = 0; j < imageHeight; j++) {

                int randX = random(0, imageWidth);
                int randY = random(0, imageHeight);

                // randomly swap a pixel
                sourceImageAfterSwap = sourceImage.swapPixels(i,j, randX, randY);

                if (distanceToOriginal(sourceImageAfterSwap) <
                    distanceToOriginal(sourceImage)) {
                    sourceImage = sourceImageAfterSwap;
                }
            }
        }


    }
    sourceImage.draw();
}
