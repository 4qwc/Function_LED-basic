#include <16F877.h>
#fuses HS,NOWDT, NOPROTECT, NOLVP
#use delay(clock=20000000)

#define  LED_1  PIN_B5 //��˹��� pin LED
#define  LED_2  PIN_B4 //��˹��� pin LED
#define  LED_3  PIN_B3 //��˹��� pin LED

#use fast_io(b)
#byte PB =6


int a;
int const i[]={0x08,0x10,0x20 };// ��˹� port_B 00010000,00001000,00000100

int SHIFT()
{
   for(a=0; a<3; ++a){
   PB = i[a];
   delay_ms(250);
   }      
}

void flash_led() {

  for(int i=0;i<5;++i)
     {
      output_high(LED_1);
      output_high(LED_2);
      output_high(LED_3);
      delay_ms(150);
      
      output_low(LED_1);
      output_low(LED_2);
      output_low(LED_3);
      delay_ms(150);
     } 
}

int b;
void main()
{
   set_tris_b(0); // output B

 while(TRUE) {
   delay_ms(200);
   for(b=0;b<=5;++b){
  if(b==5){
   
     flash_led();
     
   }else{
     SHIFT();
   }
   }
 } 
}
