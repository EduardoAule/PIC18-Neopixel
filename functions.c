void init_NeoPixels() {
    memset(NeoRed,0,sizeof(NeoRed));
    memset(NeoGreen,0,sizeof(NeoGreen));
    memset(NeoBlue,0,sizeof(NeoBlue));
    NeoDraw();
    delay_ms(40);
}
void ajustar_brillo(unsigned int* arrayRed,  unsigned int8* arrayGreen, unsigned int* arrayBlue){
    //ajustar brillo
    for(int8 i = 0; i < NUM_PIXELS; i++) {
    	//en modo ANSI la division tiene que ser entre el mismo tipo
        arrayRed[i] = arrayRed[i] / (unsigned)brillo;
        arrayGreen[i] = arrayGreen[i] / (unsigned)brillo;
        arrayBlue[i] = arrayBlue[i] / (unsigned)brillo;
    }
}
void mode_SingleColor(int8 c)
{
    for(i = 0; i < NUM_PIXELS; i++)
    {
        NeoRed[i] = rainbow_double[0][c];
        NeoGreen[i] = rainbow_double[1][c];
        NeoBlue[i] = rainbow_double[2][c];
    }

    NeoDraw();
    delay_ms(40);
}


void mode_RGB()
{
    tempR = 0; tempG = 0; tempB = 0;
    for(int rgb = 0; rgb < 3; rgb++) {
        for(int16 temp = 1; temp < 256; temp++)
        {
            if(rgb == 0)
                tempR = temp;
            else
                if(rgb == 1)
                    tempG = temp;
                else
                    tempB = temp;
            for(i = 0; i < NUM_PIXELS; i++)
            {
                NeoRed[i] = tempR;
                NeoGreen[i] = tempG;
                NeoBlue[i] = tempB;
                //delay_ms(100);
            }
            //putc('e');
            ajustar_brillo(&NeoRed[0], NeoGreen, &NeoBlue[0]);
            NeoDraw();
            if(mode != '2') {
                init_NeoPixels();
                break;
            }
            delay_ms(50);
        }
        //putc('E');
        if(mode != '2') {
            break;
        }
    }
    if(mode != '2')
        return;
    for(unsigned int rgb = 0; rgb < 3; rgb++) {
        for(temp = 255; temp > 0; temp--)
        {
            if(rgb == 0)
                tempR = temp;
            else
                if(rgb == 1)
                    tempG = temp;
                else
                    tempB = temp;
            for(i = 0; i < NUM_PIXELS; i++)
            {
                NeoRed[i] = tempR;
                NeoGreen[i] = tempG;
                NeoBlue[i] = tempB;
                //delay_ms(100);
            }
            //putc('f');
            ajustar_brillo(&NeoRed[0], NeoGreen, &NeoBlue[0]);
            NeoDraw();
            if(mode != '2') {
                //init_NeoPixels();
                break;
            }

            delay_ms(50);
        }
        //putc('F');
        if(mode != '2') {
            break;
        }
    }

}

/*
*   36 neopixels y 4 mas para una estrella,
*   movera un pixel a traves de los 36 y se iran acumulando,
*   cada pixel sera de un color del arcoiris,
*   y la estrella solo brillara a dif intensidad
*/
void mode_tree()
{   

    int8 temp_NP = NUM_PIXELS;
    for(int8 r = 0; r < 3; r++) {
	    for(int8 c = 0;c < sizeof(rainbow_double[0]); c++) {
	        for(i = 0; i < temp_NP; i++) {
	            NeoRed[i] = rainbow_double[0][c];
	            NeoGreen[i] = rainbow_double[1][c];
	            NeoBlue[i] = rainbow_double[2][c];
	            //evitar que el pixel anterior se muestre
	            //pero que se conserve el ultimo pixel, un solo pixel que se mueve
	            //por la tira
	            if(i >= 1) {
	                NeoRed[i-1] = 0;
	                NeoGreen[i-1] = 0;
	                NeoBlue[i-1] = 0;

	            }
	            if(mode != '3') {
	                //init_NeoPixels();	//
	                break;
	            }
	            NeoDraw();
	            delay_ms(35);
	        }
	        temp_NP--;
	        if(!temp_NP )
	            break;
	        if(mode != '3')
	            break;
	    }
	    if(mode != '3') {
	        flag_break = TRUE;
	        break;
	    }
    }
	//ajustar brillo despues de las secuencia incial
    ajustar_brillo(&NeoRed[0], NeoGreen, &NeoBlue[0]);

}

void shift_Rainbow(){
    int8 tempNeo = NUM_PIXELS-1;
    //ajustar brillo
    //lo de abajo no es correcto segun C, pero funciona en CCS
    //ajustar_brillo(&bNeoRed, &bNeoGreen, &bNeoBlue);
    //lo correcto es
    //ajustar_brillo(&NeoRed[0], NeoGreen, &NeoBlue[0]);
    for(i = tempNeo; i > 0; i--) {
        if(i == tempNeo) {
            tempR = NeoRed[i];
            tempG = NeoGreen[i];
            tempB = NeoBlue[i];
        }
        NeoRed[i] = NeoRed[i - 1]; 
        NeoGreen[i] = NeoGreen[i - 1];
        NeoBlue[i] = NeoBlue[i - 1];

        if(i==1) {
            NeoRed[i - 1] = tempR;
            NeoGreen[i - 1] = tempG;
            NeoBlue[i - 1] = tempB;
        }
    }
    
}

void mode_SingleTree()
{   //base color verde y algunos leds seran esferas
    //0 7 14 20 25 29 32 34, intermedios 3 10 17 22
    for(i = 0; i < NUM_PIXELS; i++)
    {
        NeoRed[i] = rainbow_double[0][3];
        NeoGreen[i] = rainbow_double[1][3];
        NeoBlue[i] = rainbow_double[2][3];
    }
	//estrella
	NeoRed[NUM_PIXELS-1] = rainbow_double[0][7];
	NeoGreen[NUM_PIXELS-1] = rainbow_double[1][7];
	NeoBlue[NUM_PIXELS-1] = rainbow_double[2][7];
	//pixel 0
	random = rand();
	NeoRed[0] = rainbow_double[0][random];
	NeoGreen[0] = rainbow_double[1][random];
	NeoBlue[0] = rainbow_double[2][random];
	//pixel 7
	random = rand();
	NeoRed[7] = rainbow_double[0][random];
	NeoGreen[7] = rainbow_double[1][random];
	NeoBlue[7] = rainbow_double[2][random];
	//pixel 14
	random = rand();
	NeoRed[14] = rainbow_double[0][random];
	NeoGreen[14] = rainbow_double[1][random];
	NeoBlue[14] = rainbow_double[2][random];
	//pixel 20
	random = rand();
	NeoRed[20] = rainbow_double[0][random];
	NeoGreen[20] = rainbow_double[1][random];
	NeoBlue[20] = rainbow_double[2][random];
	//pixel 25
	random = rand();
	NeoRed[25] = rainbow_double[0][random];
	NeoGreen[25] = rainbow_double[1][random];
	NeoBlue[25] = rainbow_double[2][random];
	//pixel 29
	random = rand();
	NeoRed[29] = rainbow_double[0][random];
	NeoGreen[29] = rainbow_double[1][random];
	NeoBlue[29] = rainbow_double[2][random];
	//pixel 32
	random = rand();
	NeoRed[32] = rainbow_double[0][random];
	NeoGreen[32] = rainbow_double[1][random];
	NeoBlue[32] = rainbow_double[2][random];
	//pixel 34
	random = rand();
	NeoRed[34] = rainbow_double[0][random];
	NeoGreen[34] = rainbow_double[1][random];
	NeoBlue[34] = rainbow_double[2][random];
	//pixel 3
	random = rand();
	NeoRed[3] = rainbow_double[0][random];
	NeoGreen[3] = rainbow_double[1][random];
	NeoBlue[3] = rainbow_double[2][random];
	//pixel 10
	random = rand();
	NeoRed[10] = rainbow_double[0][random];
	NeoGreen[10] = rainbow_double[1][random];
	NeoBlue[10] = rainbow_double[2][random];
	//pixel 17
	random = rand();
	NeoRed[17] = rainbow_double[0][random];
	NeoGreen[17] = rainbow_double[1][random];
	NeoBlue[17] = rainbow_double[2][random];
	//pixel 23
	random = rand();
	NeoRed[23] = rainbow_double[0][random];
	NeoGreen[23] = rainbow_double[1][random];
	NeoBlue[23] = rainbow_double[2][random];
   	
	//ajustar brillo
	//lo de abajo no es correcto segun C, pero funciona en CCS
	/*Como vimos en el capítulo 6, los arreglos 
		no se pasan mediante el operador & debido a que C pasa de 
		manera automática la dirección inicial en memoria del arreglo 
		(el nombre del arreglo es equivalente a &nombreArreglo[ 0 ]).
	*/
	//ajustar_brillo(&bNeoRed, &bNeoGreen, &bNeoBlue);
	//pasa la referencia de los arrays
	//dir del array pag  193 Deitel Como programar en C/C++
	//el nombre de un arreglo en realidad es la dirección del primer elemento del
	//arreglo, imprimiendo arreglo, &arreglo[ 0 ] y &arreglo,  tienen el mismo valor
	ajustar_brillo(&NeoRed[0], NeoGreen, &NeoBlue[0]);
	//ajustar_brillo(NeoRed, NeoGreen, NeoBlue);
	//ajustar_brillo(&NeoRed, &NeoGreen, &NeoBlue);
	NeoDraw();
	delay_ms(100);
}


