void MyDelay(unsigned long mSecondsApx);  // this is a function prototype

void setup()
{
  unsigned char *portDDRB;  // Declare a pointer byte for the data direction register B
  
  portDDRB = (unsigned char *) 0x24;  // Assign the pointer byte address (from ATmega328p datasheet, data direction register B)
  
  *portDDRB |= 0x20;  // Bitwise OR which sets bit 5
}

void loop()
{
  unsigned char *portB;  // Declare a pointer byte for data register B

  portB = (unsigned char *) 0x25; // Assign pointer byte address to data register B

  *portB |= 0x20; // Set bit 5 of data register B
  MyDelay(1000);
  *portB &= 0xDF; // Reset bit 5 of data register B
  MyDelay(1000);
}

void MyDelay(unsigned long mSecondsApx) // This is function definition
{
  volatile unsigned long i; // Initialize loop index
  unsigned long endTime = 1000 * mSecondsApx; // Calculate length of loop
  
  for (i = 0; i < endTime; i++); // Loop until end time reached
}
