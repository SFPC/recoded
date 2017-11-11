
#pragma once



// this is for scenes with zz
// https://www.instagram.com/zzdesign/
//#define SHOW_MSOFT_LUNCHTIME


//this shows the skketches from SFPC fall 2017 class
#define SHOW_SFPC_FALL_2017


//THis will show all the other sketches; the ones that are not either for microsoft lunch or by sfpc2017
#define SHOW_OTHERS

// assume that visuals and code are the same here....
// and also assuming our screen is square :)

#define VISUALS_WIDTH 504
#define VISUALS_HEIGHT 504

#define CODE_WIDTH VISUALS_WIDTH
#define CODE_HEIGHT VISUALS_HEIGHT



#define BIG_TV                  // for 1920 x 1080 TV :)



#define DRAW_TWO_UP       // draw two side by side in a 1920x1080 window
//#define DRAW_ONE_BIG      // draw one of these big centered in the screen

//#define RANDOMIZE_SCENES    // shuffle the order of the scenes upon startup

//#define


// TWO UP
#ifdef DRAW_TWO_UP
#define CODE_X_POS 504      // TV
#elif defined DRAW_ONE_BIG
#define CODE_X_POS 3000     // OFFSCREEN
#else
#define CODE_X_POS 504  // LED
#endif


// ONE BIG (move offscreen) 
// move code offscreen for now (we should fix this
#ifdef DRAW_ONE_BIG
#define CODE_X_POS 3000      // via the tech staff
#endif


// if this is defined, we will wait for type animation
#define TYPE_ANIMATION

#define USE_MIDI_PARAM_SYNC
// this is used to enable recording/playback of midi data.
#define USE_MIDI_RECORDING

#define USE_SCENE_TRANSITIONS



// if this is defined, we will disable all sound playback inside this app, and instead send
// OpenSoundControl messages which can be used to trigger sounds in another program (e.g. Ableton Live)
//#define USE_EXTERNAL_SOUNDS

#define OSC_HOST "localhost" // send to this host
#define OSC_PORT 12345       // send on this port

#define USE_SERIAL // Uncomment this line to use serial/talk to arduino
