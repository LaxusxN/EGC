int val;
int LED12 = 12;               // Blink del LED segun la frecuencia de pulsos
int Buzzer = 2;
int Threshold = 540;

void setup(){
  pinMode(12,OUTPUT); 
  pinMode(2,OUTPUT);
  Serial.begin(19200);
}

void loop(){

val=analogRead(A0);
if(val >= Threshold){                           
     digitalWrite(LED12,HIGH);   
     digitalWrite(Buzzer,HIGH);
}
else{
     digitalWrite(LED12,LOW); 
    digitalWrite(Buzzer,LOW);
}
Serial.println(val);
delay(100);

}
