
//Sensor de ritmo cardiaco

//  Variables
int PulseSensor = A0 ;        // Conecte el cable rojo del sensor en pin analogico cero
int LED13 = 13;               // Blink del LED segun la frecuencia de pulsos
int Buzzer = 2;
int contador = 0;
int tiempo=0;
int constante =0;
int Signal = 0;                
int Threshold = 640;           //Dato analogico considerado como un pulso     


void setup() {
  pinMode(13,OUTPUT); 
  pinMode(2,OUTPUT);
  Serial.begin(19200);
  Serial1.begin(9600);           
}


void loop() {
  tiempo=tiempo+1;
  Signal = analogRead(PulseSensor);  //Lectura de datos del sensor de ritmo cardiaco
   Serial1.print("*F");             
   Serial1.print(tiempo);  
   Serial1.print("*");
   Serial1.print("*G");             //caracter definido en la aplicacion Bluetooth Electronic para empezar a recibir informacion
   Serial1.print(String(Signal));  //Mandamos la informacion al modulo HC-05
   Serial1.print("*");                                          
   Serial.println(Signal);   
   delay(20);          
           
   if(Signal > Threshold){                           
     digitalWrite(LED13,HIGH);   
     digitalWrite(Buzzer,HIGH);
     contador=contador+1;
     delay(5);
   }

   if(Signal <Threshold) 
   {
       digitalWrite(LED13,LOW);                
       digitalWrite(Buzzer,LOW);
   }


if(tiempo<750)
{
   Serial1.print("*H");             
   Serial1.print(constante);  
   Serial1.print("*");
   
}
else{
  if(tiempo==750){
   contador=contador*2;
   Serial1.print("*H");             //caracter definido en la aplicacion Bluetooth Electronic para empezar a recibir informacion
   Serial1.print(contador);  //
   Serial1.print("*");
   constante=contador;
  }
  if(tiempo>750){
   tiempo=0;
   contador=0;
  }
}

   
}
