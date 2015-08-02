int clock = 6;  //PORTD 0b01000000
int latch = 5;  //PORTD 0b00100000
int data = 4;   //PORTD 0b00010000


int heart = 13;


char frame[8];
char frameIdx;

int pinVal = 0x01;

void setup() {
  // put your setup code here, to run once:
  //pinMode(latch, OUTPUT);
  //pinMode(data, OUTPUT);
  //pinMode(clock, OUTPUT);
  //pinMode(heart, OUTPUT);
  
  //enable clock, latch, and data pins for output
  DDRD = DDRD | 0b01110000;

  frameIdx = 0;

  frame[0] = 0b00111100;
  frame[1] = 0b01000010;
  frame[2] = 0b10100101;
  frame[3] = 0b10000001;
  frame[4] = 0b10100101;
  frame[5] = 0b10011001;
  frame[6] = 0b01000010;
  frame[7] = 0b00111100;

  PORTD = PORTD & 0b10001111; //clear clock, data, and latch pins

  //digitalWrite(latch, LOW);
  //digitalWrite(data, LOW);
  //digitalWrite(clock, LOW);

}

void loop() 
{
  displayRow(frameIdx);
  delay(2);
  if(++frameIdx > 7)
  {
    frameIdx = 0;
  }

  //The following code controls 16 leds on two shift registers
  // flashing them all, one by one, in order
  /*pinVal = pinVal << 1;
   if(pinVal == 0)
   pinVal = 0x01;
   digitalWrite(data, LOW);
   digitalWrite(latch, LOW);
   char highVal = (pinVal >> 8) & 0xff;
   char lowVal = pinVal & 0xff;
   shiftOut(data, clock, LSBFIRST, lowVal);
   shiftOut(data, clock, LSBFIRST, highVal);
   digitalWrite(latch, HIGH);
   */
}

void displayRow(char rowIdx)
{
  //clear latch pin
  PORTD = PORTD & 0b11011111;
  
  //shift out col byte
  shiftByte(frame[rowIdx]);

  //shift out row byte
  shiftByte(~(0x01 << (7-rowIdx)));
  
  //set latch pin
  PORTD = PORTD | 0b00100000;
  //delay(200);
}

void shiftByte(char val)
{
  for(char i=0; i<8; ++i)
  {
    //clear clock pin
    PORTD = PORTD & 0b10111111;
    //set data pin
    PORTD = (PORTD & 0b11101111) | (((val >> i) & 0x01) << 4);
    //set clock pin
    PORTD = PORTD | 0b01000000;
    //reset clock pin
    PORTD = PORTD & 0b10111111;
  }
}


