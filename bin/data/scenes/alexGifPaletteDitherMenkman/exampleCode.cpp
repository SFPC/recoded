// This sketch does gif glitching as described
// in Rosa Menkman's "A Vernacular of File Formats"

// Inverting the Interleave flag
if([[Glitch Interleave]]) {
    sp->ImageDesc.Interlace = !sp->ImageDesc.Interlace;
}

if (sp->ImageDesc.Interlace) {
    int i, j;

    /* Need to perform 4 passes on the image */
    for (i = 0; i < 4; i++)
        for (j = InterlacedOffset[i];
             j < sp->ImageDesc.Height;
             j += InterlacedJumps[i]) {
            if (DGifGetLine(GifFile,
                            sp->RasterBits+j*sp->ImageDesc.Width,
                            sp->ImageDesc.Width) == GIF_ERROR)
                return GIF_ERROR;
        }
}
else {
    if (DGifGetLine(GifFile,sp->RasterBits,ImageSize)==GIF_ERROR)
        return (GIF_ERROR);
}


// Manipulate the color palette by shifting colors
memcpy((char *)colorMap.Colors, (char *)gif.SColorMap->Colors, gif.SColorMap->ColorCount * sizeof(GifColorType));
for(int j = 0; j < [[Glitch Color Palette]]; j++){

    GifColorType first = colorMap.Colors[0];
    for (int i=0; i < colorMap.ColorCount-1; i++) {
        colorMap.Colors[i] = colorMap.Colors[i+1];
    }
    colorMap.Colors[colorMap.ColorCount-1] = first;
}

// Read the actual frame pixels with the manipulated color palette
int p = 0; Byte r,g,b;
for (int i = 0; i < gif.Image.Height ; i++) {
    for (int j = 0; j < gif.Image.Width ; j++) {
        r = colorMap.Colors[gif.SavedImages[frameIndex].RasterBits[p]].Red;
        g = colorMap.Colors[gif.SavedImages[frameIndex].RasterBits[p]].Green;
        b = colorMap.Colors[gif.SavedImages[frameIndex].RasterBits[p]].Blue;
        framePixels.setColor(j % gif.Image.Width, i % gif.Image.Height, ofColor(r,g,b));
        p++;
    }
}

// copy pixels to frame
frame.setFromPixels(framePixels, gif.Image.Width, gif.Image.Height, OF_IMAGE_COLOR);
frame.update();
