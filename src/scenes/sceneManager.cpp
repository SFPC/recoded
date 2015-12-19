//
//  sceneManager.cpp
//  d4nSFPCRunner
//
//  Created by zach on 11/14/15.
//
//

#include "sceneManager.h"
#include "baseScene.h"

#include "exampleScene.h"
#include "triangleScene.h"
#include "veraAnimatedScene.h"
#include "robbyMolnarScene.h"
#include "robbyRileyScene.h"
#include "yeseulWhitneyScene.h"
#include "johnWhitneyShader01.h"
#include "johnWhitneyShader02.h"
#include "RoyWhitney1.h"
#include "veraFscene.h"
#include "anastasisRileyScene.h"
#include "loloWhitney.h"
#include "loloVera.h"
#include "andyMenkmanDataBendsJpg.h"
#include "andyMenkmanDataBendsPng.h"
#include "andyMenkmanDataBendsTif.h"
#include "CooperBauhaus.h"
#include "memoAktenScene.h"
#include "submotionOrchestraScene.h"
#include "manfredMohrP196A.h"
#include "chrisMurielCooper.h"
#include "chrisRileyCascando.h"
#include "veraMolnarTrapezium.h"
#include "loloVera2.h"
#include "cantusFirmusRiley.h"
#include "chrisVeraInterruptions.h"
#include "aaronMarcusHieroglyphB.h"
#include "veraMolnarLines68.h"
#include "Cooper3dText.h"
#include "alexLissamojiWhitney.h"
#include "janVantommeScene.h"
#include "rodrigoBelfort.h"
#include "rachelScene.h"
#include "RileyArcsRoy.h"
#include "robbyMenkmanScene.h"
#include "yosukeVeraSansTitre.h"
#include "alexGifPaletteDitherMenkman.h"
#include "yeseulMenkmanInstitution.h"
#include "yeseulCooperMessages.h"
#include "yosukeJohnWhitneyMatrix.h"
#include "mgsCooperSymbols.h"
#include "mgsRileyDiamonds.h"
#include "mgsRileyEllipsesAndSquares.h"
#include "mgsRileyDescending.h"
#include "mgsVeraMolnarLineStudy.h"
#include "mgsMaedaTimePainter.h"
#include "olegVeraV.h"
#include "sarahgpRileyCircle.h"
#include "mwalczykVeraSquares.h"
#include "yeseulRileyBrokencircle.h"

float baseScene::smoothingSpeed = 0.2;

//-----------------------------------------------------------------------------------
sceneManager::~sceneManager(){
    ofRemoveListener(sync.ffwKeyPressed, this, &sceneManager::setAdvanceCurrentScene);
}
//-----------------------------------------------------------------------------------
void sceneManager::setup(){
    
    font.load("fonts/ProggySmall.fon", 8, false ,false, false, 0, 96);

    scenes.push_back(new CooperBauhaus());  // this might make for a good start scene -Robby & Becca
    scenes.push_back(new RileyArcsRoy());
    scenes.push_back(new rachelScene());
    scenes.push_back(new rodrigoBelfort());
    scenes.push_back(new Cooper3dText());
    scenes.push_back(new chrisVeraInterruptions());
    scenes.push_back(new johnWhitneyShader02());
    scenes.push_back(new chrisRileyCascando());
    scenes.push_back(new memoAktenScene());
    scenes.push_back(new submotionOrchestraScene());
    scenes.push_back(new RoyWhitney1());
    scenes.push_back(new veraFscene());
    scenes.push_back(new robbyMolnarScene() );
    scenes.push_back(new veraAnimatedScene() );
    scenes.push_back(new robbyRileyScene() );
    scenes.push_back(new robbyMenkmanScene());
    scenes.push_back(new johnWhitneyShader01());
    scenes.push_back(new anastasisRileyScene());
    scenes.push_back(new loloWhitney());
    scenes.push_back(new loloVera());
    scenes.push_back(new andyMenkmanDataBendsJpg());
    scenes.push_back(new andyMenkmanDataBendsPng());
    scenes.push_back(new andyMenkmanDataBendsTif());
    scenes.push_back(new manfredMohrP196A());
    scenes.push_back(new veraMolnarTrapezium());
    scenes.push_back(new loloVera2());
    scenes.push_back(new cantusFirmusRiley());
    scenes.push_back(new aaronMarcusHieroglyphB());
    scenes.push_back(new veraMolnarLines68());
    scenes.push_back(new alexLissamojiWhitney());
    scenes.push_back(new yosukeVeraSansTitre());
    scenes.push_back(new alexGifPaletteDitherMenkman());
    scenes.push_back(new yeseulMenkmanInstitution());
    scenes.push_back(new yeseulCooperMessages());
    scenes.push_back(new yeseulWhitneyScene());
    scenes.push_back(new yeseulRileyBrokencircle());
    scenes.push_back(new yosukeJohnWhitneyMatrix());
    scenes.push_back(new mgsCooperSymbols());
    scenes.push_back(new mgsRileyDiamonds());
    scenes.push_back(new mgsRileyEllipsesAndSquares());
    scenes.push_back(new mgsVeraMolnarLineStudy());
    scenes.push_back(new mgsMaedaTimePainter());
    scenes.push_back(new mgsRileyDescending());
    scenes.push_back(new olegVeraV());
    scenes.push_back(new sarahgpRileyCircle());
    scenes.push_back(new mwalczykVeraSquares());

    
    // Duplicate with rodrigoBelfort
    // scenes.push_back(new janVantommeScene());
    
    
#ifdef USE_MIDI_PARAM_SYNC
    sync.setup(0);
    
    // Disable MIDI smoothing by default
    sync.smoothing.set(0);

    ofAddListener(sync.player.playE, this, &sceneManager::startPlaying);
    ofAddListener(sync.recorder.recEndE, this, &sceneManager::recordingEnd);
#endif
    
    // Not using
    // scenes.push_back(new chrisMurielCooper());
    gui.setDefaultWidth(300);    
    gui.setup("SFPC_d4n", "SFPC_d4n_general_settings.xml");


    gui.add(bAutoPlay.set("Auto Play on scene change", false));
    gui.add(autoadvanceDelay.set("Autoadvance", 0, 0, 60));
    gui.add(bSceneWaitForCode.set("Scene wait for code", true));
    gui.add(bFadeOut.set("Scene fade out", true));
    gui.add(bAutoAdvance.set("Auto Advance Scene", false));
#ifdef USE_SCENE_TRANSITIONS
    gui.add(sceneTweenDuration.set("fadeOutTime", 4.0, 0, 10.0));
    gui.add(codeTweenDuration.set("fadeInTime", 7.5, 0, 15));
#endif
    sync.smoothing.setName("MIDI Smoothing");
    gui.add(sync.smoothing);
    gui.add(ofSmoothing.set("OF Smoothing", 0.2, 0.01, 1));
    
    
    gui.loadFromFile("SFPC_d4n_general_settings.xml");
//    gui.setWidthElements(300);
//    gui.setDefaultWidth(300);
    gui.setPosition(ofGetWidth() - gui.getShape().width-20,  ofGetHeight() - gui.getShape().getHeight() - 100);
    
    
    sceneFbo.allocate(VISUALS_WIDTH, VISUALS_HEIGHT, GL_RGBA, 4);
    codeFbo.allocate(VISUALS_WIDTH, VISUALS_HEIGHT, GL_RGB, 1);

    lastFrame.allocate(VISUALS_WIDTH, VISUALS_HEIGHT, OF_PIXELS_RGBA);
    currFrame.allocate(VISUALS_WIDTH, VISUALS_HEIGHT, OF_PIXELS_RGBA);

    //  transitionFbo.allocate(VISUALS_WIDTH, VISUALS_HEIGHT, GL_RGB32F_ARB);
    transitionFbo.begin();
    ofSetColor(0,255);
    ofDrawRectangle(0, 0, VISUALS_WIDTH, VISUALS_HEIGHT);
    transitionFbo.end();
    transitionFbo.draw(0,0);
    
#ifdef USE_EXTERNAL_SOUNDS
    // open an outgoing connection
    oscSender.setup(OSC_HOST, OSC_PORT);
#endif
    
    // disney
    for (auto scene : scenes){
        scene->dimensions.set(0,0,VISUALS_WIDTH, VISUALS_HEIGHT);
        scene->setup();
        scene->enableMidi();
    }
    
    
    //    for (int i = 0; i< scenes.size(); i++){
    //        scenes[i]->setup();
    //    }
    
    isTransitioning = false;
    currentScene = 0;

#ifdef TYPE_ANIMATION
    shouldDrawScene = false;
#else
    shouldDrawScene = true;
#endif
    shouldDrawCode = true;
    
    panel = new ofxPanel();
    panel->setup("scene settings");
    panel->add(scenes[currentScene]->parameters);
    panel->setPosition(520+504+20, 20);

    codeEnergyDecayRate.set("codeDecay", 0.1, 0, 0.3);
    codeEnergyPerFrame.set("codeEnergyPerFrame", 0.15, 0, 0.4);
    codeControls.setup("code settings", "codeSettings.xml");
    codeControls.add(codeEnergyDecayRate);
    codeControls.add(codeEnergyPerFrame);
    codeControls.loadFromFile("codeSettings.xml");
    codeControls.setPosition(520+504+20, 500);
    
    startScene(currentScene);

    screenRect.set(0, 0, VISUALS_WIDTH+CODE_X_POS, VISUALS_HEIGHT);
    bShowCursor = true;
    ofAddListener(sync.ffwKeyPressed, this, &sceneManager::setAdvanceCurrentScene);
}
//-----------------------------------------------------------------------------------
void sceneManager::startScene(int whichScene){
    scenes[currentScene]->reset();
    TM.setup( (scenes[currentScene]), codeTweenDuration);
    lettersLastFrame = 0;
    lastPlayTime = 0;
    maxLetterX = 0;
    lastLetterY = 0;
#ifdef USE_MIDI_PARAM_SYNC
    for (auto param : scenes[currentScene]->midiParameters) {
        cout << param->getName() << endl;
    }
    sync.setSyncGroup(scenes[currentScene]->midiParameters, true);
    sync.enableMidi();
#endif
#ifdef USE_EXTERNAL_SOUNDS
    ofxOscMessage m;
    m.setAddress("/d4n/scene/load");
    m.addIntArg(currentScene);
    oscSender.sendMessage(m, false);
#endif
}
#ifdef USE_MIDI_PARAM_SYNC
//-----------------------------------------------------------------------------------
void sceneManager::recordingStart(){}
//-----------------------------------------------------------------------------------
void sceneManager::recordingEnd(){
    if (sync.recorder.isRecording()) {
        sync.recorder.stop();
    }
    if (sync.recorder.recData.size()) {
        scenes[currentScene]->setRecData(sync.recorder.recData);
        sync.recorder.recData.clear();
    }

}
//-----------------------------------------------------------------------------------
void sceneManager::startPlaying(){
    if(scenes[currentScene]->hasRecData()){
        sync.player.setData(scenes[currentScene]->getRecData());
        sync.player.play();
    }else{
        sync.player.clear();
    }
}
//-----------------------------------------------------------------------------------
void sceneManager::stopPlaying(){
    sync.player.stop();
}
#endif

//-----------------------------------------------------------------------------------
void sceneManager::update(){

    if (autoadvanceDelay > 0.001 && !scenes[currentScene]->isEndSet()) {
        if (lastAutoadvanceTime == 0) {
            lastAutoadvanceTime = ofGetElapsedTimef();
        }        
        if (ofGetElapsedTimef() - lastAutoadvanceTime > autoadvanceDelay) {
            advanceScene();
            lastAutoadvanceTime = ofGetElapsedTimef();
        }
    } else {
        if (bAutoAdvance && !sync.recorder.isRecording()) {
            if (scenes[currentScene]->isSceneDone()) {
                advanceScene();
            }
        }
        lastAutoadvanceTime = 0;
    }
    
    baseScene::smoothingSpeed = ofSmoothing;
    TM.animTime = codeTweenDuration;
    TM.energyDecayRate = codeEnergyDecayRate;
    TM.energyChangePerFrame = codeEnergyPerFrame;
    //the following is to avoid showing the mouse curson if it is over what's being drawn to the screens,
    //but showing it if not.
    bool bInside =screenRect.inside(ofGetMouseX(), ofGetMouseY()) ;
    if ( bInside && bShowCursor) {
        ofHideCursor();
        bShowCursor = false;
    }else if(!bInside && !bShowCursor){
        ofShowCursor();
        bShowCursor = true;
    }
    
#ifdef TYPE_ANIMATION
    pctDelay = (ofGetElapsedTimef() - TM.setupTime) / (TM.animTime);
    if (bSceneWaitForCode) {
        if (!shouldDrawScene && pctDelay > FADE_DELAY_MIN){
            shouldDrawScene = true;
            fadingIn = true;
#ifdef USE_EXTERNAL_SOUNDS
            oscMessage.clear();
            oscMessage.setAddress("/d4n/scene/start");
            oscMessage.addTriggerArg();
            oscSender.sendMessage(oscMessage, false);
#endif

        } else if (fadingIn && pctDelay > FADE_DELAY_MAX){
            fadingIn = false;
#ifdef USE_MIDI_PARAM_SYNC
            if (bAutoPlay) {
                startPlaying();
            }
#endif
        }
    } else {
        shouldDrawScene = true;
    }
#endif
    
    if (isTransitioning) {
        preTransitionPct = (ofGetElapsedTimef() - preTransitionStart) / sceneTweenDuration;
        fadingOut = false;
        introCursor = false;
        shouldDrawScene = false;
        shouldDrawCode = false;
        
        if (preTransitionPct >= 1.0) {
            isTransitioning = false;
            nextScene(true);
        } else if (preTransitionPct < SCENE_PRE_TRANSITION_FADE) {
            fadingOut = true;
            shouldDrawScene = true;
            shouldDrawCode = true;
        } else if (preTransitionPct > SCENE_PRE_TRANSITION_CURSOR) {
            introCursor = true;
        }
    }

    if (shouldDrawScene) {
#ifdef USE_MIDI_PARAM_SYNC
        scenes[currentScene]->updateMidiParams();
#endif
        scenes[currentScene]->update();
    }

    ofParameter < float > floatParam;

    if (TM.paramChangedEnergy.size() > 0) {
        
        for (int i = 0; i < TM.paramChangedEnergy.size(); i++) {
    
            if (TM.paramChangedEnergy[i] > 0) {
            
                ofParameter<float> t = scenes[currentScene]->parameters[i].cast<float>();

                float minVal = t.getMin();
                float maxVal = t.getMax();
                float val = t;
        
                float pct  = (t - minVal) / (float)(maxVal - minVal);
        
                if (pct > 1) pct = 1;
                if (pct < 0) pct = 0;

#ifdef USE_EXTERNAL_SOUNDS
                oscMessage.clear();
                oscMessage.setAddress("/d4n/paramEnergy");
                oscMessage.addFloatArg(TM.paramChangedEnergy[i] / 2.0);
                oscSender.sendMessage(oscMessage, false);

                oscMessage.clear();
                oscMessage.setAddress("/d4n/paramEnergyInverse");
                float arg = 1 - (TM.paramChangedEnergy[i] / 2.0);
                if (arg < 0.4) {
                    arg = 0;
                }
                oscMessage.addFloatArg(arg);
                oscSender.sendMessage(oscMessage, false);
                
                oscMessage.clear();
                oscMessage.setAddress("/d4n/param/"+ofToString((i % 2) + 1)+"/value");
                oscMessage.addFloatArg(pct);
                oscSender.sendMessage(oscMessage, false);
#endif
            }
        }
    } else {
#ifdef USE_EXTERNAL_SOUNDS
        oscMessage.clear();
        oscMessage.setAddress("/d4n/paramEnergy");
        oscMessage.addFloatArg(0);
        oscSender.sendMessage(oscMessage, false);
#endif
    }
    
    
}
//-----------------------------------------------------------------------------------
void sceneManager::setAdvanceCurrentScene(){
    scenes[currentScene]->setSceneEnd();
}
//-----------------------------------------------------------------------------------
void sceneManager::draw(){
    sync.update();
    codeFbo.begin();
    ofSetColor(255,255,255);
    float pct = (ofGetElapsedTimef() - TM.setupTime) / TM.animTime;
    
    if (pct > 1) pct = 1;
    if (pct < 0) pct = 0;
    
    if (pct < 0.5){
        pct *= 2;
        pct  = powf(pct, 3.0);
        pct *= 0.5;
    } else {
        
        pct -= 0.5;
        pct *= 2.0;
        pct  = powf(pct, 1.0/3.0);
        pct *= 0.5;
        pct += 0.5;
        
    }

    ofClear(0,0,0,255);
    vector < codeLetter > letters;
    if (shouldDrawCode)
        letters = TM.getCodeWithParamsReplaced(scenes[currentScene]);
    
    ofSetColor(255);
    //font.drawString(codeReplaced, 40, 40);
    //ofDrawBitmapString(codeReplaced, 40,40);
    
    
    bool bShiftUp = false, bShiftLeft = false;
    
    if (lastLetterY > (VISUALS_HEIGHT-20)) {
        bShiftUp = true;
    }

    if (maxLetterX > (VISUALS_WIDTH-20)) {
        bShiftLeft = true;
    }
    
    if (bShiftUp && !introCursor) {
        float dy = lastLetterY - (VISUALS_HEIGHT-20);
        ofPushMatrix();
        ofTranslate(0,-dy);
    }

    if (bShiftLeft && !introCursor) {
        float dx = maxLetterX - (VISUALS_WIDTH-20);
        dx = min((int)dx, 20);
        ofPushMatrix();
        ofTranslate(-dx,0);
    }

    const int codeDefaultStartX = 40;
    int countLetters = 0;
    int xStart = codeDefaultStartX;
    int x = xStart;
    
    // Quick cache of how many lines we're going to draw
    int nLines = 0, currentLine = 0;
    float maxActivationPerLine = 0, maxTotalActivation = 0;
    
    // One entry per line, stores id of param that is getting animated the most
    vector<int> lineHasAnimParam;

    lineHasAnimParam.push_back(-1);
    for (int i = 0; i < letters.size() * pct; i++) {
        if (letters[i].type == CHARACTER_PARAM) {
            float activation = TM.paramEnergy[letters[i].idOfChar];
            if (activation > 0.000001 && activation > maxActivationPerLine) {
                maxActivationPerLine = activation;
                lineHasAnimParam[currentLine] = letters[i].idOfChar;
            }
            if (activation > 0.000001 && activation > maxTotalActivation) {
                maxTotalActivation = activation;
            }
        }

        if (letters[i].character == '\n') {
            currentLine++;
            nLines++;
            maxActivationPerLine = 0;
            lineHasAnimParam.push_back(-1);
        }
    }

    // Set line Y based on how many lines we're going to draw over the total height
    int maxLinesWithoutScroll = (VISUALS_HEIGHT - 60*2) / 13;
    int maxLinesWithScroll = (VISUALS_HEIGHT-10*2) / 13;
    int y;
    
    if (nLines <= maxLinesWithoutScroll) {
        y = 60 + 13;
    } else if (nLines <= maxLinesWithScroll) {
        y = 60 + 13 + (maxLinesWithoutScroll - nLines + 1) * 13;
    } else {
        y = 10 + 13;
    }
    
    const int lineWithActiveParamDim = 60;
    const int lineWithoutActiveParamDim = 100;
    const int commentDim = 70;
    currentLine = 0;
    bool nonEmptyLetter = false;
    
    for (int i = 0; i < letters.size() * pct; i++){
        
        int lineBrightness = 127;
        if (lineHasAnimParam[currentLine] < 0) {
            lineBrightness -= maxTotalActivation * lineWithoutActiveParamDim;
        } else {
            float currActivation = TM.paramEnergy[lineHasAnimParam[currentLine]];
            lineBrightness -= (maxTotalActivation - currActivation) * lineWithActiveParamDim;
        }
        
        ofSetColor(127);
        if (letters[i].type == CHARACTER_CODE) {
            ofSetColor(lineBrightness);
        } else if (letters[i].type == CHARACTER_PARAM) {
            int charBrightness = TM.paramEnergy[letters[i].idOfChar]*(255-lineWithActiveParamDim);
            ofSetColor(min(lineBrightness + charBrightness, 255));
        } else if (letters[i].type == CHARACTER_COMMENT) {
            ofSetColor(max(lineBrightness - commentDim * (1.0-maxTotalActivation), 0.0));
        }
    
        string s = "";
        s += (char)(letters[i].character);
        font.drawString(s , (int)x, (int)y);
        
        
        if (letters[i].character != ' ' &&
            letters[i].character != '\n' &&
            letters[i].character != '\t') {
            countLetters++;
            nonEmptyLetter = true;
        }
        
        x += 7;
        if (letters[i].character == '\n'){
            y += 13;
            x = xStart;
            currentLine++;
        }
        
        maxLetterX = max((int)maxLetterX, x);
        lastLetterY = y;
    }
    
    bool drawCursor = false;
    
    // Decide if we're going to draw a cursor
    if (!isTransitioning) {
        if (pct < 0.1) {
            drawCursor = int(letters.size() * pct) % 2 == 0;
        } else if (pct > 0.1 && pct < 1) {
            drawCursor = true;
        } else if (pctDelay > 1 && !shouldDrawScene) {
            x = xStart;
            y += 13;
            drawCursor = (int)((pctDelay * TM.animTime) / 0.2) % 2 == 1;
        }

        if (!nonEmptyLetter) drawCursor = false;
        if (!(x != xStart || pctDelay > 1)) drawCursor = false;
    } else if (isTransitioning && introCursor) {
        x = codeDefaultStartX;
        y = 60 + 13;
        drawCursor = (int)((preTransitionPct * sceneTweenDuration) / 0.2) % 2 == 0;
    }
    
    // Draw that cursor
    if (drawCursor) {
        ofSetColor(140);
        ofDrawRectangle(x, y-10, 7, 13);
    }
    
    if (bShiftLeft){
        ofPopMatrix();
    }
        
    if (bShiftUp){
        ofPopMatrix();
    }

    codeFbo.end();
    
    // Get rid of blended sidebars
    ofSetColor(0);
    ofDrawRectangle(CODE_X_POS-1, 0, VISUALS_WIDTH+2, VISUALS_HEIGHT);
    ofSetColor(255);
    codeFbo.draw(CODE_X_POS, 0, VISUALS_WIDTH, VISUALS_HEIGHT);

    if (shouldDrawScene) {
        sceneFbo.begin();
        ofClear(0,0,0,255);
        ofPushStyle();
        scenes[currentScene]->draw();
        ofPopStyle();
        sceneFbo.end();
        
        // For sound and for kicks
        computeMotion(sceneFbo);

        // Draw twice to make the background go away
        sceneFbo.draw(1,0,VISUALS_WIDTH, VISUALS_HEIGHT);
        sceneFbo.draw(0,0,VISUALS_WIDTH, VISUALS_HEIGHT);

        if (fadingIn) {
            float fadeOpacityRaw = ofMap(pctDelay, FADE_DELAY_MIN, FADE_DELAY_MAX, 0, PI);
            float fadeOpacityShaped = ofMap(cos(fadeOpacityRaw), 0, 1, 0, 255);
            ofSetColor(0, fadeOpacityShaped);
            ofFill();
            ofDrawRectangle(0, 0, VISUALS_WIDTH+1, VISUALS_HEIGHT);
        }
    } else {
        ofSetColor(0);
        ofFill();
        ofClearAlpha();
        ofDrawRectangle(0, 0, VISUALS_WIDTH+1, VISUALS_HEIGHT);
    }

    // Draw overlay rectangles on fade out
    if (isTransitioning && fadingOut) {
        float fadeOpacityRaw = ofMap(preTransitionPct, 0, SCENE_PRE_TRANSITION_FADE, 0, 1);
        ofSetColor(0, ofClamp(fadeOpacityRaw * 255, 0, 255));
        ofFill();
        
        // Draw over the frames
        ofDrawRectangle(0, 0, VISUALS_WIDTH+1, VISUALS_HEIGHT);
        ofDrawRectangle(CODE_X_POS-1, 0, VISUALS_WIDTH+2, VISUALS_HEIGHT);
    }

  
#ifdef TYPE_ANIMATION
    if (!shouldDrawScene){
        ofSetColor(0,1);
        ofFill();
        ofDrawRectangle(0,0,VISUALS_WIDTH, VISUALS_HEIGHT);
        int diff = (countLetters - (int)lettersLastFrame);
        if (diff > 0 && (ofGetElapsedTimeMillis()-lastPlayTime > ofRandom(50,87))) {
            lastPlayTime = ofGetElapsedTimeMillis();
            
#ifdef USE_EXTERNAL_SOUNDS
            if (ofNoise(pct*10, ofGetElapsedTimef()/10.0) > 0.5) {
                oscMessage.clear();
                oscMessage.setAddress("/d4n/keystroke");
                oscMessage.addIntArg(roundf(ofRandom(1,2)));
                oscSender.sendMessage(oscMessage, false);
            } else {
                oscMessage.clear();
                oscMessage.setAddress("/d4n/keystroke");
                oscMessage.addIntArg(roundf(ofRandom(3,4)));
                oscSender.sendMessage(oscMessage, false);
            }
#endif
        }
        lettersLastFrame = countLetters;
        
    }
#endif

    panel->draw();
    codeControls.draw();
    
    gui.draw();
    
    
    // let's draw some info!
    
    ofSetColor(255);
    
    ofDrawBitmapString("drawing scene " + ofToString(currentScene) +
                       "/" + ofToString(scenes.size()) +
                       "\t\t(" + scenes[currentScene]->author  + ", " +
                       scenes[currentScene]->originalArtist + ")",
                       20, VISUALS_HEIGHT + 50);

    
    string str = "Recorded events: " + ofToString(sync.recorder.getData().size())+"\n";
    str += "Is Recording: " + (string)(sync.recorder.isRecording()?"TRUE":"FALSE")+"\n";
    str += "Play events: " + ofToString(sync.player.data.size())+"\n";
    str += "Is Playing: " + (string)(sync.player.bPlaying?"TRUE":"FALSE")+"\n";
    str += "Pre-recorded events: " + ofToString(scenes[currentScene]->recData.size());
    
    ofDrawBitmapString(str, 20, VISUALS_HEIGHT + 100);
}

void sceneManager::computeMotion(ofFbo &fbo) {
    fbo.readToPixels(currFrame);

    const unsigned char *currPixels = currFrame.getData();
    const unsigned char *lastPixels = lastFrame.getData();
    
    long long sumX = 0, sumY = 0, sumMotion = 0, totalMotion = 1, totalThresh = 1;
    for (int i = 0; i < VISUALS_WIDTH * VISUALS_HEIGHT * 4; i += 4) {
        int val = (currPixels[i] + currPixels[i+1] + currPixels[i+2]) / 3;
        int lastVal = (lastPixels[i] + lastPixels[i+1] + lastPixels[i+2]) / 3;

        sumMotion += abs(val - lastVal);
        totalMotion++;

        if (val > 127) {
            int x = (i / 4) % VISUALS_WIDTH;
            int y = (i / 4) / VISUALS_WIDTH;
            
            sumX += x;
            sumY += y;
            totalThresh++;
        }
    }

    lastCentroid.set(centroid);
    centroid.set(sumX / totalThresh, sumY / totalThresh);
    
    float currMotion = ((float)sumMotion / totalMotion) / 255.0;
    float shapedMotion = sqrt(currMotion);
    motion += (shapedMotion - motion) * 0.1;
    
#ifdef USE_EXTERNAL_SOUNDS
    oscMessage.clear();
    oscMessage.setAddress("/d4n/motion");
    oscMessage.addFloatArg(motion);
    oscMessage.addFloatArg(centroid.x);
    oscMessage.addFloatArg(centroid.y);
    oscMessage.addFloatArg(centroid.x - lastCentroid.x);
    oscMessage.addFloatArg(centroid.y - lastCentroid.y);
    oscSender.sendMessage(oscMessage, false);
#endif
    
    currFrame.pasteInto(lastFrame, 0, 0);
}

//-----------------------------------------------------------------------------------
void sceneManager::nextScene(bool forward){
#ifdef USE_MIDI_PARAM_SYNC
    recordingEnd();
#endif

    if (forward){
        currentScene ++;
        currentScene %= scenes.size();
    } else {
        currentScene --;
        if (currentScene < 0){
            currentScene = scenes.size() - 1;
        }
    }
    
#ifdef TYPE_ANIMATION
    shouldDrawScene = false;
#else
    shouldDrawScene = true
#endif

    isTransitioning = false;
    shouldDrawCode = true;

    startScene(currentScene);

    panel->clear();
    panel->setup("scene settings");
    panel->add(scenes[currentScene]->parameters);
    
    panel->setPosition(520+504+20, 20);
};
//-----------------------------------------------------------------------------------
void sceneManager::advanceScene(){
    stopPlaying();

    if (bFadeOut) {
        if (!isTransitioning) {
            isTransitioning = true;
            preTransitionStart = ofGetElapsedTimef();
            preTransitionPct = 0;
        } else {
            isTransitioning = false;
            nextScene(true);
        }
    } else {
        nextScene(true);
    }
};
//-----------------------------------------------------------------------------------
void sceneManager::regressScene(){
    stopPlaying();
    nextScene(false);
};
//-----------------------------------------------------------------------------------
void sceneManager::screenGrab() {
    string path = "screengrabs/";
    ofImage sceneImg;
    ofImage codeImg;
    
    sceneFbo.readToPixels(sceneImg.getPixels());
    codeFbo.readToPixels(codeImg.getPixels());
    
    sceneImg.save(path+ofGetTimestampString()+"_scene.png");
    codeImg.save(path+ofGetTimestampString()+"_code.png");
    
}
//-----------------------------------------------------------------------------------
