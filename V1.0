
//bibliotecas
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#include <Ultrasonic.h>
#include <OneWire.h>
#include <DallasTemperature.h>

LiquidCrystal lcd(9, 8, 5, 4, 3, 6);//pinos a serem conectados no arduino 

#define echoPin 12//Pino 13 recebe o pulso do echo   
#define trigPin 13 //Pino 12 envia o pulso para gerar o echo 
Ultrasonic ultrasonic(13,12);

#define ONE_WIRE_BUS 10
OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire);

int sinal = 12;

long microsec = 0;
float distanciaCM = 0;

//variaveis:
char serial,t,opcao,ok,comando;//variavel utilizada para armazenar os valores coletados no serial
int temp,cont,dist,kelvin,cont;

void setup() {
  
  //inicio da comunicação serial:
  Serial.begin(9600);   
  //Definição dos pinos:+
  pinMode(sinal, OUTPUT);
  
  pinMode(trigPin, OUTPUT);  // define o pino triger como saída.   
  pinMode(echoPin, INPUT);  // define o pino echo como entrada. 
  int dist = 0;
  //Inicialização do display
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  
  sensors.begin();
  
  lcd.print("Bem-Vindo =D ");
  delay(4000);
  lcd.clear();
  lcd.print("Conexao bluetooth");
  lcd.setCursor(0,1);
  lcd.print("disponivel");
  delay(2000);
  lcd.clear();
  lcd.print("Aguardando");
  delay(2000);
  lcd.clear();   
  }  
  
void loop(){ 
//verificação da conexão bluetooth.
  
  char ok = Serial.read();
  if(ok == 't'){
  while(ok == 't')  
  {
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("conectado!");
     delay(3000);
     lcd.setCursor(0,1);
     lcd.print("click o botão!");
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("1 - Iniciar");
     lcd.setCursor("2 -Para procurar");
     
     opcao = Serial.read();
     
     switch(opcao){
     case 'a':
     while(opcao == 'a')
     {
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("rodando...");
     microsec = ultrasonic.timing();
     dist = ultrasonic.convert(microsec, Ultrasonic::CM);
     temp = sensors.requestTemperatures();
     
     if(temp>=10||dist<=17){
       lcd.clear();
       lcd.setCursor(0,1);
       lcd.print("Cuidado!!!");
       digitalWrite(sinal, HIGH);
       delay(6000);
       digitalWrite(sinal, LOW);
       lcd.clear();
     }
     else
     {
       microsec = ultrasonic.timing();
       dist = ultrasonic.convert(microsec,Ultrasonic::CM);
       temp = sensors.requestTemperatures();
       lcd.clear;
       lcd.setCursor(0,0);
       kelvin=temp+273;
       lcd.print(temp);
       lcd.setCursor(3,0);
       lcd.print("Celsius");
       lcd.setCursor(0,1);
       lcd.print(kelvin);
       lcd.print(4,1);
       lcd.print("Kelvin");
     }
    }
    break;
    
    case 'b':
    while(opcao == 'b')
    {
      lcd.clear();
      lcd.print("Procurando....");
      for(int cont = 0; cont<=12; cont++)
      {
        digitalWrite(sinal, HIGH);
        delay(1000);
        digitalWrite(sinal, LOW);
      }
     opcao = 'a';        
    }
    break;
   } 
  }
 } 
     else
     {
     lcd.setCursor(0,0);
     lcd.clear();
     lcd.print("nao conectado...");
     lcd.setCursor(0,1);
     lcd.print("aguardando...");
     delay(1000);
      }   
     }
       






  
  
  
