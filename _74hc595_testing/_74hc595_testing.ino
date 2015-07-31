int latch = 7;
int data = 10;
int clock = 9;
int heart = 13;
int clr = 8;

char frame[8];
char frameIdx;

char pinVal = 0xc3;

void setup() {
  // put your setup code here, to run once:
  pinMode(latch, OUTPUT);
  pinMode(data, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(heart, OUTPUT);
  pinMode(clr, OUTPUT);

  frameIdx = 0;

  /*for (char i = 0; i < 8; i++)
  {
    frame[i][0] = 0x01 << i;
    frame[i][1] = 0x00;
    frame[i + 8][0] = 0x00;
    frame[i + 8][1] = 0x01 << i;
  }*/
  frame[0] = 0b00111100;
  frame[1] = 0b01000010;
  frame[2] = 0b10100101;
  frame[3] = 0b10000001;
  frame[4] = 0b10100101;
  frame[5] = 0b10011001;
  frame[6] = 0b01000010;
  frame[7] = 0b00111100;

  //PORTD = PORTD & 0b01111111; //clear latch pin
  //PORTB = PORTB & 0b11111001; //clear the data and clock pins
  
  digitalWrite(clr, LOW);
  digitalWrite(clr, HIGH);

  digitalWrite(latch, LOW);
  digitalWrite(data, LOW);
  digitalWrite(clock, LOW);
  //shiftOut(data, clock, LSBFIRST, 0x0f);
  //digitalWrite(latch, HIGH);
  //digitalWrite(latch, LOW);
  //shiftOut(data, clock, LSBFIRST, 0xff);
  //shiftOut(data, clock, LSBFIRST, 0x00);
  //for (char i = 0; i < 8; i++)
  //{
  //  digitalWrite(latch, HIGH);
    //digitalWrite(latch, LOW);
  //  delay(500);
  //}
}

void loop() {
  //displayRow();
  delay(230);
  pinVal ^= 0xff;
  digitalWrite(data, LOW);
  digitalWrite(latch, HIGH);
  shiftOut(data, clock, LSBFIRST, pinVal);
  digitalWrite(latch, LOW);
  
}

void displayRow()
{
  if (frameIdx >= 8)
  {
    frameIdx = 0;
  }

  //shift out rows byte
  char rowByte = 0x01 << frameIdx;
  for (char i = 0; i < 8; ++i)
  {
    //set data pin
    PORTB = (PORTB | 0b00000100) & (((0x00 >> i) & 0x01) << 2);
    //set clock pin
    PORTB = PORTB | 0b00000010;
    //reset clock pin
    PORTB = PORTB & 0b11111101;
  }

  //shift out columns byte
  for (char i = 0; i < 8; ++i)
  {
    //set data pin
    //PORTB = (PORTB | 0b00000100) & (((frame[frameIdx] >> i) & 0x01) << 2);
    PORTB = (PORTB | 0b00000100) & (((rowByte >> i) & 0x01) << 2);
    //set clock pin
    PORTB = PORTB | 0b00000010;
    //reset clock pin
    PORTB = PORTB & 0b11111101;
  }

  //set latch pin
  PORTD = PORTD | 0b10000000;
  //clear latch pin
  PORTD = PORTD & 0b01111111;

  ++frameIdx;
}

void shiftByte(char val)
{

}

