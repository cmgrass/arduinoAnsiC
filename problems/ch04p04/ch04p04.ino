void NewDelay(unsigned long mSecondsApx);
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
  NewDelay(1000);
  *portB &= 0xDF;
  NewDelay(1000);
}

void NewDelay(unsigned long mSecondsApx)
{
  volatile unsigned long i;
  unsigned char j = 0;
  unsigned long endTime = 100 * mSecondsApx;

  i = 0;
  
  while (j == 0)
  {
    i++;
    if (i == endTime)
    {
      j = 1;
    }
    //snprintf(message, MESSAGE_MAX_LEN, "%lu, %d, %lu\n", i, j, endTime);
    //Serial.write(message);      
  }
}
