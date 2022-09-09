#pragma once

#define AUDIO_DAC_SAMPLE_MAX 4095U

#ifdef AUDIO_ENABLE
    #define AUDIO_INIT_DELAY
    #define STARTUP_SONG SONG(MARIO_MUSHROOM)
    #define ADJUST_SONG SONG(ZELDA_PUZZLE)
    #define CAPSLOCK_ON_SONG SONG(MARIO_MUSHROOM)
    #define CAPSLOCK_OFF_SONG SONG(CAPS_LOCK_OFF_SOUND)
    #define WIN_SONG SONG(ONE_UP_SOUND)
    #define MAC_SONG SONG(ZELDA_TREASURE)
#endif

/*
 * MIDI options
 */

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4

