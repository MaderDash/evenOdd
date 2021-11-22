int even        = 0;
int odd         = 0;
bool output     = 0;
bool reset      = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("starting");
}

void loop() {
  if (Serial.available() > 0) {
    int value = Serial.parseInt();
   
      
      if ((value % 2) == 0) {
        even++;
        output    = 1;
        reset     = 1;
      } else {
        odd++;
        output    = 0;
        reset     = 1;
      }
    
    value = Serial.parseInt();
  }
  
  if (reset) {

    reset = 0;
    if (output) {
      Serial.println("The number you entered was even. ");
    } else {
      Serial.println("The number you entered was odd.");
    }
    Serial.println("Sofar you have entered " + String(even) + " even Numbers");
    Serial.println("Sofar you have entered " + String(odd) + "   odd Numbers");
    delay(1000);
  }
}
