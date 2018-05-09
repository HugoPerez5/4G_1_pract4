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
int contadorD = 0x00;

#int_timer0
void timer0(){
   contadorB++;

   contadorD++;
}
void main (void){
   setup_oscillator(OSC_16MHZ);
   set_tris_b(0x00);
   set_tris_d(0x00);
   
   set_timer0(0x00); 
   setup_timer_0(RTCC_INTERNAL |RTCC_DIV_128 | T0_8_BIT);
   enable_interrupts(int_timer0);
   enable_interrupts(GLOBAL);
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
      
      if(contadorD > 122 ){
         if(indiceD > 9)
            indiceD = 0x00;
         output_d(display[indiceD]);
         indiceD++;
         contadorD = 0x00;
      }
   }
}