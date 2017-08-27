void PinStateOns(unsigned char *inputPort, unsigned char *motorState, unsigned char *prevSample, unsigned char *currSample, unsigned char mask);
void MotorControl(unsigned char *inputPort, unsigned char *motorState);
void DebounceInput();
void MyDelay(unsigned long milliSeconds);
#define MASK_PORTD_INPUT 0x01
#define MASK_PORTD_OUTPUT 0x0E  // NOT this for motor disable
#define MASK_MOTOR_DIR01 0x06
#define MASK_MOTOR_DIR02 0x0A
unsigned char *portDataD;
unsigned char *portPinD;

// Debugging
//#define MESSAGE_MAX_LEN 80

void setup()
{
  unsigned char *portDDRD;

  portDDRD = (unsigned char *) 0x2A;
  portDataD = (unsigned char *) 0x2B;
  portPinD = (unsigned char *) 0x29;

  *portDDRD &= (~MASK_PORTD_INPUT); // Define inputs
  *portDDRD |= MASK_PORTD_OUTPUT; // Define outputs
  *portDataD |= MASK_PORTD_INPUT; // Enable internal pullup resistor for input

  //Serial.begin(9600);
}

void loop()
{  
  unsigned char previousSample;
  unsigned char currentSample;
  unsigned char myMotorState;
  unsigned char *prevSampleAddr;
  unsigned char *currSampleAddr;
  unsigned char *motorStateAddr;
  
  prevSampleAddr = &previousSample;
  currSampleAddr = &currentSample;
  motorStateAddr = &myMotorState;
  
  PinStateOns(portPinD, motorStateAddr, prevSampleAddr, currSampleAddr, MASK_PORTD_INPUT);

}

void PinStateOns(unsigned char *inputPort, unsigned char *motorState, unsigned char *prevSample, unsigned char *currSample, unsigned char mask)
{
  /* One shot pin state change*/
  
  unsigned char confirmSample;
  //char message[MESSAGE_MAX_LEN];

  *currSample = (*inputPort) & mask;

  if (*currSample != *prevSample)
  {
    DebounceInput();
    confirmSample = (*inputPort) & mask;

    if (confirmSample == *currSample)
    {
      MotorControl(inputPort, motorState);
      //snprintf(message, MESSAGE_MAX_LEN, "Change State: %#x\n", *motorState);
      //Serial.write(message);
    }
  }
  *prevSample = *currSample;
}

void MotorControl(unsigned char *inputPort, unsigned char *motorState)
{
  switch (*motorState)
  {
    case (0x01):
      *inputPort &= (~MASK_PORTD_OUTPUT);
      *inputPort |= MASK_MOTOR_DIR01;
      *motorState = 0x02;
      break;

    case (0x02):
      *inputPort &= (~MASK_PORTD_OUTPUT);
      *motorState = 0x03;
      break;

    case (0x03):
      *inputPort &= (~MASK_PORTD_OUTPUT);
      *inputPort |= MASK_MOTOR_DIR02;
      *motorState = 0x04;
      break;

    case (0x04):
      *inputPort &= (~MASK_PORTD_OUTPUT);
      *motorState = 0x01;

    default:
      *inputPort &= (~MASK_PORTD_OUTPUT);
      *motorState = 0x01;
      break;
  }
}

void DebounceInput()
{
  MyDelay(10);
}

void MyDelay(unsigned long milliSeconds)
{
  volatile unsigned long i;
  unsigned long endTime = 1000 * milliSeconds;

  for (i = 0; i < endTime; i++);
}

