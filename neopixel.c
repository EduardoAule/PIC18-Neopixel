void NeoBit (int1 Bit)
{
   if (Bit == 1)
   { RE2=1; delay_cycles(7); RE2=0; } //4// delay_cycles (3); // Bit '1'   
   else
   { RE2=1; delay_cycles (3); RE2=0;  } //1// delay_cycles (6); // Bit '0'   
}
void NeoDraw (void)
{
   unsigned int8 NeoPixel;
   signed int8 BitCount;
   for (NeoPixel = 0; NeoPixel < NUM_PIXELS; NeoPixel++)
   {    
      for (BitCount = 7; BitCount >= 0; BitCount--)      
         NeoBit(bit_test(NeoGreen[NeoPixel], BitCount));      
      for (BitCount = 7; BitCount >= 0; BitCount--)           
         NeoBit(bit_test(NeoRed[NeoPixel], BitCount));            
      for (BitCount = 7; BitCount >= 0; BitCount--)      
         NeoBit(bit_test(NeoBlue[NeoPixel], BitCount));      
   }
   //output_low (NeoPin);
   //RE2=0; //delay_cycles (1);
}
/*
void NeoBit (int1 Bit)
{
   if (Bit == 1)
   { output_high (NeoPin); delay_cycles (4); output_low (NeoPin);} //8// delay_cycles (3); // Bit '1'   
   else
   { output_high (NeoPin); delay_cycles (1); output_low (NeoPin); } //4// delay_cycles (6); // Bit '0'   
}*/
/*
void NeoInit (void)
{
   unsigned int8 NeoPixel;
   for (NeoPixel = 0; NeoPixel < NeoNum; NeoPixel++) 
   {
      if (NeoPixel < 5)
         { NeoGreen[NeoPixel] = 0; NeoBlue[NeoPixel] = 0; NeoRed[NeoPixel] = 64; }
         else if((NeoPixel >= 5) & (NeoPixel < 10))
            { NeoGreen[NeoPixel] = 0; NeoBlue[NeoPixel] = 64; NeoRed[NeoPixel] = 0; }
            else if((NeoPixel >= 10) & (NeoPixel < NeoNum)) 
               { NeoGreen[NeoPixel] = 64; NeoBlue[NeoPixel] = 0; NeoRed[NeoPixel] = 0; }
      /*if (NeoPixel < 10)
         { NeoGreen[NeoPixel] = 0; NeoBlue[NeoPixel] = 0; NeoRed[NeoPixel] = 64; }
      else if ((NeoPixel >= 10) & (NeoPixel < 20))
         { NeoGreen[NeoPixel] = 0; NeoBlue[NeoPixel] = 64; NeoRed[NeoPixel] = 0; }
      else if ((NeoPixel >= 20) & (NeoPixel < 30))
         { NeoGreen[NeoPixel] = 0; NeoBlue[NeoPixel] = 64; NeoRed[NeoPixel] = 64; }
      else if ((NeoPixel >= 30) & (NeoPixel < 40))
         { NeoGreen[NeoPixel] = 64; NeoBlue[NeoPixel] = 0; NeoRed[NeoPixel] = 0; }
      else if ((NeoPixel >= 40) & (NeoPixel < 50))
         { NeoGreen[NeoPixel] = 64; NeoBlue[NeoPixel] = 0; NeoRed[NeoPixel] = 64; }
      else if ((NeoPixel >= 50) & (NeoPixel < NeoNum))
         { NeoGreen[NeoPixel] = 64; NeoBlue[NeoPixel] = 64; NeoRed[NeoPixel] = 0; }   
   }
}*/

/*
void NeoRotate (void)
{
   unsigned int8 NeoPixel;   
   for (NeoPixel = 0; NeoPixel < NeoNum - 1; NeoPixel++)   
   {           
      NeoGreen[NeoPixel] = NeoGreen[NeoPixel + 1];
      NeoBlue[NeoPixel] = NeoBlue[NeoPixel + 1];
      NeoRed[NeoPixel] = NeoRed[NeoPixel + 1];
   }
   NeoGreen[NeoNum - 1] = NeoGreen[0];
   NeoBlue[NeoNum - 1] = NeoBlue[0];
   NeoRed[NeoNum - 1] = NeoRed[0]; 
}*/

