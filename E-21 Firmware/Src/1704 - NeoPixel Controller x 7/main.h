#include <16F1704.h>
#device ADC=16

#FUSES NOWDT                   //No Watch Dog Timer
#FUSES PROTECT                 //Code protected from reads
#FUSES NOBROWNOUT              //No brownout reset
#FUSES NOLVP                   //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(internal=32MHz)

#use FAST_IO(ALL)

#pin_select rx1=pin_C5
#pin_select tx1=pin_C0

#use rs232(baud=57600, parity=N, xmit=pin_C0, rcv=pin_C5, bits=8, stream=COMM, ERRORS)

#define DELAY_HIGH_0 2
#define DELAY_LOW_0 2

#define DELAY_HIGH_1 6
#define DELAY_LOW_1 1

