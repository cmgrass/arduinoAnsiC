void NewDelay(unsigned long mSecondsApx);
#define MESSAGE_MAX_LEN 80
char message[MESSAGE_MAX_LEN];

void setup()
{
  unsigned char *portDDRB;
  
  portDDRB = (unsigned char *) 0x24;
  
  *portDDRB |= 0x20;

  Serial.begin(9600);
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

void NewDelay(unsigned long mSecondsApx)
{
  volatile unsigned long i;
  char j;
  long k;
  unsigned long endTime = 100 * mSecondsApx;

  for (i = 0; i < endTime; i++)
  {
    j = 10;
    
    do
    {
      j = j - 1;
      k = i / ((long) j);

      snprintf(message, MESSAGE_MAX_LEN, "%lu, %d, %ld\n", endTime, j, k);
      Serial.write(message);

    } while (k > 0);
  }
}
