#define MODE_BTN 19
#define START_STOP_BTN 18
#define SPEED_UP_BTN 17
#define SPEED_DOWN_BTN 16
#define DIR_BTN 15

#define STATUS_LED 0
#define DIR_LED 1

#define SEG_A 8
#define SEG_B 7
#define SEG_C 6
#define SEG_D 5 
#define SEG_E 4
#define SEG_F 3
#define SEG_G 2

const uint8_t SEG_7[7] = {
  SEG_A,
  SEG_B,
  SEG_C,
  SEG_D,
  SEG_E,
  SEG_F,
  SEG_G
};


//?~ states
bool status = 0;  //!~ 0=off, 1=on
bool dir = 1;     //!~ 0=reverse, 1=forward


void display_mode(char ch);


void setup() {
  //?~ btns setup 
  pinMode(MODE_BTN, INPUT_PULLUP);
  pinMode(START_STOP_BTN, INPUT_PULLUP);
  pinMode(SPEED_UP_BTN, INPUT_PULLUP);
  pinMode(SPEED_DOWN_BTN, INPUT_PULLUP);
  pinMode(DIR_BTN, INPUT_PULLUP);
  //?~ leds setup 
  pinMode(STATUS_LED, OUTPUT);
  pinMode(DIR_LED, OUTPUT);
  //?~ 7-segments setup
  for(uint8_t i = 0; i < 7; i++) pinMode(SEG_7[i], OUTPUT);
}


void loop() {

  if(!digitalRead(START_STOP_BTN)) status = !status;

  if(status) {
    if(!digitalRead(DIR_BTN)) dir = !dir;
    digitalWrite(STATUS_LED, 1);
    digitalWrite(DIR_LED, dir);
    display_mode('0');
    delay(1000);
    display_mode('1');
    delay(1000);
    display_mode('2');
    delay(1000);
    display_mode('3');
    delay(1000);
    display_mode('4');
    delay(1000);  
    display_mode('E');
    delay(1000);
  }
  else {
    digitalWrite(STATUS_LED, 0);
    digitalWrite(DIR_LED, 0);
  }

}


void display_mode(char ch)	{
  switch(ch) {
    case '0':
      digitalWrite(SEG_7[0], 1);	
      digitalWrite(SEG_7[1], 1);	
      digitalWrite(SEG_7[2], 1);
      digitalWrite(SEG_7[3], 1);
      digitalWrite(SEG_7[4], 1);
      digitalWrite(SEG_7[5], 1);
      digitalWrite(SEG_7[6], 0); 
    break;
    case '1':
      digitalWrite(SEG_7[0], 0);	
      digitalWrite(SEG_7[1], 1);
      digitalWrite(SEG_7[2], 1);
      digitalWrite(SEG_7[3], 0);	
      digitalWrite(SEG_7[4], 0);
      digitalWrite(SEG_7[5], 0);
      digitalWrite(SEG_7[6], 0);
    break;
    case '2':
      digitalWrite(SEG_7[0], 1);
      digitalWrite(SEG_7[1], 1);
      digitalWrite(SEG_7[2], 0);
      digitalWrite(SEG_7[3], 1);
      digitalWrite(SEG_7[4], 1);
      digitalWrite(SEG_7[5], 0);
      digitalWrite(SEG_7[6], 1);
    break;
    case '3':
      digitalWrite(SEG_7[0], 1);
      digitalWrite(SEG_7[1], 1);
      digitalWrite(SEG_7[2], 1);
      digitalWrite(SEG_7[3], 1);
      digitalWrite(SEG_7[4], 0);
      digitalWrite(SEG_7[5], 0);
      digitalWrite(SEG_7[6], 1);
    break;
    case '4':
      digitalWrite(SEG_7[0], 0);
      digitalWrite(SEG_7[1], 1);
      digitalWrite(SEG_7[2], 1);
      digitalWrite(SEG_7[3], 0);
      digitalWrite(SEG_7[4], 0);
      digitalWrite(SEG_7[5], 1);
      digitalWrite(SEG_7[6], 1);
    break;
    default:
      digitalWrite(SEG_7[0], 0);
      digitalWrite(SEG_7[1], 0);
      digitalWrite(SEG_7[2], 0);
      digitalWrite(SEG_7[3], 0);
      digitalWrite(SEG_7[4], 0);
      digitalWrite(SEG_7[5], 0);
      digitalWrite(SEG_7[6], 0);
    break;
  }
}
