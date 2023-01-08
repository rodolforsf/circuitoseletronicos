#define sensorPin A0
int led = 13;
int motor = 10;
int buzzer = 7;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(motor, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {  
  int reading = analogRead(sensorPin);  
  float voltage = reading * (5000 / 1024.0);  
  float temperatura = (voltage - 500) / 10;
  
  Serial.print(temperatura);
  Serial.print(" \xC2\xB0"); 
  Serial.println("C");
  delay(100); 
  
    if(temperatura > 30){
    digitalWrite(motor, HIGH);
  }else{
    digitalWrite(motor, LOW);
  }
    if(temperatura > 50){
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
  }else{
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
  }  
}