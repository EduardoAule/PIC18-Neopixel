#include <18F4550.h>
#device ADC=10
//#device ANSI	//ocupa mas ROM
#define RAND_MAX 16
#INCLUDE <STDLIB.H>
#fuses HSPLL,MCLR,NOWDT,NOPROTECT,NOBROWNOUT,PBADEN,NODEBUG,NOLVP,NOVREGEN,USBDIV,PLL3,CPUDIV1
#fuses PUT,NOIESO,NOFCMEN
//#fuses HSPLL,MCLR,NOWDT,NOPROTECT,NODEBUG,USBDIV,PLL2,CPUDIV1,VREGEN,NOLVP,NOPBADEN,NOBROWNOUT
//#fuses HS,NOWDT,NOPROTECT,NOPUT,NOBROWNOUT,NOPBADEN,NOLVP,NOCPD,NODEBUG,NOWRT,NOVREGEN
//#fuses XT,MCLR,NOWDT,NOPROTECT,NOPUT,NOBROWNOUT,NOPBADEN,NOLVP,NOCPD,NODEBUG,NOWRT,NOVREGEN
//#use delay(clock=4MHz,crystal=4MHz)
#use delay(clock=48MHz,crystal=12MHz)
//#use rs232(baud=9600,parity=N,xmit=None,rcv=None,bits=8,stream=PORT1)
#use rs232(uart1, baud=9600)
//#use FAST_IO(ALL)
//#use fast_io(B)
#use fast_io(D)
#use fast_io(E)
//#priority timer1,rda //first timer1 IRQ
/* #use fast_io(a)
By default the compiler is set to 'standard_io' mode.
In standard_io mode, the instruction:
output_a(0x00); 
sets the _whole_ of portA as outputs. sin importa el set_tris_x() */
//FOR NEOPIXELS type GRB
//#define NEOPIN PIN_E2
#define NUM_PIXELS 36

#include "ioports.h"
#include "vars.h"
#include "NeoPixel.c"
#include "IRQ.c"
#include "fun_arrays.c"
#include "functions.c"
#include "fun_NeoPixels.c"
//clear(set to 0) si se usa PBADEN con INT_EXT y resistencia a PULL_UP sin
//importar si es H2L o L2H, sino este Flag bit se pondra a 1.
//como si alguien dispara la INT
#bit INT0IF_BIT = 0xFF2.1	//(INTCON)INT0IF: INT0 External Interrupt Flag bit
#bit INT0IE_BIT = 0xFF2.4

void main() {
   	
	output_a(0x00);
    output_b(0x00);
    output_d(0x00);
    output_e(0x00);
    //si hay que inicializar, por que tiene un comportamiento raro
    //al inicio a veces estan en ON, otras a off,
    //a veces parece que guardan el estado anterior
    //no inicialice, aunque deberia
    set_tris_b(0x03); //INT_EXT0 y 1 // 0x44 SPI
    set_tris_c(0x00); //RX
    set_tris_d(0x00); //
    set_tris_e(0x0);
    
    //setup_adc_ports(AN0_TO_AN3 | VSS_VDD);
    //setup_adc(ADC_CLOCK_INTERNAL);
   //ext_int_edge (H_TO_L) ;
   //enable_interrupts( int_EXT_H2L );	//int_EXT_H2L para RX.
	if(INT0IE_BIT)
		putc('I'); else putc('i');
	INT0IF_BIT = 0;	//solo si se usa el FUSE PBADEN.
	if(INT0IF_BIT)
		putc('F'); else putc('f');
    enable_interrupts (INT_EXT_L2H);//Habilita interrupciones ext
    enable_interrupts (INT_EXT1_L2H);
    setup_timer_1( T1_INTERNAL | T1_DIV_BY_8 );
    //enable_interrupts (INT_RDA);
    enable_interrupts(GLOBAL);
	//configurando puertos, A, B y D puertos como salida
    //set_tris_a(0x00); //4 inputs for Analogics
    
    putc('E');
    output_high(PIN_E0); delay_ms(300);
    output_low(PIN_E0); delay_ms(300);
    output_high(PIN_E0); delay_ms(300);
    output_low(PIN_E0); delay_ms(300);
    output_high(PIN_E0); delay_ms(300);
    output_low(PIN_E0);
    //printf("sizeof of array rainbow: %d\n", (int) sizeof(rainbow));
    //printf("sizeof of array rainbow[0]: %d\n", (int) sizeof(rainbow[0]));
    //iniciamos en color solido mode1
    flag_init = 1;
    //while(TRUE);
    
    while (TRUE) {
        
		if(flag_init) {
			init_NeoPixels();
			flag_init = FALSE;
		}
		if(flag_mode1) {
			//mode_SingleColor(3);    //green
			mode_SingleTree();
			//flag_mode1 = FALSE;
		}
		if(flag_mode2) {
			mode_RGB();
		}
		if(flag_mode3) {
			mode_tree();
			flag_mode3 = FALSE;
			flag_continum = TRUE;
		}
		if(flag_continum) {
			shift_Rainbow();
			NeoDraw();
			delay_ms(100);
		}
		if(flag_mode4)	{
			initDiagonal_Rainbow();
			flag_mode4 = FALSE;
			flag_diagonal_Rainbow = TRUE;
		}
		if(flag_diagonal_Rainbow) {
			diagonal_Rainbow();
		}
		if(flag_mode5)	{
			flames_RGB();
		}
		if(flag_mode6){
			tunel_Triangular();
			//flag_mode6 = FALSE;
		}
		if(flag_mode7){
			tunel_WheelBlues();
		}
		if(flag_mode8){
			tunel_WheelRainbow();
		}
        if(flag_btn) {  //no hacer loop
			flag_continum = FALSE;
			flag_mode1 = FALSE;
			flag_mode2 = FALSE;
			flag_mode3 = FALSE;
			flag_mode4 = FALSE;
			flag_mode5 = FALSE;
			flag_mode6 = FALSE;
			flag_mode7 = FALSE;
			flag_mode8 = FALSE;
			flag_diagonal_Rainbow = FALSE;
			switch(mode) {
				case '1':
					flag_mode1 = TRUE; 
					break;
				case '2':
					flag_mode2 = TRUE;
					break;
				case '3':
					flag_mode3 = TRUE;
					break;
				case '4':
					flag_mode4 = TRUE;
					break;
				case '5':
					flag_mode5 = TRUE;
					break;
				case '6':
					flag_mode6 = TRUE;
					break;
				case '7':
					flag_mode7 = TRUE;
					break;
				case '8':
					flag_mode8 = TRUE;
					break;
				case '9':
					flag_init = TRUE; mode = '0';
					break;
			}
	            flag_btn = FALSE;
        }
        delay_ms(100);   
    }
}


