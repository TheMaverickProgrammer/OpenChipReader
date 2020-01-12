void setup() {
  // Open serial connection.
  Serial.begin(9600);

  for(int i = 11; i > 1; i--){
    pinMode(i, INPUT_PULLUP); // Enable internal pull-up resistor on pin
  }
}

void loop() {
  int val = 0;
  String binary = String('1');

  for(int i = 11; i > 1; i--) {
    val = digitalRead(i);   // read the input pin

    if(val == HIGH) {
      val = LOW;
    }else{
      val = HIGH;
    }
    binary += String(val);
  }

  auto output = String();

  for(int i = 0; i < binary.length()-2; i++) {
    output += binary[i];
  }

  output += String('1');
  
  Serial.println(output);
  delay(1000); // ms
}
