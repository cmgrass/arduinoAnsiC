#define DEBUG_OUTPUT_MESSAGE_MAX_LENGTH 80  // Create a macro for our constant

void setup()
{
  char message[DEBUG_OUTPUT_MESSAGE_MAX_LENGTH];  // This byte array will contain our message string

  snprintf(message, DEBUG_OUTPUT_MESSAGE_MAX_LENGTH, "Hello, world!\n"); // same as `printf()`, except prints formatted string to memory buffer instead of standard output port.

  Serial.begin(9600);
  Serial.write(message);
}

void loop()
{
}
