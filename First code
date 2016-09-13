//First code
//Ultrasonic HC-SR04 in function
//Color sensor in function 
//The code are in portuguese (Brazil), but, the next versions will be made in english too
//Please check the component list for details
//ASS: Sargastico, contact: fernandocaro54@hotmail.com

char comando;

//Conexão dos sensores de distância HC-SR04
//Sensor para braço
int trigPin1 = 4;
int echoPin1 = 5;

//Sensor para cabeça
int trigPin2 = 2;
int echoPin2 = 3;

//Conexão sensor de cor
const int s0 = 8;  
const int s1 = 9;  
const int s2 = 12;  
const int s3 = 11;  
const int out = 10;   

int red = 0;  
int green = 0;  
int blue = 0;  

void setup() {
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(s0, OUTPUT);  
  pinMode(s1, OUTPUT);  
  pinMode(s2, OUTPUT);  
  pinMode(s3, OUTPUT);  
  pinMode(out, INPUT);   
  digitalWrite(s0, HIGH);  
  digitalWrite(s1, HIGH);  

  Serial.println("Projeto ativado");
  delay(5000);
  Serial.println("Sistema pronto");
  delay(2000);
  Serial.println("Aguardando comandos");

}
void firstsensor(){ // Função para o primeiro sensor
  int duration1, distance1;
  digitalWrite (trigPin1, HIGH);
  delayMicroseconds (10);
  digitalWrite (trigPin1, LOW);
  duration1 = pulseIn (echoPin1, HIGH);
  distance1 = (duration1/2) / 29.1;
  if(distance1<=40){
    Serial.println("Cuidado");
    delay(2000);    
  }
}
void secondsensor(){ //Função pra o segundo sensor
    int duration2, distance2;
    digitalWrite (trigPin2, HIGH);
    delayMicroseconds (10);
    digitalWrite (trigPin2, LOW);
    duration2 = pulseIn (echoPin2, HIGH);
    distance2 = (duration2/2) / 29.1; 
    if(distance2<=50){
    Serial.println("Cuidado com a cabeça"); 
    delay(2000);   
  }   
}


void loop() {
  comando = Serial.read();  
  if(comando == 'b'){
    comando = Serial.read();
  color(); 
  Serial.print("R Intensity:");  
  Serial.print(red, DEC);  
  Serial.print(" G Intensity: ");  
  Serial.print(green, DEC);  
  Serial.print(" B Intensity : ");  
  Serial.print(blue, DEC);  
  //Serial.println();  

  if (red < blue && red < green && red < 20)
  {  
   Serial.println(" - (Red Color)");  
  }  

  else if (blue < red && blue < green)   
  {  
   Serial.println(" - (Blue Color)");  
  }  

  else if (green < red && green < blue)  
  {  
   Serial.println(" - (Green Color)");  
  }  
  else{
  Serial.println();  
  }
  delay(300);   

 }  
   else{
   firstsensor();
   secondsensor();
   }
}    
void color()  
{    
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);  
  //count OUT, pRed, RED  
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);  
  //count OUT, pBLUE, BLUE  
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);  
  //count OUT, pGreen, GREEN  
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
}
