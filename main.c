#include <18F4620.h>
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)
#use fast_io(a)
#use fast_io(b)
#use fast_io(c)
#use fast_io(d)
#use fast_io(e)

int contadorB = 0x00;

void main (void){
   setup_oscillator(OSC_16MHZ);
   int indiceB = 0x00, indiceC = 0x00, indiceD = 0x00;
   int display[10] = {63,6,91,79,102,109,125,7,127,103};
   
   while(1){
      if(contadorB > 24 ){
         if(indiceB > 9)
            indiceB = 0x00;
         output_b(display[indiceB]);
         indiceB++;
         contadorB = 0x00;
      }
   }
}