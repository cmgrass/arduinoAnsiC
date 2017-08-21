void NewDelay(unsigned char mSecondsApx);
//#define MESSAGE_MAX_LEN 80
//char message[MESSAGE_MAX_LEN];

void setup()
{  
  unsigned char *portDDRB;

  portDDRB = (unsigned char *) 0x24;

  *portDDRB |= 0x20;

  //Serial.begin(9600);
}

void loop()
{
  unsigned char *portB;

  portB = (unsigned char *) 0x25;

  *portB |= 0x20;
  NewDelay(100);
  *portB &= 0xDF;
  NewDelay(100);
}

void NewDelay(unsigned char mSecondsApx)
{
  volatile unsigned long i;
  unsigned long endTime = 1000 * ((long) mSecondsApx);

  //snprintf(message, MESSAGE_MAX_LEN, "%lu,%c\n", endTime, mSecondsApx);
  //Serial.write(message);

  /*
   * Turns out `void NewDelay(unsigned char mSecondsApx)` will not work with unsigned long arithmetic.
   * Had to typecase the `char` variable as a long in order for the arithmetic to work.
   * I used the serial and print functions to figure this out.
   */

  for (i = 0; i < endTime; i++);
}

