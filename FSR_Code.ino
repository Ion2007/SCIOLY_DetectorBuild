int FSR = 0;  
int redLed = 5;
int greenLed = 4;
int blueLed= 3;
int fsrRead;
float voltage;
float t2;
float t1;
float T;
float sum=0.0f;
void setup() {


  Serial.begin(9600);
  t1=millis();


  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  // initialize the led pins as an output
 
}


float predict(float v){
  return 13.8 * exp(.918*v);
}


void loop() {
 
// The commented code below was to find 
  t2=millis();//the aveage voltage detected in one minute
  if(t2-t1>=10000-50 && t2-t1<=10000+50 ){
    
    Serial.print("Analog reading = ");
Serial.print(sum/100.0);
//prints analog value from sensor


Serial.print(" Voltage = ");
Serial.print(T/100.0);
//prints voltage from sensor


Serial.print(" Mass = ");
Serial.println(predict(T/100.0));
//prints predicted mass of object
  }
fsrRead = analogRead(FSR);
//reads analog value of sensor
sum+=fsrRead;
voltage = (fsrRead/1023.0)*5.0;
//converts analog data to voltage






  if (predict(voltage)>=500 && predict(voltage)<=1000){
    digitalWrite(redLed,HIGH);
     digitalWrite(greenLed,LOW);
    digitalWrite(blueLed,LOW);
  }
  else if (predict(voltage)>100 && predict(voltage)<500){
    digitalWrite(greenLed,HIGH);
    digitalWrite(redLed,LOW);
    digitalWrite(blueLed,LOW);
  }
  else if (predict(voltage)<=100 && predict(voltage)>=30){
  digitalWrite(blueLed,HIGH);
   digitalWrite(redLed,LOW);
    digitalWrite(greenLed,LOW);
  }
  else{
    digitalWrite(redLed,LOW);
    digitalWrite(greenLed,LOW);
    digitalWrite(blueLed,LOW);
  }
// Detirmines Which LED
  delay(100);
  //LEDBright = map(fsrRead,0,1023,0,255);
  T+=voltage;


}
