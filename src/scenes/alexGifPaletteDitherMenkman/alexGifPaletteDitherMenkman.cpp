//
//#include "alexGifPaletteDitherMenkman.h"
//
//void alexGifPaletteDitherMenkman::setup(){
//    
//    center.set(ofGetWidth()*0.5f, ofGetHeight()*0.5f, 0);
//    
//    dir.listDir("scenes/alexGifPaletteDitherMenkman/gifs/");
//    dir.sort(); // in linux the file system doesn't return file lists ordered in alphabetical order
//    
//    // timer stuff
//    lastTime = ofGetElapsedTimeMillis();
//    
//    // gui
//    parameters.add(pImageIndex.set("Image", 0, 0, dir.size()-1));
//    ImageIndexLast = 1;
//    
//    parameters.add(pPaletteShift.set("Glitch Color Palette", 0, 0, 0));
//    parameters.add(pGlitchInterleave.set("Glitch Interleave", true));
//    
//    parameters.add(pInterlacedOffset[0].set("Interleave Offset 1", 0,0,4));
//    parameters.add(pInterlacedOffset[1].set("Interleave Offset 2", 4,0,4));
//    parameters.add(pInterlacedOffset[2].set("Interleave Offset 3", 2,0,4));
//    parameters.add(pInterlacedOffset[3].set("Interleave Offset 4", 1,0,4));
//    
//    parameters.add(pInterlacedJumps[0].set("Interleave Jumps 1", 8,0,8));
//    parameters.add(pInterlacedJumps[1].set("Interleave Jumps 2", 8,0,8));
//    parameters.add(pInterlacedJumps[2].set("Interleave Jumps 3", 4,0,8));
//    parameters.add(pInterlacedJumps[3].set("Interleave Jumps 4", 2,0,8));
//    
//    parameters.add(pReset.set("Reset", false));
//    pReset.addListener(this, &alexGifPaletteDitherMenkman::pResetChanged);
//
//    
//    for(int i=0;i<4;i++){
//        pInterlacedJumps[i].addListener(this, &alexGifPaletteDitherMenkman::pInterlacedChanged);
//        pInterlacedOffset[i].addListener(this, &alexGifPaletteDitherMenkman::pInterlacedChanged);
//    }
//    
//    pGlitchInterleave.addListener(this, &alexGifPaletteDitherMenkman::pGlitchInterleaveChanged);
//
//    setAuthor("Alex Tolar");
//    setOriginalArtist("Rosa Menkman");
//    loadCode("scenes/alexGifPaletteDitherMenkman/exampleCode.cpp");
//}
//
//void alexGifPaletteDitherMenkman::update(){
//    
//    ofSetBackgroundColor(0);
//    
//    int InterlacedOffset[4];
//    int InterlacedJumps[4];
//    
//    for(int i=0; i<4; i++)
//    {
//        InterlacedOffset[i] = pInterlacedOffset[i];
//        InterlacedJumps[i] = pInterlacedJumps[i];
//    }
//
//    if((ImageIndexLast != pImageIndex) || ImageReload){
//        ImageReload = false;
//        ImageIndexLast = pImageIndex;
////        cout << "Image Index changed to:" << pImageIndex << " thats " << dir.getPath(pImageIndex) <<  endl;
//        
//        // DGifCloseFile(&gif,&gifOpenError);
//        gif = *DGifOpenFileName( ofToDataPath(dir.getPath(pImageIndex)).c_str() , &gifOpenError);
//        gifSlurpStatus = DGifGlitchSlurp(&gif,pGlitchInterleave,InterlacedOffset,InterlacedJumps);
//        
//        colorMap = *GifMakeMapObject(gif.SColorMap->ColorCount, gif.SColorMap->Colors);
//        
//        // allocate for pixels and images
//        framePixels.clear();
//        framePixels.allocate(gif.Image.Width, gif.Image.Height, OF_IMAGE_COLOR);
//        
//        frame.clear();
//        frame.allocate(gif.Image.Width, gif.Image.Height,OF_IMAGE_COLOR);
//        
//        pPaletteShift.setMax(gif.SColorMap->ColorCount);
//        
//        frameIndex = 0;
//        
////        cout << "Color Resolution: " << gif.SColorResolution << endl;
////        cout << "Image Count: " << gif.ImageCount << endl;
////        cout << "Palette Color Count: " << gif.SColorMap->ColorCount << endl;
////        cout << "Image Type: " << gif.Image.Interlace << endl;
//        
//    }
//    
//    colorMap = *GifMakeMapObject(gif.SColorMap->ColorCount, gif.SColorMap->Colors);
//    
//    // Manipulate the color palette by shifting colors
//    memcpy((char *)colorMap.Colors, (char *)gif.SColorMap->Colors, gif.SColorMap->ColorCount * sizeof(GifColorType));
//    for(int j = 0; j < pPaletteShift; j++){
//        
//        GifColorType first = colorMap.Colors[0];
//        for (int i=0; i < colorMap.ColorCount-1; i++) {
//            colorMap.Colors[i] = colorMap.Colors[i+1];
//        }
//        colorMap.Colors[colorMap.ColorCount-1] = first;
//    }
//    
//    // To Do: Use actual data from gif extension block, 12 fps for now
//    if(ofGetElapsedTimeMillis() - lastTime > 83){
//        frameIndex++;
//        if(frameIndex >= gif.ImageCount) {
//            frameIndex = 0;
//        }
//        lastTime = ofGetElapsedTimeMillis();
//    }
//    
//    // Read the actual frame pixels with the manipulated color palette
//    int p = 0; Byte r,g,b;
//    for (int i = 0; i < gif.Image.Height ; i++) {
//        for (int j = 0; j < gif.Image.Width ; j++) {
//            r = colorMap.Colors[gif.SavedImages[frameIndex].RasterBits[p]].Red;
//            g = colorMap.Colors[gif.SavedImages[frameIndex].RasterBits[p]].Green;
//            b = colorMap.Colors[gif.SavedImages[frameIndex].RasterBits[p]].Blue;
//            framePixels.setColor(j % gif.Image.Width, i % gif.Image.Height, ofColor(r,g,b));
//            p++;
//        }
//    }
//    
//    // copy pixels to frame
//    frame.setFromPixels(framePixels, gif.Image.Width, gif.Image.Height, OF_IMAGE_COLOR);
//    frame.update();
//    
//}
//
//void alexGifPaletteDitherMenkman::draw(){
//    
//    frame.draw(dimensions.width/2-frame.getWidth()/2, dimensions.height/2-frame.getHeight()/2);
//    
//}
//
//void alexGifPaletteDitherMenkman::pInterlacedChanged(int &value) {
//    if(!pGlitchInterleave) {
//        pGlitchInterleave.set(true);
//    } else {
//        ImageReload = true ;
//    }
//}
//
//void alexGifPaletteDitherMenkman::pGlitchInterleaveChanged(bool &value){
//    ImageReload = true;
//}
//
//void alexGifPaletteDitherMenkman::pResetChanged(bool &value) {
//    
//    if(pReset) {
//        
//    pImageIndex.set(0);
//    pGlitchInterleave.set(true);
//    pPaletteShift.set(0);
//        
//    pInterlacedOffset[0].set(0);
//    pInterlacedOffset[1].set(4);
//    pInterlacedOffset[2].set(2);
//    pInterlacedOffset[3].set(1);
//    pInterlacedJumps[0].set(8);
//    pInterlacedJumps[1].set(8);
//    pInterlacedJumps[2].set(4);
//    pInterlacedJumps[3].set(2);
//        
//    pReset.set(false);
//    
//    }
//    
//}
//
//
//
//
///******************************************************************************
// This routine reads an entire GIF into core, hanging all its state info off
// the GifFileType pointer.  Call DGifOpenFileName() or DGifOpenFileHandle()
// first to initialize I/O.  Its inverse is EGifSpew().
// *******************************************************************************/
//int
//DGifGlitchSlurp(GifFileType *GifFile, bool pInterleave, int InterlacedOffset[], int InterlacedJumps[])
//{
//    size_t ImageSize;
//    GifRecordType RecordType;
//    SavedImage *sp;
//    GifByteType *ExtData;
//    int ExtFunction;
//    
//    GifFile->ExtensionBlocks = NULL;
//    GifFile->ExtensionBlockCount = 0;
//    
//    do {
//        if (DGifGetRecordType(GifFile, &RecordType) == GIF_ERROR)
//            return (GIF_ERROR);
//        
//        switch (RecordType) {
//            case IMAGE_DESC_RECORD_TYPE:
//                if (DGifGetImageDesc(GifFile) == GIF_ERROR)
//                    return (GIF_ERROR);
//                
//                sp = &GifFile->SavedImages[GifFile->ImageCount - 1];
//                /* Allocate memory for the image */
//                if (sp->ImageDesc.Width < 0 && sp->ImageDesc.Height < 0 &&
//                    sp->ImageDesc.Width > (INT_MAX / sp->ImageDesc.Height)) {
//                    return GIF_ERROR;
//                }
//                ImageSize = sp->ImageDesc.Width * sp->ImageDesc.Height;
//                
//                if (ImageSize > (SIZE_MAX / sizeof(GifPixelType))) {
//                    return GIF_ERROR;
//                }
//                sp->RasterBits = (unsigned char *)malloc(ImageSize *
//                                                         sizeof(GifPixelType));
//                
//                if (sp->RasterBits == NULL) {
//                    return GIF_ERROR;
//                }
//                
//                // Inverting the Interleave flag
//                if(pInterleave) {
//                    sp->ImageDesc.Interlace = !sp->ImageDesc.Interlace;
//                }
//                
//                if (sp->ImageDesc.Interlace) {
//                    int i, j;
//                    /*
//                     * The way an interlaced image should be read -
//                     * offsets and jumps...
//                     */
//                    //int InterlacedOffset[] = { 0, 4, 2, 1 };
//                    //int InterlacedJumps[] = { 8, 8, 4, 2 };
//                    /* Need to perform 4 passes on the image */
//                    for (i = 0; i < 4; i++)
//                        for (j = InterlacedOffset[i];
//                             j < sp->ImageDesc.Height;
//                             j += InterlacedJumps[i]) {
//                            if (DGifGetLine(GifFile,
//                                            sp->RasterBits+j*sp->ImageDesc.Width,
//                                            sp->ImageDesc.Width) == GIF_ERROR)
//                                return GIF_ERROR;
//                        }
//                }
//                else {
//                    if (DGifGetLine(GifFile,sp->RasterBits,ImageSize)==GIF_ERROR)
//                        return (GIF_ERROR);
//                }
//                
//                if (GifFile->ExtensionBlocks) {
//                    sp->ExtensionBlocks = GifFile->ExtensionBlocks;
//                    sp->ExtensionBlockCount = GifFile->ExtensionBlockCount;
//                    
//                    GifFile->ExtensionBlocks = NULL;
//                    GifFile->ExtensionBlockCount = 0;
//                }
//                break;
//                
//            case EXTENSION_RECORD_TYPE:
//                if (DGifGetExtension(GifFile,&ExtFunction,&ExtData) == GIF_ERROR)
//                    return (GIF_ERROR);
//                /* Create an extension block with our data */
//                if (ExtData != NULL) {
//                    if (GifAddExtensionBlock(&GifFile->ExtensionBlockCount,
//                                             &GifFile->ExtensionBlocks,
//                                             ExtFunction, ExtData[0], &ExtData[1])
//                        == GIF_ERROR)
//                        return (GIF_ERROR);
//                }
//                while (ExtData != NULL) {
//                    if (DGifGetExtensionNext(GifFile, &ExtData) == GIF_ERROR)
//                        return (GIF_ERROR);
//                    /* Continue the extension block */
//                    if (ExtData != NULL)
//                        if (GifAddExtensionBlock(&GifFile->ExtensionBlockCount,
//                                                 &GifFile->ExtensionBlocks,
//                                                 CONTINUE_EXT_FUNC_CODE,
//                                                 ExtData[0], &ExtData[1]) == GIF_ERROR)
//                            return (GIF_ERROR);
//                }
//                break;
//                
//            case TERMINATE_RECORD_TYPE:
//                break;
//                
//            default:    /* Should be trapped by DGifGetRecordType */
//                break;
//        }
//    } while (RecordType != TERMINATE_RECORD_TYPE);
//    
//    return (GIF_OK);
//}
//
///* end */
//
//
