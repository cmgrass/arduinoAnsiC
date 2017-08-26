void MyDelay(unsigned long milliSecondsApx);
void SevSegLookup(unsigned char myCharacter);
#define DIRECTION_PORTD 0x7F  // 0111 1111

void setup()
{
  unsigned char *portDDRD;

  portDDRD = (unsigned char *) 0x2A;

  *portDDRD |= DIRECTION_PORTD;  // Set data direction bits: D0 through D6 = `1`
}

void loop()
{
  volatile unsigned char k;
  unsigned char *portD;
  char myChar;

  portD = (unsigned char *) 0x2B;

  for (k = 0x30; k < 0x7B; k++)
    {
      myChar = k;
      SevSegLookup(myChar, portD);
      MyDelay(25);
      if (k >= 0x39 and k < 0x41)
        {
          k = 0x40;
        }
      else if (k >= 0x5A and k < 0x61)
        {
          k = 0x60;
        }
    }
}

void SevSegLookup(unsigned char myCharacter, unsigned char *outputPort)
{

  *outputPort &= (~DIRECTION_PORTD);  // Initialize outputs prior to lookup

  switch (myCharacter)
  {
    case 0x30:  // '0'
      *outputPort |= 0x01;
      break;

    case 0x31:  // '1'
      *outputPort |= 0x02;
      break;

    case 0x32:  // '2'
      *outputPort |= 0x03;
      break;

    case 0x33:  // '3'
      *outputPort |= 0x04;
      break;

    case 0x34:  // '4'
      *outputPort |= 0x05;
      break;

    case 0x35:  // '5'
      *outputPort |= 0x06;
      break;

    case 0x36:  // '6'
      *outputPort |= 0x07;
      break;

    case 0x37:  // '7'
      *outputPort |= 0x08;
      break;

    case 0x38:  // '8'
      *outputPort |= 0x09;
      break;

    case 0x39:  // '9'
      *outputPort |= 0x0A;
      break;

    case 0x41:  // 'A'
      *outputPort |= 0x0B;
      break;

    case 0x42:  // 'B'
      *outputPort |= 0x0C;
      break;

    case 0x43:  // 'C'
      *outputPort |= 0x0D;
      break;

    case 0x44:  // 'D'
      *outputPort |= 0x0E;
      break;

    case 0x45:  // 'E'
      *outputPort |= 0x0F;
      break;

    case 0x46:  // 'F'
      *outputPort |= 0x10;
      break;

    case 0x47:  // 'G'
      *outputPort |= 0x11;
      break;

    case 0x48:  // 'H'
      *outputPort |= 0x12;
      break;

    case 0x49:  // 'I'
      *outputPort |= 0x13;
      break;

    case 0x4A:  // 'J'
      *outputPort |= 0x14;
      break;

    case 0x4B:  // 'K'
      *outputPort |= 0x15;
      break;

    case 0x4C:  // 'L'
      *outputPort |= 0x16;
      break;

    case 0x4D:  // 'M'
      *outputPort |= 0x17;
      break;

    case 0x4E:  // 'N'
      *outputPort |= 0x18;
      break;

    case 0x4F:  // 'O'
      *outputPort |= 0x19;
      break;

    case 0x50:  // 'P'
      *outputPort |= 0x1A;
      break;

    case 0x51:  // 'Q'
      *outputPort |= 0x1B;
      break;

    case 0x52:  // 'R'
      *outputPort |= 0x1C;
      break;

    case 0x53:  // 'S'
      *outputPort |= 0x1D;
      break;

    case 0x54:  // 'T'
      *outputPort |= 0x1E;
      break;

    case 0x55:  // 'U'
      *outputPort |= 0x1F;
      break;

    case 0x56:  // 'V'
      *outputPort |= 0x20;
      break;

    case 0x57:  // 'W'
      *outputPort |= 0x21;
      break;

    case 0x58:  // 'X'
      *outputPort |= 0x22;
      break;

    case 0x59:  // 'Y'
      *outputPort |= 0x23;
      break;

    case 0x5A:  // 'Z'
      *outputPort |= 0x24;
      break;

    case 0x61:  // 'a'
      *outputPort |= 0x25;
      break;

    case 0x62:  // 'b'
      *outputPort |= 0x26;
      break;

    case 0x63:  // 'c'
      *outputPort |= 0x27;
      break;

    case 0x64:  // 'd'
      *outputPort |= 0x28;
      break;

    case 0x65:  // 'e'
      *outputPort |= 0x29;
      break;

    case 0x66:  // 'f'
      *outputPort |= 0x2A;
      break;

    case 0x67:  // 'g'
      *outputPort |= 0x2B;
      break;

    case 0x68:  // 'h'
      *outputPort |= 0x2C;
      break;

    case 0x69:  // 'i'
      *outputPort |= 0x2D;
      break;

    case 0x6A:  // 'j'
      *outputPort |= 0x2E;
      break;

    case 0x6B:  // 'k'
      *outputPort |= 0x2F;
      break;

    case 0x6C:  // 'l'
      *outputPort |= 0x30;
      break;

    case 0x6D:  // 'm'
      *outputPort |= 0x31;
      break;

    case 0x6E:  // 'n'
      *outputPort |= 0x32;
      break;

    case 0x6F:  // 'o'
      *outputPort |= 0x33;
      break;

    case 0x70:  // 'p'
      *outputPort |= 0x34;
      break;

    case 0x71:  // 'q'
      *outputPort |= 0x35;
      break;

    case 0x72:  // 'r'
      *outputPort |= 0x36;
      break;

    case 0x73:  // 's'
      *outputPort |= 0x37;
      break;

    case 0x74:  // 't'
      *outputPort |= 0x38;
      break;

    case 0x75:  // 'u'
      *outputPort |= 0x39;
      break;

    case 0x76:  // 'v'
      *outputPort |= 0x3A;
      break;

    case 0x77:  // 'w'
      *outputPort |= 0x3B;
      break;

    case 0x78:  // 'x'
      *outputPort |= 0x3C;
      break;

    case 0x79:  // 'y'
      *outputPort |= 0x3D;
      break;

    case 0x7A:  // 'z'
      *outputPort |= 0x3E;
      break;

    default:
      *outputPort |= (~DIRECTION_PORTD);
      break;

  }
}

void MyDelay(unsigned long milliSecondsApx)
{
  volatile unsigned long i;
  unsigned long endTime = milliSecondsApx * 1000;

  for (i = 0; i < endTime; i++);
}
