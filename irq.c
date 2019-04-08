#INT_EXT
void interrupcion_ext()
{
    RE0 = ~RE0;
    RA5 = !RA5;

    light = !light;
    mode ++;
    flag_btn = TRUE;
    putc(mode);

}
#INT_EXT1
void interrupcion_ext1()
{
    brillo++;

    if(brillo > 6) {
        brillo = 1;
    }
    putc(brillo);

}

#int_rda 
void rda_isr(void)//función de interrupción por recepción de datos USART               
{ 
   if(kbhit()) //verifica si hay datos en buffer
   {
      data=getc(); 
      putc(data);
      //mode = data;
        
      //data=0;
   }
}

