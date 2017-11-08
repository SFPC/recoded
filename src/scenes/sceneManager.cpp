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
#include "andyMenkmanJpg.h"
#include "andyMenkmanPng.h"
#include "andyMenkmanTif.h"
#include "CooperBauhaus.h"
#include "memoAktenScene.h"
#include "submotionOrchestraScene.h"
#include "chrisMurielCooper.h"
#include "chrisRileyCascando.h"
#include "veraMolnarTrapezium.h"
#include "manfredMohrP196A.h"
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
// #include "alexGifPaletteDitherMenkman.h"
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
#include "zachTest.h"
#include "heatherMolnarScene.h"
#include "yingTanWhitneyMatrix.h"
#include "annMolnarRectangles.h"
#include "weiWhitney.h"
#include "yumiNishida01.h"
#include "testingScene.h"

//SCRIPT_PLACEHOLDER_INCLUDE -- DO NOT REMOVE THIS LINE. PLACE INCLUDES ABOVE. 

float baseScene::smoothingSpeed = 0.02;

//-----------------------------------------------------------------------------------
sceneManager::~sceneManager(){
    ofRemoveListener(sync.ffwKeyPressed, this, &sceneManager::setAdvanceCurrentScene);
}
//-----------------------------------------------------------------------------------
void sceneManager::setup(){
    
    font.load("fonts/ProggySmall.fon", 8, false ,false, false, 0, 96);
    //SCRIPT_PLACEHOLDER_PUSH_SCENE -- DO NOT REMOVE OR MOVE THIS LINE 

    scenes.push_back(new testingScene());
    scenes.push_back(new yingTanWhitneyMatrix());
    scenes.push_back(new annMolnarRectangles());
    scenes.push_back(new weiWhitney());
    scenes.push_back(new yumiNishida01());
    scenes.push_back(new zachTest());
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
    scenes.push_back(new andyMenkmanJpg());
    scenes.push_back(new andyMenkmanPng());
    scenes.push_back(new manfredMohrP196A());
    scenes.push_back(new veraMolnarTrapezium());
    scenes.push_back(new loloVera2());
    scenes.push_back(new cantusFirmusRiley());
    scenes.push_back(new aaronMarcusHieroglyphB());
    //scenes.push_back(new veraMolnarLines68());
    scenes.push_back(new alexLissamojiWhitney());
    scenes.push_back(new yosukeVeraSansTitre());
    //scenes.push_back(new alexGifPaletteDitherMenkman());
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
    scenes.push_back(new heatherMolnarScene());

    // Too slow
//     scenes.push_back(new andyMenkmanTif());
  
    // Duplicate with rodrigoBelfort
    // scenes.push_back(new janVantommeScene());

#ifdef RANDOMIZE_SCENES
    ofRandomize(scenes);
#endif
    
#ifdef USE_MIDI_PARAM_SYNC
    sync.setup(0);
    
    // Disable MIDI smoothing by default
    sync.smoothing.set(0);

    ofAddListener(sync.player.playE, this, &sceneManager::startPlaying);
    ofAddListener(sync.recorder.recStartE, this, &sceneManager::recordingStart);
    ofAddListener(sync.recorder.recEndE, this, &sceneManager::recordingEnd);
#endif
    
    // Not using
    // scenes.push_back(new chrisMurielCooper());
    gui.setDefaultWidth(300);    
    gui.setup("SFPC_d4n", "SFPC_d4n_general_settings.xml");

    gui.add(enableParameterSounds.set("Enable parameter sounds", true));
    enableParameterSounds.addListener(this, &sceneManager::toggleParameterSounds);
    gui.add(drawScenePanel.set("draw scene ctrl", true));
    gui.add(enableMidiUpdate.set("enable midi update", true));
    gui.add(bAutoPlay.set("Auto Play on scene change", true));
    gui.add(autoadvanceDelay.set("Autoadvance", 0, 0, 60));
    gui.add(bSceneWaitForCode.set("Scene wait for code", true));
    gui.add(bFadeOut.set("Scene fade out", true));
    gui.add(bAutoAdvance.set("Auto Advance Scene", true));
#ifdef USE_SCENE_TRANSITIONS
    gui.add(sceneTweenDuration.set("fadeOutTime", 4.0, 0, 10.0));
    gui.add(codeTweenDuration.set("fadeInTime", 7.5, 0, 15));
#endif
    sync.smoothing.setName("MIDI Smoothing");
    gui.add(sync.smoothing);
    gui.add(ofSmoothing.set("OF Smoothing", 0.02, 0.01, 1));
    
    
    gui.loadFromFile("SFPC_d4n_general_settings.xml");
//    gui.setWidthElements(300);
//    gui.setDefaultWidth(300);
    gui.setPosition(ofGetWidth() - gui.getShape().width-20,  ofGetHeight() - gui.getShape().getHeight() - 100);
    
    
    sceneFbo.allocate(VISUALS_WIDTH, VISUALS_HEIGHT, GL_RGBA, 4);
  //dimmedSceneFbo.allocate(VISUALS_WIDTH, VISUALS_HEIGHT, GL_RGBA, 4);
    codeFbo.allocate(VISUALS_WIDTH, VISUALS_HEIGHT, GL_RGB, 1);
    
    codeFbo.getTexture().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
    
  //dimmerShader.load("scenes/dimmer");

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
#else
    loadSounds();
    
    parameterChangeSound.setLoop(true);
    if (enableParameterSounds.get()) {
        parameterChangeSound.play();
    }
    parameterChangeSound.setVolume(0);
    
    TM.loadSounds();
#endif
    
    // disney
    for (auto scene : scenes){
        scene->dimensions.set(0,0,VISUALS_WIDTH, VISUALS_HEIGHT);
        scene->setup();
        scene->enableMidi();
        scene->postSetup();
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
    scenes[currentScene]->resetTiming();
    scenes[currentScene]->reset();
    TM.setup( (scenes[currentScene]), codeTweenDuration);
    lettersLastFrame = 0;
    lastPlayTime = 0;
    maxLetterX = 0;
    lastLetterY = 0;
#ifdef USE_MIDI_PARAM_SYNC
    sync.setSyncGroup(scenes[currentScene]->midiParameters, true);
    isMidiConnected = sync.enableMidi();
#endif
//#ifdef USE_EXTERNAL_SOUNDS
//    oscMessage.clear();
//    oscMessage.setAddress("/d4n/scene/load");
//    oscMessage.addIntArg(currentScene);
//    oscSender.sendMessage(oscMessage, false);
//#else
//#endif
    // TODO
    
}
#ifdef USE_MIDI_PARAM_SYNC
//-----------------------------------------------------------------------------------
void sceneManager::recordingStart(){
    scenes[currentScene]->reset();
    scenes[currentScene]->resetTiming();
}
//-----------------------------------------------------------------------------------
void sceneManager::recordingEnd(){
    if (sync.recorder.isRecording()) {
        sync.recorder.stop();
    }
    if (sync.recorder.recData.size()) {
        scenes[currentScene]->setSceneEnd();
        scenes[currentScene]->setRecData(sync.recorder.recData);
        sync.recorder.recData.clear();
    }

}
void sceneManager::toggleParameterSounds(bool &i){
    parameterChangeSound.setPaused(!enableParameterSounds);
}

//-----------------------------------------------------------------------------------
void sceneManager::startPlaying(){
    if(scenes[currentScene]->hasRecData()){
        scenes[currentScene]->resetTiming();
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
            if (!isTransitioning && scenes[currentScene]->isSceneDone()) {
                advanceScene();
            }
        }
        lastAutoadvanceTime = 0;
    }
    
    baseScene::smoothingSpeed = ofSmoothing;
    TM.animTime = codeTweenDuration;
    TM.energyDecayRate = codeEnergyDecayRate;
    TM.energyChangePerFrame = codeEnergyPerFrame;
    //the following is to avoid showing the mouse cursor if it is over what's being drawn to the screens,
    //but showing it if not.
    bool bInside =screenRect.inside(ofGetMouseX(), ofGetMouseY()) ;
    if ( bInside && bShowCursor) {
        ofHideCursor();
        bShowCursor = false;
    } else if(!bInside && !bShowCursor){
        ofShowCursor();
        bShowCursor = true;
    }
    
    
#ifdef TYPE_ANIMATION
    pctDelay = (ofGetElapsedTimef() - TM.setupTime) / (TM.animTime);
    if (bSceneWaitForCode) {
        if (!isTransitioning && !shouldDrawScene && pctDelay > FADE_DELAY_MIN){
            shouldDrawScene = true;
            fadingIn = true;
#ifdef USE_EXTERNAL_SOUNDS
            oscMessage.clear();
            oscMessage.setAddress("/d4n/scene/start");
            oscMessage.addIntArg(1);
            oscSender.sendMessage(oscMessage, false);
#else
            animationStartSound.play();
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
        shouldDrawScene = false;
        shouldDrawCode = false;
        shouldPlaySceneChangeSound = false;

        if (preTransitionPct >= 1.0) {
            isTransitioning = false;
            introCursor = false;
            nextScene(true);
        } else if (preTransitionPct < SCENE_PRE_TRANSITION_FADE) {
            fadingOut = true;
            shouldDrawScene = true;
            shouldDrawCode = true;
            hasTriggeredSceneChangeSound = false;
//        } else if (preTransitionPct > SCENE_PRE_TRANSITION_SOUND) {
//            if (!hasTriggeredSceneChangeSound) {
//                //shouldPlaySceneChangeSound = true;
//            }
        } else if (preTransitionPct > SCENE_PRE_TRANSITION_CURSOR) {
            introCursor = true;
        }
    }

    if (shouldDrawScene) {
#ifdef USE_MIDI_PARAM_SYNC
        if (enableMidiUpdate.get() && scenes[currentScene]->recData.size()){
            if(scenes[currentScene]->bAnimateScene){
                scenes[currentScene]->updateMidiParams();
            }
        }
#endif
        scenes[currentScene]->update();
    }
    
#ifdef USE_EXTERNAL_SOUNDS
    oscMessage.clear();
    oscMessage.setAddress("/d4n/scene/start");
    oscMessage.addIntArg(1);
    oscSender.sendMessage(oscMessage, false);
#else
    if (shouldPlaySceneChangeSound) {
        sceneChangeSound.play();
        hasTriggeredSceneChangeSound = true;
    }
#endif
    
    ofParameter < float > floatParam;

    float maxActivation = 0, maxPct;
    if (shouldDrawScene && TM.paramEnergy.size() > 0) {
        
        for (int i = 0; i < TM.paramEnergy.size(); i++) {
    
            if (TM.paramEnergy[i] > 0) {
                ofParameter<float> t = scenes[currentScene]->parameters[i].cast<float>();
                float minVal = t.getMin();
                float maxVal = t.getMax();
                float val = t;

                float pct  = (t - minVal) / (float)(maxVal - minVal);

                if (pct > 1) pct = 1;
                if (pct < 0) pct = 0;
                if (pct > maxActivation)
                    maxPct = pct;
                if (TM.paramChangedEnergy[i] > maxActivation)
                    maxActivation = TM.paramChangedEnergy[i];
            }
        }
        
        float vol;
        float maxVol = 0.5;
        if (isTransitioning) {
            vol = ofMap(preTransitionPct, 0, 0.2, maxVol, 0, true);
        }

        if (maxActivation > 0.1) {
            if (!isTransitioning) {
                vol = ofMap(maxActivation, 0.1, 1, 0, maxVol, true);
            }
            parameterChangeSound.setVolume(vol);
            parameterChangeSound.setSpeed(ofMap(maxActivation, 0, 1, 0.4, 1.0));
        } else {
            parameterChangeSound.setVolume(0);
        }
    } else {
#ifdef USE_EXTERNAL_SOUNDS
        oscMessage.clear();
        oscMessage.setAddress("/d4n/paramEnergy");
        oscMessage.addFloatArg(0);
        oscSender.sendMessage(oscMessage, false);
#else
        parameterChangeSound.setVolume(0);
#endif
    }
    
    
}
//-----------------------------------------------------------------------------------
void sceneManager::setAdvanceCurrentScene(){
    scenes[currentScene]->setSceneEnd();
    parameterChangeSound.setVolume(0);
}

void sceneManager::drawType(){
    ofSetColor(0);
    ofDrawRectangle(CODE_X_POS-1, 0, VISUALS_WIDTH+2, VISUALS_HEIGHT);
    ofSetColor(255);
    codeFbo.draw(CODE_X_POS, 0, VISUALS_WIDTH, VISUALS_HEIGHT);
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
    
    const int lineWithActiveParamDim = 120;
    const int lineWithoutActiveParamDim = 130;
    const int commentDim = 70;
    currentLine = 0;
    bool nonEmptyLetter = false;
    
    for (int i = 0; i < letters.size() * pct; i++){
        
        int lineBrightness = 165;
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
    
    bool drawCursor, soundCursor = false;
    
    // Decide if we're going to draw a cursor
    if (!isTransitioning) {
        if (pct < 0.1) {
            drawCursor = int(letters.size() * pct) % 3 == 0;
        } else if (pct > 0.1 && pct < 1) {
            drawCursor = true;
        } else if (pctDelay > 1) {
            x = xStart;
            y += 13;
            drawCursor = (int)((pctDelay * TM.animTime) / 0.2) % 3 == 1;
            soundCursor = drawCursor;
        }

        if (!nonEmptyLetter) drawCursor = false;
        if (!(x != xStart || pctDelay > 1)) drawCursor = false;
    }
    if (isTransitioning && introCursor) {
        x = codeDefaultStartX;
        y = 60 + 13;
        soundCursor = drawCursor = (int)((preTransitionPct * sceneTweenDuration) / 0.2) % 3 == 1;
    }
    
    // Draw that cursor
    if (drawCursor && !shouldDrawScene) {
        ofSetColor(140);
        ofDrawRectangle(x, y-10, 7, 13);
    }
    
    if (soundCursor && !shouldDrawScene) {
        if (!hasTriggeredCursorSound) {
            triggerCursorSound();
            hasTriggeredCursorSound = true;
        }
    } else {
        hasTriggeredCursorSound = false;
    }
    
    if (bShiftLeft){
        ofPopMatrix();
    }
        
    if (bShiftUp){
        ofPopMatrix();
    }

    codeFbo.end();
    

    if (shouldDrawScene) {
        sceneFbo.begin();
        ofClear(0,0,0,255);
        ofPushStyle();
        scenes[currentScene]->draw();
        ofPopStyle();
        sceneFbo.end();
        
        // For sound and for kicks
        //computeMotion(sceneFbo);
//
//        float dimAmt = 1;
//        if (frameBrightness > 0.5) {
//            dimAmt = ofMap(frameBrightness, 0.5, 1, 1, 0.5);
//        }

//        dimmedSceneFbo.begin();
//        dimmerShader.begin();
//        dimmerShader.setUniformTexture("texture0", sceneFbo.getTexture(), 0);
//        dimmerShader.setUniform1f("dimAmt", dimAmt);
//        ofSetColor(255);
//        ofClearAlpha();
//        ofDrawRectangle(0, 0, VISUALS_WIDTH, VISUALS_HEIGHT);
//        dimmerShader.end();
//        dimmedSceneFbo.end();
//        dimmedSceneFbo.draw(1,0,VISUALS_WIDTH, VISUALS_HEIGHT);
//        dimmedSceneFbo.draw(0,0,VISUALS_WIDTH, VISUALS_HEIGHT);
      sceneFbo.draw(0,0,VISUALS_WIDTH, VISUALS_HEIGHT);
      //sceneFbo.draw(0,1,VISUALS_WIDTH, VISUALS_HEIGHT);
      
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
#else
            if (ofNoise(pct*10, ofGetElapsedTimef()/10.0) > 0.5){
                TM.keystroke2Sound.play();
                TM.keystroke2Sound.setSpeed(ofRandom(0.9, 1.1));
                
            } else {
                TM.keystroke1Sound.play();
                TM.keystroke1Sound.setSpeed(ofRandom(0.9, 1.1));
            }
#endif
        }
        lettersLastFrame = countLetters;
        
    }
#endif

    if (drawScenePanel)
        panel->draw();
    codeControls.draw();
    
    gui.draw();
    
    
    // let's draw some info!
    
ofSetColor(255);
//    
//    ofDrawBitmapString("drawing scene " + ofToString(currentScene) +
//                       "/" + ofToString(scenes.size()) +
//                       "\t\t(" + scenes[currentScene]->author  + ", " +
//                       scenes[currentScene]->originalArtist + ")",
//                       20, VISUALS_HEIGHT + 50);
//
//    
//    string str = "Recorded events: " + ofToString(sync.recorder.getData().size())+"\n";
//    str += "Is Recording: " + (string)(sync.recorder.isRecording()?"TRUE":"FALSE")+"\n";
//    str += "Play events: " + ofToString(sync.player.data.size())+"\n";
//    str += "Is Playing: " + (string)(sync.player.bPlaying?"TRUE":"FALSE")+"\n";
//    str += "Pre-recorded events: " + ofToString(scenes[currentScene]->recData.size())+"\n";
//    str += "Current Scene Time: " + ofToString(scenes[currentScene]->getElapsedTimef())+"\n";
//    str += "Current Scene Duration: " + ofToString(scenes[currentScene]->sceneDuration)+"\n";
//    str += "Current Scene is done: " + (string)(scenes[currentScene]->isSceneDone()?"TRUE":"FALSE");
//    
//    ofDrawBitmapString(str, 20, VISUALS_HEIGHT + 100);
}

//void sceneManager::computeMotion(ofFbo &fbo) {
//    fbo.readToPixels(currFrame);
//
//    const unsigned char *currPixels = currFrame.getData();
//    const unsigned char *lastPixels = lastFrame.getData();
//    
//    long long sumX = 0, sumY = 0, sumMotion = 0, sumBrightness = 0, totalPixels = 1, totalThresh = 1;
//    for (int i = 0; i < VISUALS_WIDTH * VISUALS_HEIGHT * 4; i += 4) {
//        int val = (currPixels[i] + currPixels[i+1] + currPixels[i+2]) / 3;
//        int lastVal = (lastPixels[i] + lastPixels[i+1] + lastPixels[i+2]) / 3;
//
//        sumBrightness += val;
//        sumMotion += abs(val - lastVal);
//        totalPixels++;
//
//        if (val > 127) {
//            int x = (i / 4) % VISUALS_WIDTH;
//            int y = (i / 4) / VISUALS_WIDTH;
//            
//            sumX += x;
//            sumY += y;
//            totalThresh++;
//        }
//    }
//
//    lastCentroid.set(centroid);
//    centroid.set(sumX / totalThresh, sumY / totalThresh);
//    
//    frameBrightness = ((float)sumBrightness / totalPixels) / 255.0;
//    
//    float currMotion = ((float)sumMotion / totalPixels) / 255.0;
//    float shapedMotion = sqrt(currMotion);
//    motion += (shapedMotion - motion) * 0.1;
//    
//#ifdef USE_EXTERNAL_SOUNDS
////    oscMessage.clear();
////    oscMessage.setAddress("/d4n/motion");
////    oscMessage.addFloatArg(motion);
////    oscMessage.addFloatArg(centroid.x);
////    oscMessage.addFloatArg(centroid.y);
////    oscMessage.addFloatArg(centroid.x - lastCentroid.x);
////    oscMessage.addFloatArg(centroid.y - lastCentroid.y);
////    oscSender.sendMessage(oscMessage, false);
//#endif
//    
//    currFrame.pasteInto(lastFrame, 0, 0);
//}

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
    
    parameterChangeSound.setVolume(0);
    
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
    parameterChangeSound.setVolume(0);
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
void sceneManager::loadSounds() {
    string path = "sounds/";
    sceneChangeSound.load(path+"sceneChange.aiff");
    
    cursorBlinkSound.load(path+"cursorBlink1.aiff");
    cursorBlinkSound.setLoop(false);
    cursorBlinkSound.setMultiPlay(false);


    animationStartSound.load(path+"animationStart.aiff");
    
    parameterChangeSound.load(path+"parameterChange.aiff");
    parameterChangeSound.setMultiPlay(false);
}
//-----------------------------------------------------------------------------------
void sceneManager::triggerCursorSound() {
#ifdef USE_EXTERNAL_SOUNDS
    ofxOscMessage oscMessage;
    oscMessage.clear();
    oscMessage.setAddress("/d4n/cursor");
    oscMessage.addTriggerArg();
    oscSender.sendMessage(oscMessage, false);
#else
    cursorBlinkSound.play();
#endif
}



