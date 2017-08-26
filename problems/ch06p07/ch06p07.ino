void MyDelay(unsigned long milliSeconds);
#define MASK_PORTD_INPUT 0x01
#define MASK_PORTD_OUTPUT 0x0E  // NOT this for motor disable
#define MASK_MOTOR_DIR01 0x06
#define MASK_MOTOR_DIR02 0x0A
unsigned char *portDataD;
unsigned char *portPinD;

// Debugging
#define MESSAGE_MAX_LEN 80
char message[MESSAGE_MAX_LEN];

void setup()
{
  unsigned char *portDDRD;

  portDDRD = (unsigned char *) 0x2A;
  portDataD = (unsigned char *) 0x2B;
  portPinD = (unsigned char *) 0x29;

  *portDDRD &= (~MASK_PORTD_INPUT); // Define inputs
  *portDDRD |= MASK_PORTD_OUTPUT; // Define outputs
  *portDataD |= MASK_PORTD_INPUT; // Enable internal pullup resistor for input

  Serial.begin(9600);
}

void loop()
{
  *portDataD &= (~MASK_PORTD_OUTPUT);  // Disable motor
  *portDataD |= MASK_MOTOR_DIR01;
  snprintf(message, MESSAGE_MAX_LEN, "%#x\n", *portDataD);
  Serial.write(message);
  MyDelay(2000);
  *portDataD &= (~MASK_PORTD_OUTPUT);
  snprintf(message, MESSAGE_MAX_LEN, "%#x\n", *portDataD);
  Serial.write(message);
  MyDelay(2000);
  *portDataD &= (~MASK_PORTD_OUTPUT);
  *portDataD |= MASK_MOTOR_DIR02;
  snprintf(message, MESSAGE_MAX_LEN, "%#x\n", *portDataD);
  Serial.write(message);
  MyDelay(2000);
  *portDataD &= (~MASK_PORTD_OUTPUT);
  snprintf(message, MESSAGE_MAX_LEN, "%#x\n", *portDataD);
  Serial.write(message);
  MyDelay(2000);
}

void MyDelay(unsigned long milliSeconds)
{
  volatile unsigned long i;
  unsigned long endTime = 1000 * milliSeconds;

  for (i = 0; i < endTime; i++);
}

