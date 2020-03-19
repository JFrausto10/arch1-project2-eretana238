#ifndef soundEngine_included
#define soundEngine_included

char c4,cs4,d4,ds4,e4,f4,fs4,g4,gs4,a4,as4,b4,c5,cs5,d5,ds5,e5,f5,fs5,g5,gs5,a5,as5,b5;
/* soundbank -------- notes with s = sharp */
unsigned char song_selection;
unsigned char sound_state;

void soundEngine_init();

void sound_state_reset();
void play_song();

#endif //included
