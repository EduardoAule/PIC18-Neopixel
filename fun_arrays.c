
//desplaza los elementos del array rainbow[3][8] hacia la derecha.
void shiftRight_Array2D(int8 des, unsigned int8* array, int8 NUM_COLS) {
    //int8 tempNeo = sizeof(array[0]) - 1;
    col --;
    //printf("tempNeo:%d\n\r",tempNeo);
    //ajustar brillo
    //ajustar_brillo(&bNeoRed, &bNeoGreen, &bNeoBlue);
    for(int d = 0; d < des; d++)	//cuantos desplazamientos
    for(i = col; i > 0; i--) {
        if(i == col) {
			tempR = *((array+0*NUM_COLS)+ i);
			tempG = *((array+1*NUM_COLS)+ i);
			tempB = *((array+2*NUM_COLS)+ i);
		}
		*((array + 0 * NUM_COLS) + i) = *((array + 0 * NUM_COLS) + (i - 1)); 
		*((array + 1 * NUM_COLS) + i) = *((array + 1 * NUM_COLS) + (i - 1));
		*((array + 2 * NUM_COLS) + i) = *((array + 2 * NUM_COLS) + (i - 1));

		if(i==1) {
			*((array + 0 * NUM_COLS) + (i - 1)) = tempR; 
			*((array + 1 * NUM_COLS) + (i - 1)) = tempG; 
			*((array + 2 * NUM_COLS) + (i - 1)) = tempB; 
		}
	}
}

//***************************************************************************
//void shiftLeft(int8 des, unsigned int8 *array[3]) {	//unsigned int8 (*array)[3] bad
//param: desplazamientos, array, columnas del array (row esta fijo por ser array de 3 x Cols)
void shiftLeft_Array2D(int8 des, unsigned int8 *array, int8 NUM_COLS) {
	//int8 no_cols = 2;//(int)( sizeof(blues_1[0]) / sizeof(blues_1[0][0]) ); //elementos de la fila
	//col = NUM_COLS;
	col--;
	for( i = 0; i < col; i++) {
		if(i == 0) {
			tempR = *((array+0*NUM_COLS)+ i);
			tempG = *((array+1*NUM_COLS)+ i);
			tempB = *((array+2*NUM_COLS)+ i);
		}
		*((array + 0 * NUM_COLS) + i) = *((array + 0 * NUM_COLS) + (i + 1)); 
		*((array + 1 * NUM_COLS) + i) = *((array + 1 * NUM_COLS) + (i + 1));
		*((array + 2 * NUM_COLS) + i) = *((array + 2 * NUM_COLS) + (i + 1));

		if( i == (col-1) ) {
			*((array + 0 * NUM_COLS) + (i + 1)) = tempR; 
			*((array + 1 * NUM_COLS) + (i + 1)) = tempG; 
			*((array + 2 * NUM_COLS) + (i + 1)) = tempB; 

		}
	}
}
//***************************************************************************
//void shiftLeft(int8 des, unsigned int8 *array[3]) {	//unsigned int8 (*array)[3] bad
/*void shiftLeft(int8 des, unsigned int8 *array) {
	int8 tempNeo = (int)( sizeof(blues_1[0]) / sizeof(blues_1[0][0]) ); //elementos de la fila
	tempNeo --;
	for( i = 0; i < tempNeo; i++) {
		if(i == 0) {
			//Para acceder a los elementos hazlo con la forma: 
			//*(*(matriz+NUM_COL)+NUM_FIL)  
		    //tempR = *(*(array+ 0 )+ i );
			tempR = array[0][i];
			tempG = array[1][i];
			tempB = array[2][i];
		}
		array[0][i] = array[0][i + 1]; 
		array[1][i] = array[1][i + 1];
		array[2][i] = array[2][i + 1];
		if( i == (tempNeo-1) ) {
			array[0][i + 1] = tempR;
			array[1][i + 1] = tempG;
			array[2][i + 1] = tempB;
		}
	}

}*/
