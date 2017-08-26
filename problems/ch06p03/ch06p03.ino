void PinState(unsigned char *inputPort, unsigned char *prevSample, unsigned char *currSample, unsigned char mask);
void DebounceInput(unsigned char *inputPort);
void MyDelay(unsigned long milliSeconds);
#define MASK_BIT01 0x01
unsigned char *portDataD;

// DEBUGGING
//#define MESSAGE_MAX_LEN 80

void setup()
{
  unsigned char *portDDRD;

  portDDRD = (unsigned char *) 0x2A;
  portDataD = (unsigned char *) 0x2B;

  *portDDRD &= (~MASK_BIT01);  // Enable pin D0 as input
  *portDataD |= MASK_BIT01; // Enable internal pullup on pin D0

  //Serial.begin(9600);
}

void loop()
{
  unsigned char *portPinD;
  unsigned char previousSample;
  unsigned char currentSample;
  unsigned char *prevSampleAddr;
  unsigned char *currSampleAddr;
  
  portPinD = (unsigned char *) 0x29;
  prevSampleAddr = &previousSample;
  currSampleAddr = &currentSample;

  PinState(portPinD, prevSampleAddr, currSampleAddr, MASK_BIT01);
}

void PinState(unsigned char *inputPort, unsigned char *prevSample, unsigned char *currSample, unsigned char mask)
{
  unsigned char confirmSample;
  //char message[MESSAGE_MAX_LEN];
  
  *currSample = (*inputPort) & mask;

  if (*currSample != *prevSample)
  {
    DebounceInput();
    confirmSample = (*inputPort) & mask;

    if (confirmSample == *currSample)
    {
      // Valid transition
      //snprintf(message, MESSAGE_MAX_LEN, "Change State: %d\n", *currSample);
      //Serial.write(message);
    }
  }
  
  *prevSample = *currSample;

}

void DebounceInput()
{
  MyDelay(10);
}

void MyDelay(unsigned long milliSeconds)
{
  volatile unsigned long i;
  unsigned long endTime = 100 * milliSeconds;

  for (i = 0; i < endTime; i++);
}

