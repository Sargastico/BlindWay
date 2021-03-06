#include <wire.h>
#include <Adafruit_MLX90614.h>

//Variaveis Globais.
//Global Variables.
char comando; 
int red = 0;  
int green = 0;  
int blue = 0;  

//Conexão do HC-SR04.
//HC-SR04 connection.
int trigPin1 = 4;
int echoPin1 = 5;

//Conexão do Vibracall.
//Vibracall connection.
int vibracall = 6;

//Conexão do buzzer.
//Buzzer connection.
int buzzer = 7;

//Conexão TCS230.
//TCS230 connection.
const int s0 = 8;  
const int s1 = 9;  
const int s2 = 12;  
const int s3 = 11;  
const int out = 10;   

//Conexão MLX90614 padrão: SDA -> A4 || SCL -> A5.
//Utiliza protocolo I2C para comunicação.
//Orientando as funções do sensor ao objeto 'mlx'.

//Standard connection for MLX90714: SDA -> A4 || SCL -> A5.
//Use I2C communication protocol.
//Gives function properties to the object called as 'mlx'.
mlx = Adafruit_MLX90614();

//Função que opera o buzzer para emissão de alertas sonoros -> Localização do dispositivo.
//Function to operate the buzzer and emit sound alerts -> Get the device's location.
void f_buzzer(){ 
	//Essa parte do código vai aplicar um efeito de sirene, utilizando uma f(x) = sen[(x*pi)/180],
	//onde x varia progressivamente no intervalo [0,180] -> Como evidenciado no laço de repetição.

	//This part of the code will apply a horn effect using a function: f(x) = sen[(x*pi)/180],
	//where x can assume values between the interval [0,180].
		for(int x=0;x<180;x++){
		seno=(sin(x*3.1416/180));
  		frequencia = 2000+(int(seno*1000));//gera uma frequência a partir do valor do seno.
  		tone(buzzer,frequencia);
  		delay(2);
  	}
}

//Função que captura, refina e analisa os dados obtidos pelo sensor HC-RS04 -> Sensor de distancia. 
//Function to capture and analyse the data sended by the distance sensor, HC-RS04.
void firstsensor(){
  int duration1, distance1;
  digitalWrite (trigPin1, HIGH);
  delayMicroseconds (10);
  digitalWrite (trigPin1, LOW);
  duration1 = pulseIn (echoPin1, HIGH);
  distance1 = (duration1/2) / 29.1;
  if(distance1<=40){
  	digitalWrite(vibracall, HIGH);
    delay(500);
    digitalWrite(vibracall, LOW);
  }
}

//Função que controla o sensor TCS230 -> Sensor de cor.
//Function to control the color sensor TCS230.
void color(){
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

  Serial.print("R Intensity:");  
  Serial.print(red, DEC);  
  Serial.print(" G Intensity: ");  
  Serial.print(green, DEC);  
  Serial.print(" B Intensity : ");  
  Serial.print(blue, DEC);  
  Serial.println();  

  if (red < blue && red < green && red < 20){  
  	Serial.println(" - (Red Color)");  
  }  

  else if (blue < red && blue < green){  
  	Serial.println(" - (Blue Color)");  
  }  

  else if (green < red && green < blue){  
   Serial.println(" - (Green Color)");  
  }  
  else{
  Serial.println();  
  }
  delay(300); 
}


void setup(){
  Serial.begin(9600);
  
  //Definição de I/O do microcontrolador.
  //Sets microcontroller I/O.
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  pinMode(vibracall, OUTPUT);

  pinMode(s0, OUTPUT);  
  pinMode(s1, OUTPUT);  
  pinMode(s2, OUTPUT);  
  pinMode(s3, OUTPUT);  
  pinMode(out, INPUT); 
    
  digitalWrite(s0, HIGH);  
  digitalWrite(s1, HIGH);  

  mlx.begin(); //Inicialização do sensor de temperatura.
  			   //Starts the temperature sensor.
  
  //Comunicação para com usuario de testes, somente visivel no monitor serial.
  //Communication with a test user, only visible on serial monitor.
  Serial.println("Projeto ativado");
  delay(2000);
  Serial.println("Sistema pronto");
  delay(2000);
  Serial.println("Aguardando comandos...");
}

void loop(){
  comando = Serial.read();  
    switch (comando) {

    	case 'a':
      		comando = Serial.read();
      		color(); 
      		break;

      	case 'b':
      		f_buzzer();
      		break;

      	default:
      		temp = mlx.readObjectTempC();
      			if(temp>=40){
      				digitalWrite(vibracall, HIGH);
      				delay(500);
      				digitalWrite(vibracall, LOW);
      			}

    		firstsensor();
   			break;
	}
}    

