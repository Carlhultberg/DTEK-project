#include <pic32mx.h>
#include <stdlib.h>
#include "pitches.h"


#define TMR2PERIOD ((80000000 / 256) / 1000)
#if TMR2PERIOD > 0xffff
#error "Timer period is too big."
#endif
#define IC3CON       PIC32_R (0x2400)
#define IC3CONCLR       PIC32_R (0x2404)
#define IC3CONSET       PIC32_R (0x2408)
#define IC3BUF        PIC32_R (0x2410)


int mytime = 0x5957;


// Starwars
//int notes[] = {NOTE_A4, R, NOTE_A4, R,NOTE_A4,R, NOTE_F4,R,NOTE_C5,R,NOTE_A4,R,NOTE_F4,R,NOTE_C5,NOTE_A4,NOTE_E5,NOTE_E5,NOTE_E5,NOTE_F5,NOTE_C5, NOTE_G5,NOTE_F5, NOTE_C5,NOTE_A4};
//int delays[] = { 150000, 50000, 150000, 50000, 150000,50000,150000,30000,100000,100000,100000,550000, 100000, 575000, 20, 5, 60, 80, 50, 20, 50, 20, 50, 20, 40, 50, 20, 50,  60, 50, 40, 50,  20, 50, 60, 40};
// L'amour tojours
int notes[] = {NOTE_G7, NOTE_DS5,NOTE_D5,NOTE_D6,NOTE_DS5,NOTE_C5, NOTE_C6,NOTE_AS7,NOTE_C7,NOTE_A7,NOTE_C7,NOTE_A7, NOTE_G7};
int delays[] = {150000, 100000, 150000, 50000,150000, 40000,150000, 100000,150000, 200000,150000, 100000, 150000, 100000,150000, 100000, 150000,100000,150000, 100000, 150000,100000, 150000 };



// Core init
//int toneM = 0;
//int beat= 0;
//int duration = 0;
//int potVal = 0;


/*
 Idea: Since we're only playing one background song (OR MORE, maybe possibility to change background music in menu). Instead of converting notes (Chars) to freq
 it might be easier to just makes arrays of the corresponding frequencies.
 */



void init() {
    
    TRISECLR = 0xFF;
    TRISDCLR = 0x400; //set port D10 as output
    PORTD = 0x400;
    T2CON = 0x70;
 
    T2CONSET = 0x8000; /* Start the timer */
 

    
}

//int[] convertToFreq(char note[]) {
    
//}

void jump() {
    
}

void addFilter() {
}

void playFreq(int freq, int duration) {
    
    // we need to find out the frequency of the processor.
    
    // 80 MHz
    // 8 MHz
    // 32 Khz
    
    // play tone for time
    

  int timeoutcount=0;
    
    if (freq == 0) {
        
        int calculated_period = ((80000000 / 256) / 1000);
        
        PR2 = ((80000000 / 256) / 1000);
        
        while (timeoutcount*calculated_period < duration) {
            
            
            if(IFS(0) & 0x100){
                IFS(0) = 0;
                timeoutcount++;
                
            }
        }
        
        
        return;
        
    }
    
    
    
    int calculated_period = ((80000000 / 256) / freq);
    
    PR2 = ((80000000 / 256) / freq); // Freq = 300  1/s, PR = 20ms. freq = 300 1/s, PR = 10s;
    
   // int duration = timeoutcount/freq;
    
  int i = 0;
    
    while (timeoutcount*calculated_period < duration) {
       
        if(IFS(0) & 0x100){
            IFS(0) = 0;
            timeoutcount++;

                    if (timeoutcount%2 == 0) {
                        PORTD = 0x400;
                
                    } else {
                        PORTD = 0x000;
                    }
            
        
            }
        }
    
    
    
    }
    

    





int main() {
    init();
    int d = 0;
    int n;
    int c = sizeof(notes)/sizeof(notes[0]);
    while (d < c) {
        
        playFreq(notes[d], delays[d]);
       // delay(d);
        
        d++;
    }
    
}
