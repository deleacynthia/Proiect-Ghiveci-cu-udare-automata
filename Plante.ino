  int relay = 2;
int Led = 13;
#define sensorPower 7
#define sensorPin 8

#define sensorPower_2 9
#define sensorPin_2 10

int readSensor() {
  digitalWrite(sensorPower, HIGH);  
  delay(10);              
  int sensorVal = digitalRead(sensorPin); // valoarea citita de senzor
  digitalWrite(sensorPower, LOW);   
  return sensorVal;             // returneaza valoarea anologiga citita de senzor
}

int readSensor_2() {
  digitalWrite(sensorPower_2, HIGH);  
  delay(10);              
  int sensorVal_2 = digitalRead(sensorPin_2); // valoarea citita de senzor
  digitalWrite(sensorPower_2, LOW);   
  return sensorVal_2;             // returneaza valoarea anologiga citita de senzor
}


void setup() {

  pinMode(Led, OUTPUT);
  pinMode(relay, OUTPUT);
  pinMode(sensorPower, OUTPUT);
  digitalWrite(sensorPower, LOW);

  pinMode(sensorPower_2, OUTPUT);
  digitalWrite(sensorPower_2, LOW);

  Serial.begin(9600);

}

void loop() {

int sensorVal = readSensor();

int sensorVal_2 = readSensor_2();

  Serial.print("Digital Output senzor 1: ");
  Serial.println(sensorVal);

  Serial.print("Digital Output senzor 2: ");
  Serial.println(sensorVal_2);


  // Verificam starea solului, daca valoarea citita este 1 atunci solul trebuie udat, altfel solul este perfect
  if (sensorVal == 1 &&  sensorVal_2 == 1 ) { // daca ambele sunt 1 porneste pompa
    digitalWrite(Led, HIGH);
    Serial.println("Status: APA!!!");
    digitalWrite(relay, LOW);
    delay(500);
  } else { // daca ambele sunt 0 atunci se opreste pompa 
    digitalWrite(Led, LOW);
    Serial.println("Status: Perfect");
    digitalWrite(relay, HIGH);
    delay(2000);
  }
  
  delay(500);  //  citeste valoarea senzorului de umiditate pentru a putea fi testata
      
  Serial.println();
  
}
