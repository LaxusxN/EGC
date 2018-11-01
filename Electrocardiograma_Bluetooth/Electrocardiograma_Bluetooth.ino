
//Sensor de ritmo cardiaco

//  Variables
int PulseSensor = A0 ;        // Conecte el cable rojo del sensor en pin analogico cero
int LED13 = 13;               // Blink del LED segun la frecuencia de pulsos
int Buzzer = 2;
int contador = 0;
int tiempo=0;
int constante =0;
int Signal = 0;                
int cero=480;

void setup() {
  pinMode(13,OUTPUT); 
  pinMode(2,OUTPUT);
  Serial.begin(19200);
  Serial1.begin(9600);           
}


void loop() {
tiempo=tiempo+1;
  Signal = analogRead(PulseSensor);  //Lectura de datos del sensor de ritmo cardiaco
                                              
   Serial.println(Signal);                   
   if(Signal > 580){                           
     digitalWrite(LED13,HIGH);   
     digitalWrite(Buzzer,HIGH);
     contador=contador+1;
   Serial1.print("*G");             //caracter definido en la aplicacion Bluetooth Electronic para empezar a recibir informacion
   Serial1.print(String(Signal));  //Mandamos la informacion al modulo HC-05
   Serial1.print("*");
   }
   
   if(Signal > 390 or Signal <= 580) 
   {
   digitalWrite(LED13,LOW);                
   digitalWrite(Buzzer,LOW);
   Serial1.print("*G");             //caracter definido en la aplicacion Bluetooth Electronic para empezar a recibir informacion
   Serial1.print(String(cero));  //Mandamos la informacion al modulo HC-05
   Serial1.print("*");
  if(Signal <= 390 ) 
   {
       digitalWrite(LED13,LOW);                
       
       digitalWrite(Buzzer,LOW);
         Serial1.print("*G");             //caracter definido en la aplicacion Bluetooth Electronic para empezar a recibir informacion
   Serial1.print(String(Signal));  //Mandamos la informacion al modulo HC-05
   Serial1.print("*");
  
   }
   }

   


if(tiempo<75)
{
 
    Serial1.print("*H");             //caracter definido en la aplicacion Bluetooth Electronic para empezar a recibir informacion
   Serial1.print(constante);  //Mandamos la informacion al modulo HC-05
   Serial1.print("*");
   delay(100);
   
}
else{
  if(tiempo==75){
    contador=contador*4;
    Serial1.print("*H");             //caracter definido en la aplicacion Bluetooth Electronic para empezar a recibir informacion
   Serial1.print(contador);  //Mandamos la informacion al modulo HC-05
   Serial1.print("*");
   delay(1000);
  }
  if(tiempo>75){
    tiempo=0;
    contador=0;
   delay(300);
  }
}
 
      Serial1.print("*M");             //caracter definido en la aplicacion Bluetooth Electronic para empezar a recibir informacion
   Serial1.print(String(tiempo));  //Mandamos la informacion al modulo HC-05
   Serial1.print("*");
   delay(100);
   digitalWrite(Buzzer,LOW);
   
}
