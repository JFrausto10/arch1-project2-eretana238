#include <msp430.h>
#include "soundEngine.h"
#include "stateMachines.h"
#include "buzzer.h"

unsigned short c4,cs4,d4,ds4,e4,f4,fs4,g4,gs4,a4,as4,b4,c5,cs5,d5,ds5,e5,f5,fs5,g5,gs5,a5,as5,b5; 
/* all notes, chromatic scale of 2 octaves */

unsigned char song_selection = 0;
unsigned char song_state = 0;

short secrets[65] = {d4,fs4,a4,fs4,a4,fs4,d4,fs4,d4,fs4,a4,fs4,a4,fs4,d4,fs4,c4,fs4,a4,fs4,a4,fs4,c4,fs4,c4,fs4,a4,fs4,a4,fs4,c4,fs4}

void song_state_reset() {
    song_state = 0;
}

void soundEngine_init() {
    c4 = 262;
    cs4 = 279;
    d4 = 294;
    ds4 = 311;
    e4 = 330;
    f4 = 349;
    fs4 = 370;
    g4 = 392;
    gs4 = 415;
    a4 = 440;
    as4 = 466;
    b4 = 494;
    c5 = 523;
    cs5 = 554;
    d5 = 587;
    ds5 = 622;
    e5 = 659;
    f5 = 699;
    fs5 = 740;
    g5 = 784;
    gs5 = 831;
    a5 = 880;
    as5 = 932;
    b5 = 988;
}

void play_song() {
    if(song_state > 65)
        song_state_reset();
        
    buzzer_set_period(secrets[song_state]);
    song_state++;
}