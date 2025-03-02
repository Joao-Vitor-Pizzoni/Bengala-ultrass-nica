// Pino 12 irá receber o pulso do echo
int echoPino = 7;
// Pino 13 vai enviar o pulso para gerar o echo
int trigPino = 6;
long duracao = 0;
int distancia = 0;
void setup() {
// Iniciar a porta serial com velocidade de
// 9600 bits por segundo
Serial.begin(9600);
pinMode(echoPino, INPUT);
pinMode(trigPino, OUTPUT);
pinMode(12,OUTPUT);
}
void loop() {
// Pino trigger com um pulso baixo LOW
// (desligado)
digitalWrite(trigPino, LOW);
  // Delay (atraso) de 10 microssegundos
delayMicroseconds(10);
// Pino trigger com pulso HIGH (ligado)
digitalWrite(trigPino, HIGH);
// Delay (atraso) de 10 microssegundos
delayMicroseconds(10);
// Pino trigger com um pulso baixo LOW
// (desligado) novamente
digitalWrite(trigPino, LOW);
// A função pulseInt verifica o tempo que o
// pino ECHO ficou HIGH
// Calculando, desta forma, a duração do
// tráfego do sinal
duracao = pulseIn(echoPino,HIGH);
// Cálculo: distância = duração / 58.
distancia = duracao / 58;
if(distancia < 100)
   {
  		digitalWrite(12,HIGH);
  		delay(1000);
  		digitalWrite(12,LOW);
  		delay(100);
	}  
if((distancia > 100)&&(distancia < 200))
   {
  		digitalWrite(12,HIGH);
  		delay(2000);
  		digitalWrite(12,LOW);
  		delay(200);
	}
if((200 < distancia)&&(300>distancia))
	{
		digitalWrite(12,HIGH);
  		delay(3000);
  		digitalWrite(12,LOW);
  		delay(300);
	}
  

}