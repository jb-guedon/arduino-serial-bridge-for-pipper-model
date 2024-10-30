/*
code to pilot the EM-337A-PLI controler for accurator

- connect the relay card to the accurator on pin 5v, FW, BW
- connect the arduino by usb serial at 9600 baud
- send '1' to serial to bring up the accurator
- send '2' to lower the accurator 

!!! wait for the accurator have reached their position befor 
send a new order otherwise it will not take the new order !!!

pin high = relay off
pin low = relay on

*/

int up = 10;                                //pin for up
int down = 11;                              //pin for down
int up_time_val = 29000;                    //lift up time
int down_time_val = up_time_val + 1000;     //lift down time (=lift up time + 1 seccond)
bool state = false;                         //security flag     false = down    true = up

void setup() {
  Serial.begin(9600);
  pinMode(up, OUTPUT);
  pinMode(down, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  STOP();
}

void loop() {
  if (Serial.available()) {
    char val = Serial.read();
    if (val == '1' && !state) {
      GO_UP();
      delay(up_time_val);
      STOP();
    } else if (val == '2' && state) {
      GO_DOWN();
      delay(down_time_val);
      STOP();
    }
    Serial.flush();
  }
}

void GO_UP() {
  digitalWrite(down, HIGH);             //this is to be sure the down "button" is not push
  digitalWrite(up, LOW);                //activate the up "button"
  digitalWrite(LED_BUILTIN, HIGH);      //for the visual signal
  state = true;                         //set the security flag
}

void GO_DOWN() {
  digitalWrite(up, HIGH);               //this is to be sure the up "button" is not push
  digitalWrite(down, LOW);              //activate the down "button"
  digitalWrite(LED_BUILTIN, HIGH);      //for the visual signal
  state = false;                        //set the security flag
}

void STOP() {
  digitalWrite(down, HIGH);             //release the down button
  digitalWrite(up, HIGH);               //release the up button
  digitalWrite(LED_BUILTIN, LOW);       //turn off the visual signal
}