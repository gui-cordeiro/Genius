/*
 * -> Código-Fonte do Genius
 * -> Desenvolvido por: Guilherme Cordeiro
 * -> Ano: 2020
 * 
 * -> [ATENÇÃO] O projeto está configurado para rodar em quaisquer micro-
 * 	controladores que possuam o chip ATmega328P, como o Arduino UNO e
 * 	Nano. Caso opte por utilizar um microcontrolador que tenha um chip
 * 	diferente, altere a configuração de placa em "platformio.ini".
 */

#include <Arduino.h>

// Pinos dos LED's
#define LED_Amarelo 13
#define LED_Verde 12
#define LED_Vermelho 11
#define LED_Azul 10

// Pinos dos botões correspondentes aos LED's
#define Botao1 5
#define Botao2 4
#define Botao3 3
#define Botao4 2

// Pino do buzzer e definição das frequências sonoras relativas a cada cor
#define Buzzer 9
#define Nota1 294
#define Nota2 392
#define Nota3 440
#define Nota4 880

// Estado atual dos botões (para prevenir duplo clique acidental)
int EstadoBotao1 = 0;
int EstadoBotao2 = 0;
int EstadoBotao3 = 0;
int EstadoBotao4 = 0;

// Vetores que armazenam a sequência de cores do jogo
int sequencia[100] = {};
int tentativa[100] = {};

// Variáveis de controle
int numero = 0;
int controle = 0;
int cont = 0;

// Declaração das funções auxiliares
void fimDeJogo();
void inicioJogo();

void setup() {
	Serial.begin(9600);
	pinMode(Buzzer, OUTPUT);
	
	pinMode(LED_Amarelo, OUTPUT);
	pinMode(LED_Verde, OUTPUT);
	pinMode(LED_Vermelho, OUTPUT);
	pinMode(LED_Azul, OUTPUT);

	pinMode(Botao1, INPUT_PULLUP);
	pinMode(Botao2, INPUT_PULLUP);
	pinMode(Botao3, INPUT_PULLUP);
	pinMode(Botao4, INPUT_PULLUP);

	randomSeed(analogRead(A0));

	inicioJogo();
}

void loop() {
	for(controle = 0; controle < 100; controle ++){
		sequencia[controle] = random(4);
		numero = 0;
		do{
			if(sequencia[numero] == 0){
			digitalWrite(LED_Amarelo, HIGH);
			tone(Buzzer, Nota1);
			delay(500);
			digitalWrite(LED_Amarelo, LOW);
			noTone(Buzzer);
			delay(100);
		}
		else if(sequencia[numero] == 1){
			digitalWrite(LED_Verde, HIGH);
			tone(Buzzer, Nota2);
			delay(500);
			digitalWrite(LED_Verde, LOW);
			noTone(Buzzer);
			delay(100);
		}
		else if(sequencia[numero] == 2){
			digitalWrite(LED_Vermelho, HIGH);
			tone(Buzzer, Nota3);
			delay(500);
			digitalWrite(LED_Vermelho, LOW);
			noTone(Buzzer);
			delay(100);
		}
		else if(sequencia[numero] == 3){
			digitalWrite(LED_Azul, HIGH);
			tone(Buzzer, Nota4);
			delay(500);
			digitalWrite(LED_Azul, LOW);
			noTone(Buzzer);
			delay(100);
		}
		numero ++;
		}while(numero <= controle);
		numero = 0;
			do{
				if(digitalRead(Botao1) == 0){
					digitalWrite(LED_Amarelo, HIGH);
					tone(Buzzer, Nota1);
					delay(300);
					digitalWrite(LED_Amarelo, LOW);
					noTone(Buzzer);
					tentativa[numero] = 0;
					if(tentativa[numero] == sequencia[numero]){
						numero ++;
					}
					else{
						fimDeJogo();
					}
				}
				if(digitalRead(Botao2) == 0){
					digitalWrite(LED_Verde, HIGH);
					tone(Buzzer, Nota2);
					delay(300);
					digitalWrite(LED_Verde, LOW);
					noTone(Buzzer);
					tentativa[numero] = 1;
					if(tentativa[numero] == sequencia[numero]){
						numero ++;
					}
					else{
						fimDeJogo();
					}
				}
				if(digitalRead(Botao3) == 0){
					digitalWrite(LED_Vermelho, HIGH);
					tone(Buzzer, Nota3);
					delay(300);
					digitalWrite(LED_Vermelho, LOW);
					noTone(Buzzer);
					tentativa[numero] = 2;
					if(tentativa[numero] == sequencia[numero]){
						numero ++;
					}
					else{
						fimDeJogo();
					}
				}
				if(digitalRead(Botao4) == 0){
					digitalWrite(LED_Azul, HIGH);
					tone(Buzzer, Nota4);
					delay(300);
					digitalWrite(LED_Azul, LOW);
					noTone(Buzzer);
					tentativa[numero] = 3;
					if(tentativa[numero] == sequencia[numero]){
						numero ++;
					}
					else{
						fimDeJogo();
					}
				}
		 delay(10);
		 Serial.print(numero);
		 Serial.print(" e ");
		 Serial.println(controle);
		 }while(numero <= controle);
	delay(1000);
	}
}

void fimDeJogo(){
	delay(150);
	digitalWrite(LED_Amarelo, HIGH);
	tone(Buzzer, Nota4);
	delay(150);
	digitalWrite(LED_Amarelo, LOW);
	noTone(Buzzer);
	digitalWrite(LED_Verde, HIGH);
	tone(Buzzer, Nota3);
	delay(150);
	digitalWrite(LED_Verde, LOW);
	noTone(Buzzer);
	digitalWrite(LED_Vermelho, HIGH);
	tone(Buzzer, Nota2);
	delay(150);
	digitalWrite(LED_Vermelho, LOW);
	noTone(Buzzer);
	digitalWrite(LED_Azul, HIGH);
	tone(Buzzer, Nota1);
	delay(150);
	digitalWrite(LED_Azul, LOW);
	noTone(Buzzer);
	tone(Buzzer, Nota1);
	digitalWrite(LED_Amarelo, HIGH);
	digitalWrite(LED_Verde, HIGH);
	digitalWrite(LED_Vermelho, HIGH);
	digitalWrite(LED_Azul, HIGH);
	delay(100);
	digitalWrite(LED_Amarelo, LOW);
	digitalWrite(LED_Verde, LOW);
	digitalWrite(LED_Vermelho, LOW);
	digitalWrite(LED_Azul, LOW);
	delay(100);
	digitalWrite(LED_Amarelo, HIGH);
	digitalWrite(LED_Verde, HIGH);
	digitalWrite(LED_Vermelho, HIGH);
	digitalWrite(LED_Azul, HIGH);
	delay(100);
	digitalWrite(LED_Amarelo, LOW);
	digitalWrite(LED_Verde, LOW);
	digitalWrite(LED_Vermelho, LOW);
	digitalWrite(LED_Azul, LOW);
	delay(100);
	digitalWrite(LED_Amarelo, HIGH);
	digitalWrite(LED_Verde, HIGH);
	digitalWrite(LED_Vermelho, HIGH);
	digitalWrite(LED_Azul, HIGH);
	delay(100);
	digitalWrite(LED_Amarelo, LOW);
	digitalWrite(LED_Verde, LOW);
	digitalWrite(LED_Vermelho, LOW);
	digitalWrite(LED_Azul, LOW);
	delay(100);
	noTone(Buzzer);
	delay(1500);
	loop();
}

void inicioJogo(){
	digitalWrite(LED_Amarelo, HIGH);
	delay(150);
	digitalWrite(LED_Amarelo, LOW);

	digitalWrite(LED_Verde, HIGH);
	delay(150);
	digitalWrite(LED_Verde, LOW);

	digitalWrite(LED_Vermelho, HIGH);
	delay(150);
	digitalWrite(LED_Vermelho, LOW);

	digitalWrite(LED_Azul, HIGH);
	delay(150);
	digitalWrite(LED_Azul, LOW);

	digitalWrite(LED_Vermelho, HIGH);
	delay(150);
	digitalWrite(LED_Vermelho, LOW);
	
	digitalWrite(LED_Verde, HIGH);
	delay(150);
	digitalWrite(LED_Verde, LOW);

	digitalWrite(LED_Amarelo, HIGH);
	delay(150);
	digitalWrite(LED_Amarelo, LOW);

	digitalWrite(LED_Verde, HIGH);
	delay(150);
	digitalWrite(LED_Verde, LOW);

	digitalWrite(LED_Vermelho, HIGH);
	delay(150);
	digitalWrite(LED_Vermelho, LOW);

	digitalWrite(LED_Azul, HIGH);
	delay(150);
	digitalWrite(LED_Azul, LOW);

	digitalWrite(LED_Vermelho, HIGH);
	delay(150);
	digitalWrite(LED_Vermelho, LOW);
	
	digitalWrite(LED_Verde, HIGH);
	delay(150);
	digitalWrite(LED_Verde, LOW);

	digitalWrite(LED_Amarelo, HIGH);
	delay(150);
	digitalWrite(LED_Amarelo, LOW);

	digitalWrite(LED_Amarelo, HIGH);
	digitalWrite(LED_Verde, HIGH);
	digitalWrite(LED_Vermelho, HIGH);
	digitalWrite(LED_Azul, HIGH);
	delay(100);
	digitalWrite(LED_Amarelo, LOW);
	digitalWrite(LED_Verde, LOW);
	digitalWrite(LED_Vermelho, LOW);
	digitalWrite(LED_Azul, LOW);
	delay(100);

	digitalWrite(LED_Amarelo, HIGH);
	digitalWrite(LED_Verde, HIGH);
	digitalWrite(LED_Vermelho, HIGH);
	digitalWrite(LED_Azul, HIGH);
	delay(100);
	digitalWrite(LED_Amarelo, LOW);
	digitalWrite(LED_Verde, LOW);
	digitalWrite(LED_Vermelho, LOW);
	digitalWrite(LED_Azul, LOW);
	delay(100);

	digitalWrite(LED_Amarelo, HIGH);
	digitalWrite(LED_Verde, HIGH);
	digitalWrite(LED_Vermelho, HIGH);
	digitalWrite(LED_Azul, HIGH);
	delay(100);
	digitalWrite(LED_Amarelo, LOW);
	digitalWrite(LED_Verde, LOW);
	digitalWrite(LED_Vermelho, LOW);
	digitalWrite(LED_Azul, LOW);
	delay(1500);
}
