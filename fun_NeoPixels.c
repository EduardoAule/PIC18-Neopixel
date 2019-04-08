

void setPixel(int8 pos, BYTE R, BYTE G, BYTE B) {
	NeoRed[pos] = R;
	NeoGreen[pos] = G;
	NeoBlue[pos] = B;
   	
}
//param: no. diagonal, R, G, B 
void setDiagonal(int8 nodiag, BYTE R, BYTE G, BYTE B) {
	switch(nodiag) {
		case 0:
			setPixel(7, R, G, B);
		break;
		case 1:
			setPixel(8, R, G, B);
			setPixel(6, R, G, B);
		break;
		case 2:
			setPixel(20, R, G, B);
			setPixel(9, R, G, B);
			setPixel(5, R, G, B);
		break;
		case 3:
			setPixel(21, R, G, B);
			setPixel(19, R, G, B);
			setPixel(10, R, G, B);
			setPixel(4, R, G, B);
		break;
		case 4:
			setPixel(29, R, G, B);
			setPixel(22, R, G, B);
			setPixel(18, R, G, B);
			setPixel(11, R, G, B);
			setPixel(3, R, G, B);
		break;
		case 5:
			setPixel(30, R, G, B);
			setPixel(28, R, G, B);
			setPixel(23, R, G, B);
			setPixel(17, R, G, B);
			setPixel(12, R, G, B);
			setPixel(2, R, G, B);
		break;
		case 6:
			setPixel(34, R, G, B);
			setPixel(31, R, G, B);
			setPixel(27, R, G, B);
			setPixel(24, R, G, B);
			setPixel(16, R, G, B);
			setPixel(13, R, G, B);
			setPixel(1, R, G, B);
		break;
		case 7:
			setPixel(35, R, G, B);
			setPixel(33, R, G, B);
			setPixel(32, R, G, B);
			setPixel(26, R, G, B);
			setPixel(25, R, G, B);
			setPixel(15, R, G, B);
			setPixel(14, R, G, B);
			setPixel(0, R, G, B);
		break;
   	
	}
}
void initDiagonal_Rainbow() {
	memset(NeoRed,0,sizeof(NeoRed));
    memset(NeoGreen,0,sizeof(NeoGreen));
    memset(NeoBlue,0,sizeof(NeoBlue));

	//secuencia inicial rainbow en diagonal
	//primer esquina
	setDiagonal(0, 255, 0, 0);
	NeoDraw();
	delay_ms(100);
	setDiagonal(1, 255, 0, 0);
	NeoDraw();
	delay_ms(100);
	setDiagonal(2, 255, 0, 0);
	setDiagonal(1, 255, 0, 0);
	setDiagonal(0, 255, 69, 0);
	NeoDraw();
	delay_ms(100);
	setDiagonal(3, 255, 0, 0);
	setDiagonal(2, 255, 0, 0);
	setDiagonal(1, 255, 69, 0);
	setDiagonal(0, 255, 69, 0);
	NeoDraw();
	delay_ms(100);
	setDiagonal(4, 255, 0, 0);
	setDiagonal(3, 255, 0, 0);
	setDiagonal(2, 255, 69, 0);
	setDiagonal(1, 255, 69, 0);
	setDiagonal(0, 255, 233, 0);
	NeoDraw();
	delay_ms(100);
	setDiagonal(5, 255, 0, 0);
	setDiagonal(4, 255, 0, 0);
	setDiagonal(3, 255, 69, 0);
	setDiagonal(2, 255, 69, 0);
	setDiagonal(1, 255, 233, 0);
	setDiagonal(0, 255, 233, 0);
	NeoDraw();
	delay_ms(100);
	setDiagonal(6, 255, 0, 0);
	setDiagonal(5, 255, 0, 0);
	setDiagonal(4, 255, 69, 0);
	setDiagonal(3, 255, 69, 0);
	setDiagonal(2, 255, 233, 0);
	setDiagonal(1, 255, 233, 0);
	setDiagonal(0, 0, 255, 0);
	NeoDraw();
	delay_ms(100);
	setDiagonal(7, 255, 0, 0);
	setDiagonal(6, 255, 0, 0);
	setDiagonal(5, 255, 69, 0);
	setDiagonal(4, 255, 69, 0);
	setDiagonal(3, 255, 233, 0);
	setDiagonal(2, 255, 233, 0);
	setDiagonal(1, 0, 255, 0);
	setDiagonal(0, 0, 255, 0);
   	
	NeoDraw();
	delay_ms(100);
	//shiftRight_Rainbow(4, &rainbow_inv[0]);	//hasta que rojo coincida con fila 6 y 7
	col =(int)( sizeof(rainbow_inv[0]) / sizeof(rainbow_inv[0][0]) ); 
	shiftRight_Array2D(4, (int8 *)rainbow_inv, col);
}

void diagonal_Rainbow() {
   	
	for(i = 0; i < 8; i++) {
		setDiagonal(7, rainbow_inv[0][3], rainbow_inv[1][3], rainbow_inv[2][3]);
		setDiagonal(6, rainbow_inv[0][2], rainbow_inv[1][2], rainbow_inv[2][2]);
		setDiagonal(5, rainbow_inv[0][2], rainbow_inv[1][2], rainbow_inv[2][2]);
		setDiagonal(4, rainbow_inv[0][1], rainbow_inv[1][1], rainbow_inv[2][1]);
		setDiagonal(3, rainbow_inv[0][1], rainbow_inv[1][1], rainbow_inv[2][1]);
		setDiagonal(2, rainbow_inv[0][0], rainbow_inv[1][0], rainbow_inv[2][0]);
		setDiagonal(1, rainbow_inv[0][0], rainbow_inv[1][0], rainbow_inv[2][0]);
		//desplazo
		//shiftRight_Rainbow(1, &rainbow_inv[0]);
		//col =(int)( sizeof(rainbow_inv[0]) / sizeof(rainbow_inv[0][0]) );
		//es valido, debido a que cada elemento ocupa un byte
		col = sizeof(rainbow_inv[0]);
		shiftRight_Array2D(1, (int8 *)rainbow_inv, col);
		setDiagonal(0, rainbow_inv[0][0], rainbow_inv[1][0], rainbow_inv[2][0]);
	   	
		if(mode != '4') {
			//init_NeoPixels();
			break;
		}
		//set_timer1(0);
		//ajustar brillo despues de las secuencia incial
		ajustar_brillo(&NeoRed[0], NeoGreen, &NeoBlue[0]);
		//printf("t:%lu",get_timer1());
		NeoDraw();
		delay_ms(100);
		setDiagonal(7, rainbow_inv[0][3], rainbow_inv[1][3], rainbow_inv[2][3]);
		setDiagonal(6, rainbow_inv[0][3], rainbow_inv[1][3], rainbow_inv[2][3]);
		setDiagonal(5, rainbow_inv[0][2], rainbow_inv[1][2], rainbow_inv[2][2]);
		setDiagonal(4, rainbow_inv[0][2], rainbow_inv[1][2], rainbow_inv[2][2]);
		setDiagonal(3, rainbow_inv[0][1], rainbow_inv[1][1], rainbow_inv[2][1]);
		setDiagonal(2, rainbow_inv[0][1], rainbow_inv[1][1], rainbow_inv[2][1]);
		setDiagonal(1, rainbow_inv[0][0], rainbow_inv[1][0], rainbow_inv[2][0]);
		setDiagonal(0, rainbow_inv[0][0], rainbow_inv[1][0], rainbow_inv[2][0]);
		//ajustar brillo despues de las secuencia incial
		ajustar_brillo(&NeoRed[0], NeoGreen, &NeoBlue[0]);
		NeoDraw();
		delay_ms(100);
	}
}

void flames_RGB() {
	int8 brillo=5;
	for(i = 0; i < NUM_PIXELS; i++) {
		NeoRed[i] = 0;//rainbow_double[0][4];
		NeoGreen[i] = 8;//rainbow_double[1][4];
		NeoBlue[i] = 64;//rainbow_double[2][4];
	}
    for(i = 1; i < 7; i++) {
		NeoRed[i] = 66/brillo;//rainbow_double[0][4];
		NeoGreen[i] = 165/brillo;//rainbow_double[1][4];
		NeoBlue[i] = 254/brillo;//rainbow_double[2][4];
	}
    for(i = 9; i < 14; i++) {
		NeoRed[i] = 33/brillo;//rainbow_double[0][4];
		NeoGreen[i] = 150/brillo;//rainbow_double[1][4];
		NeoBlue[i] = 243/brillo;//rainbow_double[2][4];
	}
    for(i = 16; i < 20; i++) {
		NeoRed[i] = 30/brillo;//rainbow_double[0][4];
		NeoGreen[i] = 136/brillo;//rainbow_double[1][4];
		NeoBlue[i] = 229/brillo;//rainbow_double[2][4];
	}
    for(i = 22; i < 25; i++) {
		NeoRed[i] = 25/brillo;//rainbow_double[0][4];
		NeoGreen[i] = 118/brillo;//rainbow_double[1][4];
		NeoBlue[i] = 210/brillo;//rainbow_double[2][4];
	}
    for(i = 27; i < 29; i++) {
		NeoRed[i] = 21/brillo;//rainbow_double[0][4];
		NeoGreen[i] = 101/brillo;//rainbow_double[1][4];
		NeoBlue[i] = 192/brillo;//rainbow_double[2][4];
	}
    //pixel 31
	NeoRed[31] = 13/brillo;//rainbow_double[0][4];
	NeoGreen[31] = 71/brillo;//rainbow_double[1][4];
	NeoBlue[31] = 161/brillo;//rainbow_double[2][4];
	NeoDraw();
	delay_ms(100);
   	
    for(i = 1; i < 7; i++) {
		NeoRed[i] = 66;//rainbow_double[0][4];
		NeoGreen[i] = 165;//rainbow_double[1][4];
		NeoBlue[i] = 254;//rainbow_double[2][4];
	}
	NeoDraw();
	delay_ms(100);
	for(i = 9; i < 14; i++) {
		NeoRed[i] = 33;//rainbow_double[0][4];
		NeoGreen[i] = 150;//rainbow_double[1][4];
		NeoBlue[i] = 243;//rainbow_double[2][4];
	}
	NeoDraw();
	delay_ms(100);
	for(i = 16; i < 20; i++) {
		NeoRed[i] = 30;//rainbow_double[0][4];
		NeoGreen[i] = 136;//rainbow_double[1][4];
		NeoBlue[i] = 229;//rainbow_double[2][4];
	}
	NeoDraw();
	delay_ms(100);
	for(i = 16; i < 20; i++) {
		NeoRed[i] = 30/brillo;//rainbow_double[0][4];
		NeoGreen[i] = 136/brillo;//rainbow_double[1][4];
		NeoBlue[i] = 229/brillo;//rainbow_double[2][4];
	}
	NeoDraw();
	delay_ms(100);
	for(i = 22; i < 25; i++) {
		NeoRed[i] = 25;//rainbow_double[0][4];
		NeoGreen[i] = 118;//rainbow_double[1][4];
		NeoBlue[i] = 210;//rainbow_double[2][4];
	}
	NeoDraw();
	delay_ms(100);
	for(i = 22; i < 25; i++) {
		NeoRed[i] = 25/brillo;//rainbow_double[0][4];
		NeoGreen[i] = 118/brillo;//rainbow_double[1][4];
		NeoBlue[i] = 210/brillo;//rainbow_double[2][4];
	}
	NeoDraw();
	delay_ms(100);
	for(i = 27; i < 29; i++) {
		NeoRed[i] = 21;//rainbow_double[0][4];
		NeoGreen[i] = 101;//rainbow_double[1][4];
		NeoBlue[i] = 192;//rainbow_double[2][4];
	}
	NeoDraw();
	delay_ms(100);
	for(i = 27; i < 29; i++) {
		NeoRed[i] = 21/brillo;//rainbow_double[0][4];
		NeoGreen[i] = 101/brillo;//rainbow_double[1][4];
		NeoBlue[i] = 192/brillo;//rainbow_double[2][4];
	}
	NeoDraw();
	delay_ms(100);
	//pixel 31
	NeoRed[31] = 13;//rainbow_double[0][4];
	NeoGreen[31] = 71;//rainbow_double[1][4];
	NeoBlue[31] = 161;//rainbow_double[2][4];
	NeoDraw();
	delay_ms(100);
	NeoRed[31] = 13/brillo;
	NeoGreen[31] = 71/brillo;
	NeoBlue[31] = 161/brillo;
	NeoDraw();
	delay_ms(100);
}

void setSegmento(int8 i, int8 R, int8 G, int8 B) {
		NeoRed[i] =	R;
		NeoGreen[i] = G;
		NeoBlue[i] = B;
}
void tunel_Triangular() {
	//8 segmentos, lados de un triangulo, de diferente color
	for(i = 0; i < 8; i++) {
		NeoRed[i] =	blues_1[0][2];
		NeoGreen[i] =	blues_1[1][2];
		NeoBlue[i] = blues_1[2][2];
	}
	//segmento 2
	setSegmento( 8, blues_1[0][1], blues_1[1][1], blues_1[2][1]);
	setSegmento( 20, blues_1[0][1], blues_1[1][1], blues_1[2][1]);
	setSegmento( 21, blues_1[0][1], blues_1[1][1], blues_1[2][1]);
	setSegmento( 29, blues_1[0][1], blues_1[1][1], blues_1[2][1]);
	setSegmento( 30, blues_1[0][1], blues_1[1][1], blues_1[2][1]);
	setSegmento( 34, blues_1[0][1], blues_1[1][1], blues_1[2][1]);
	setSegmento( 35, blues_1[0][1], blues_1[1][1], blues_1[2][1]);
	//segmento 3
	setSegmento( 33, blues_1[0][0], blues_1[1][0], blues_1[2][0]);
	setSegmento( 32, blues_1[0][0], blues_1[1][0], blues_1[2][0]);
	setSegmento( 26, blues_1[0][0], blues_1[1][0], blues_1[2][0]);
	setSegmento( 25, blues_1[0][0], blues_1[1][0], blues_1[2][0]);
	setSegmento( 15, blues_1[0][0], blues_1[1][0], blues_1[2][0]);
	setSegmento( 14, blues_1[0][0], blues_1[1][0], blues_1[2][0]);
	//segmento 4
	setSegmento( 13, blues_2[0][2], blues_2[1][2], blues_2[2][2]);
	setSegmento( 12, blues_2[0][2], blues_2[1][2], blues_2[2][2]);
	setSegmento( 11, blues_2[0][2], blues_2[1][2], blues_2[2][2]);
	setSegmento( 10, blues_2[0][2], blues_2[1][2], blues_2[2][2]);
	setSegmento( 9, blues_2[0][2], blues_2[1][2], blues_2[2][2]);
	//segmento 5
	setSegmento( 19, blues_2[0][1], blues_2[1][1], blues_2[2][1]);
	setSegmento( 22, blues_2[0][1], blues_2[1][1], blues_2[2][1]);
	setSegmento( 28, blues_2[0][1], blues_2[1][1], blues_2[2][1]);
	setSegmento( 31, blues_2[0][1], blues_2[1][1], blues_2[2][1]);
	//segmento 6
	setSegmento( 27, blues_2[0][0], blues_2[1][0], blues_2[2][0]);
	setSegmento( 24, blues_2[0][0], blues_2[1][0], blues_2[2][0]);
	setSegmento( 16, blues_2[0][0], blues_2[1][0], blues_2[2][0]);
	//segmento 7
	setSegmento( 17, blues_3[0][1], blues_3[1][1], blues_3[2][1]);
	setSegmento( 18, blues_3[0][1], blues_3[1][1], blues_3[2][1]);
	//segmento 8
	setSegmento( 23, blues_3[0][0], blues_3[1][0], blues_3[2][0]);
   	
	//ajustar brillo despues de las secuencia incial
	ajustar_brillo(&NeoRed[0], NeoGreen, &NeoBlue[0]);
    
	NeoDraw();
	col =(int)( sizeof(blues_1[0]) / sizeof(blues_1[0][0]) ); //elementos de la fila
	shiftLeft_Array2D(1, (int8 *)blues_1, col);
	col =(int)( sizeof(blues_2[0]) / sizeof(blues_2[0][0]) ); //elementos de la fila
	shiftLeft_Array2D(1, (int8 *)blues_2, col);
	col =(int)( sizeof(blues_3[0]) / sizeof(blues_3[0][0]) ); //elementos de la fila
	shiftLeft_Array2D(1, (int8 *)blues_3, col);
	delay_ms(100);
}

void tunel_WheelBlues() {
	//8 segmentos, lados de un triangulo, de diferente color
	for(i = 0; i < 8; i++) {
		NeoRed[i] =	blues[0][7];
		NeoGreen[i] =	blues[1][7];
		NeoBlue[i] = blues[2][7];
	}
	//segmento 2
	setSegmento( 8, blues[0][6], blues[1][6], blues[2][6]);
	setSegmento( 20, blues[0][6], blues[1][6], blues[2][6]);
	setSegmento( 21, blues[0][6], blues[1][6], blues[2][6]);
	setSegmento( 29, blues[0][6], blues[1][6], blues[2][6]);
	setSegmento( 30, blues[0][6], blues[1][6], blues[2][6]);
	setSegmento( 34, blues[0][6], blues[1][6], blues[2][6]);
	setSegmento( 35, blues[0][6], blues[1][6], blues[2][6]);
	//segmento 3
	setSegmento( 33, blues[0][5], blues[1][5], blues[2][5]);
	setSegmento( 32, blues[0][5], blues[1][5], blues[2][5]);
	setSegmento( 26, blues[0][5], blues[1][5], blues[2][5]);
	setSegmento( 25, blues[0][5], blues[1][5], blues[2][5]);
	setSegmento( 15, blues[0][5], blues[1][5], blues[2][5]);
	setSegmento( 14, blues[0][5], blues[1][5], blues[2][5]);
	//segmento 4
	setSegmento( 13, blues[0][4], blues[1][4], blues[2][4]);
	setSegmento( 12, blues[0][4], blues[1][4], blues[2][4]);
	setSegmento( 11, blues[0][4], blues[1][4], blues[2][4]);
	setSegmento( 10, blues[0][4], blues[1][4], blues[2][4]);
	setSegmento( 9, blues[0][4], blues[1][4], blues[2][4]);
	//segmento 5
	setSegmento( 19, blues[0][3], blues[1][3], blues[2][3]);
	setSegmento( 22, blues[0][3], blues[1][3], blues[2][3]);
	setSegmento( 28, blues[0][3], blues[1][3], blues[2][3]);
	setSegmento( 31, blues[0][3], blues[1][3], blues[2][3]);
	//segmento 6
	setSegmento( 27, blues[0][2], blues[1][2], blues[2][2]);
	setSegmento( 24, blues[0][2], blues[1][2], blues[2][2]);
	setSegmento( 16, blues[0][2], blues[1][2], blues[2][2]);
	//segmento 7
	setSegmento( 17, blues[0][1], blues[1][1], blues[2][1]);
	setSegmento( 18, blues[0][1], blues[1][1], blues[2][1]);
	//segmento 8
	setSegmento( 23, blues[0][0], blues[1][0], blues[2][0]);
	//ajustar brillo despues de las secuencia incial
	ajustar_brillo(&NeoRed[0], NeoGreen, &NeoBlue[0]);
	NeoDraw();
	//col =(int)( sizeof(blues[0]) / sizeof(blues[0][0]) ); //elementos de la fila
	col = sizeof(blues[0]);
	shiftLeft_Array2D(1, (int8 *)blues, col);
	delay_ms(100);
   	

}
void tunel_WheelRainbow() {
	//8 segmentos, lados de un triangulo, de diferente color
	for(i = 0; i < 8; i++) {
		NeoRed[i] =	rainbow_inv[0][7];
		NeoGreen[i] =	rainbow_inv[1][7];
		NeoBlue[i] = rainbow_inv[2][7];
	}
	//segmento 2
	setSegmento( 8, rainbow_inv[0][6], rainbow_inv[1][6], rainbow_inv[2][6]);
	setSegmento( 20, rainbow_inv[0][6], rainbow_inv[1][6], rainbow_inv[2][6]);
	setSegmento( 21, rainbow_inv[0][6], rainbow_inv[1][6], rainbow_inv[2][6]);
	setSegmento( 29, rainbow_inv[0][6], rainbow_inv[1][6], rainbow_inv[2][6]);
	setSegmento( 30, rainbow_inv[0][6], rainbow_inv[1][6], rainbow_inv[2][6]);
	setSegmento( 34, rainbow_inv[0][6], rainbow_inv[1][6], rainbow_inv[2][6]);
	setSegmento( 35, rainbow_inv[0][6], rainbow_inv[1][6], rainbow_inv[2][6]);
	//segmento 3
	setSegmento( 33, rainbow_inv[0][5], rainbow_inv[1][5], rainbow_inv[2][5]);
	setSegmento( 32, rainbow_inv[0][5], rainbow_inv[1][5], rainbow_inv[2][5]);
	setSegmento( 26, rainbow_inv[0][5], rainbow_inv[1][5], rainbow_inv[2][5]);
	setSegmento( 25, rainbow_inv[0][5], rainbow_inv[1][5], rainbow_inv[2][5]);
	setSegmento( 15, rainbow_inv[0][5], rainbow_inv[1][5], rainbow_inv[2][5]);
	setSegmento( 14, rainbow_inv[0][5], rainbow_inv[1][5], rainbow_inv[2][5]);
	//segmento 4
	setSegmento( 13, rainbow_inv[0][4], rainbow_inv[1][4], rainbow_inv[2][4]);
	setSegmento( 12, rainbow_inv[0][4], rainbow_inv[1][4], rainbow_inv[2][4]);
	setSegmento( 11, rainbow_inv[0][4], rainbow_inv[1][4], rainbow_inv[2][4]);
	setSegmento( 10, rainbow_inv[0][4], rainbow_inv[1][4], rainbow_inv[2][4]);
	setSegmento( 9, rainbow_inv[0][4], rainbow_inv[1][4], rainbow_inv[2][4]);
	//segmento 5
	setSegmento( 19, rainbow_inv[0][3], rainbow_inv[1][3], rainbow_inv[2][3]);
	setSegmento( 22, rainbow_inv[0][3], rainbow_inv[1][3], rainbow_inv[2][3]);
	setSegmento( 28, rainbow_inv[0][3], rainbow_inv[1][3], rainbow_inv[2][3]);
	setSegmento( 31, rainbow_inv[0][3], rainbow_inv[1][3], rainbow_inv[2][3]);
	//segmento 6
	setSegmento( 27, rainbow_inv[0][2], rainbow_inv[1][2], rainbow_inv[2][2]);
	setSegmento( 24, rainbow_inv[0][2], rainbow_inv[1][2], rainbow_inv[2][2]);
	setSegmento( 16, rainbow_inv[0][2], rainbow_inv[1][2], rainbow_inv[2][2]);
	//segmento 7
	setSegmento( 17, rainbow_inv[0][1], rainbow_inv[1][1], rainbow_inv[2][1]);
	setSegmento( 18, rainbow_inv[0][1], rainbow_inv[1][1], rainbow_inv[2][1]);
	//segmento 8
	//setSegmento( 23, rainbow_inv[0][0], rainbow_inv[1][0], rainbow_inv[2][0]);
	setSegmento( 23, 128, 128, 128);
	//ajustar brillo despues de las secuencia incial
	ajustar_brillo(&NeoRed[0], NeoGreen, &NeoBlue[0]);
	NeoDraw();
	//col =(int)( sizeof(rainbow_inv[0]) / sizeof(rainbow_inv[0][0]) ); //elementos de la fila
	col = sizeof(rainbow_inv[0]);
	shiftLeft_Array2D(1, (int8 *)rainbow_inv, col);
	delay_ms(100);

}
