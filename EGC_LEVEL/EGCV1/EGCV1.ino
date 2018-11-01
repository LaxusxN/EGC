float valor;

float voltaje;

void setup(){

Serial.begin(9600);
}

void loop(){

valor=analogRead(A0);

voltaje=5*valor/1023;

Serial.println("*G");
Serial.println(valor);
Serial.println("*"):


delay(16);

}

