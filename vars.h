// For NeoPixel
unsigned int8 NeoGreen [NUM_PIXELS];
unsigned int8 NeoBlue [NUM_PIXELS];
unsigned int8 NeoRed [NUM_PIXELS];

//sí unsigned int8 rainbow[][16] sin el primer indice, sizeof no funciona
unsigned int8 rainbow_double[3][16] = {
  { 255,  255, 255,   0,    0,    0, 159, 128, 255, 255, 255,   0,    0,    0, 159, 128 },
  { 0,     69, 233, 255,  176,    0,   0, 128,  0,   69, 233, 255,  176,    0,   0, 128 },
  { 0,      0,   0,   0,  255,  255, 255, 128,  0,    0,   0,   0,  255,  255, 255, 128 }
};
unsigned int8 rainbow[3][8] = {
  { 255,  255, 255,   0,    0,    0, 159, 128 },
  { 0,     69, 233, 255,  176,    0,   0, 128 },
  { 0,      0,   0,   0,  255,  255, 255, 128 }
};
unsigned int8 rainbow_inv[3][8] = {
  { 128,   159,    0,    0,    0,  255, 255, 255 },
  { 128,     0,    0,  176,  255,  233,  69,   0 },
  { 128,   255,  255,  255,    0,    0,  0,    0 }
};
/*
unsigned int8 blues[3][8] = {
	{  66,	 33,   30,   25,   21,   13,   6,   3},
	{ 165,	150,  136,  118,  101,   71,  38,  18},
	{ 245,	243,  229,  210,  192,  161,  85,  41}
};*/
unsigned int8 blues[3][8] = {  	
	// ,azul cobalto,azul marino,turqui,zafiro, azul real, azul muy oscuro
	{  12,	  0,    0,   18,    0,    8,    0,   0 },
	{ 183,	127,   71,   10,    0,   37,   35,   8 },
	{ 242,	255,  171,  143,  128,  103,  102,  16 }
};
unsigned int8 blues_1[3][3] = {  	
	//zafiro, azul real, azul muy oscuro
	{   8,    0,   0 },
	{  37,   35,   8 },
	{ 103,  102,  16 }
};
unsigned int8 blues_2[3][3] = {  	
	//azul cobalto,azul marino,turqui
	{   0,   18,    0 },
	{  71,   10,    0 },
	{ 171,  143,  128 }
};
unsigned int8 blues_3[3][2] = {
	//
	{  12,	  0 },
	{ 183,	127 },
	{ 242,	255 }
};
unsigned int8 temp;
//contador global para los for()
int8 i = 0;

//serial
unsigned char data;
int1 light = FALSE;   //para envial on/off a Neopixel

unsigned int8 tempR;
unsigned int8 tempG;
unsigned int8 tempB;
//flag para salir de los for()
//del ultimo modo
int1 flag_break = FALSE;
int1 flag_init = FALSE;
int1 flag_mode1 = FALSE;
int1 flag_mode2 = FALSE;
int1 flag_mode3 = FALSE;
int1 flag_btn = FALSE;
int1 flag_continum = FALSE;
//nuevos modos
int1 flag_mode4 = FALSE;
int1 flag_mode5 = FALSE;
int1 flag_mode6 = FALSE;
int1 flag_mode7 = FALSE;
int1 flag_mode8 =FALSE;
int1 flag_diagonal_Rainbow = FALSE;
int8 mode = '0'; //'0'
int8 random = 0;
//ajustar brillo
int8 brillo= 5;

//para el pase de arrays
int8 col = 0;
int8 row = 0;


