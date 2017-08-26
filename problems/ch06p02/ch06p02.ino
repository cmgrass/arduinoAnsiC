void MyDelay(unsigned long milliSecondsApx);
#define MASK_BIT_00 0x01  // 0000 0001
#define MASK_BIT_01 0x02  // 0000 0010
#define MASK_BIT_02 0x04  // 0000 0100
#define MASK_BIT_03 0x08  // 0000 1000
#define MASK_BIT_04 0x10  // 0001 0000
#define MASK_BIT_05 0x20  // 0010 0000
#define MASK_BIT_06 0x40  // 0100 0000
#define MASK_BIT_07 0x80  // 1000 0000
#define DIRECTION_PORTD 0x7F  // 0111 1111

// DEBUGGING
//#define MESSAGE_LEN 80
//char message[MESSAGE_LEN];

void setup()
{
  unsigned char *portDDRD;

  portDDRD = (unsigned char *) 0x2A;

  *portDDRD |= DIRECTION_PORTD;  // Set data direction bits: D0 through D6 = `1`

  //Serial.begin(9600);
}

void loop()
{
  unsigned char *portD;
  
  portD = (unsigned char *) 0x2B;

  *portD |= MASK_BIT_00;
  MyDelay(1000);
  *portD &= (~MASK_BIT_00);
  MyDelay(1000);
}

void MyDelay(unsigned long milliSecondsApx)
{
  volatile unsigned long i;
  unsigned long endTime = milliSecondsApx * 1000;

  for (i = 0; i < endTime; i++);

  //snprintf(message, MESSAGE_LEN, "%lu\n", i);
  //Serial.write(message);
}
