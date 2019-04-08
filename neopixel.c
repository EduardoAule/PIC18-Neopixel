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
