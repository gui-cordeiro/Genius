/*
 * -> Código-Fonte do Genius
 * -> Desenvolvido por: Guilherme Cordeiro
 * -> Ano: 2020, 2024
 * 
 * -> [ATENÇÃO] O projeto está configurado para rodar em quaisquer micro-
 * 	controladores que possuam o chip ATmega328P, como o Arduino UNO e
 * 	Nano. Caso opte por utilizar um microcontrolador que tenha um chip
 * 	diferente, altere a configuração de placa em "platformio.ini".
 */

#include <Arduino.h>

// Declaração dos pinos digitais para os LED's, pushbuttons e buzzer (configurado para o Arduino UNO):
const int LED_Amarelo = 13;
const int LED_Verde = 12;
const int LED_Vermelho = 11;
const int LED_Azul = 10;
const int btn_Amarelo = 5;
const int btn_Verde = 4;
const int btn_Vermelho = 3;
const int btn_Azul = 2;
const int Buzzer = 9;

// Definição das frequências sonoras relativas a cada cor
const int Nota1 = 294;
const int Nota2 = 392;
const int Nota3 = 440;
const int Nota4 = 880;

// Vetor que armazena a sequência de cores do jogo
int sequencia[100] = {};

// Variáveis de controle
int btnPressionado = -1;
int controle = 0;
int cont = 0;

// Declaração da função auxiliar
void acenderLED(int LED, int freq, int delayLED);

void setup() {
   Serial.begin(9600);
   
   // Setando os pinos como "Entrada(Pull-Up)" ou "Saída"
   pinMode(LED_Amarelo, OUTPUT);
   pinMode(LED_Verde, OUTPUT);
   pinMode(LED_Vermelho, OUTPUT);
   pinMode(LED_Azul, OUTPUT);
   pinMode(btn_Amarelo, INPUT_PULLUP);
   pinMode(btn_Verde, INPUT_PULLUP);
   pinMode(btn_Vermelho, INPUT_PULLUP);
   pinMode(btn_Azul, INPUT_PULLUP);
   pinMode(Buzzer, OUTPUT);

   // Mensagem de boas-vindas
   Serial.println("\n\n+--------------------------+");
   Serial.println("| Genius - Jogo da Memória |");
   Serial.println("+--------------------------+");
   Serial.println("| Sua pontuação final será |");
   Serial.println("| exibida assim que você   |");
   Serial.println("| errar uma cor!           |");
   Serial.println("+--------------------------+\n\n");

   // Gerando uma seed para criar uma sequência aleatória de cores
   randomSeed(analogRead(A0));
   
   // Rotina de introdução ao jogo
   for (int cont = 0; cont < 2; cont ++) {
      acenderLED(LED_Amarelo, 0, 150);
      acenderLED(LED_Verde, 0, 150);
      acenderLED(LED_Vermelho, 0, 150);
      acenderLED(LED_Azul, 0, 150);
      acenderLED(LED_Vermelho, 0, 150);
      acenderLED(LED_Verde, 0, 150);
   }
   acenderLED(LED_Amarelo, 0, 150);
   for (int cont = 0; cont <= 3; cont ++) {
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
   }
   delay(1400);
}

void loop() {
   // O jogo atualmente armazena uma sequência de 100 cores. Isso será alterado futuramente para que a sequência seja indefinida.
   for(controle = 0; controle < 100; controle ++) {

      // Mensagem de inicio de jogo
      if (controle == 0) Serial.println("-> COMECE O JOGO!");

      // Escolhe qual LED será aceso e armazena no vetor
      sequencia[controle] = random(4);

      // Loop que percorrerá por todo o vetor de sequência e acenderá as respectivas cores
      for (int numero = 0; numero <= controle; numero ++) {
         if (sequencia[numero] == 0) acenderLED(LED_Amarelo, Nota1, 500);
         else if (sequencia[numero] == 1) acenderLED(LED_Verde, Nota2, 500);
         else if (sequencia[numero] == 2) acenderLED(LED_Vermelho, Nota3, 500);
         else if (sequencia[numero] == 3) acenderLED(LED_Azul, Nota4, 500);
         delay(100);
      }

      // Loop que aguardará a ação do jogador. Ao pressionar um botão, será verificado se tal botão corresponde à cor correta.
      for (int numero = 0; numero <= controle; numero ++) {
         btnPressionado = -1;
         while (btnPressionado == -1) {
            if (digitalRead(btn_Amarelo) == 0) {
               btnPressionado = 0;
               acenderLED(LED_Amarelo, Nota1, 300);
            } else if (digitalRead(btn_Verde) == 0) {
               btnPressionado = 1;
               acenderLED(LED_Verde, Nota2, 300);
            } else if (digitalRead(btn_Vermelho) == 0) {
               btnPressionado = 2;
               acenderLED(LED_Vermelho, Nota3, 300);
            } else if (digitalRead(btn_Azul) == 0) {
               btnPressionado = 3;
               acenderLED(LED_Azul, Nota4, 300);
            }
         }
         delay(10);

         // Se "verdadeiro": Botão errado, fim de jogo! Se falso: Botão correto, o jogo continua!
         if (btnPressionado != sequencia[numero]) {

            // Printando a pontuação final e a resetando em seguida
            Serial.print("-> FIM DE JOGO! Pontuação final: ");
            Serial.print(controle);
            Serial.println("\n\n");
            controle = -1;

            // Rotina de encerramento do jogo
            delay(50);
            acenderLED(LED_Amarelo, Nota4, 180);
            acenderLED(LED_Verde, Nota3, 180);
            acenderLED(LED_Vermelho, Nota2, 180);
            acenderLED(LED_Azul, Nota1, 180);
            tone(Buzzer, Nota1);
            for (int cont = 0; cont < 4; cont ++) {
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
            }
            noTone(Buzzer);

            // Limpando vetor para iniciar um novo jogo
            for (int limpar = 0; limpar < 100; limpar ++) {
               sequencia[limpar] = -1;
            }

            delay(1000);
            break;
         }
      }
      
      // Pequeno delay para iniciar um novo loop e prosseguir com uma nova cor
      delay(1000);
   }
}

// A) Função para acender um determinado LED e acionar o buzzer numa frequência determinada, por um breve período de tempo (em ms)
void acenderLED(int LED, int freq, int delayLED) {
   digitalWrite(LED, HIGH);
   if (freq != 0) tone(Buzzer, freq);
   delay(delayLED);
   digitalWrite(LED, LOW);
   noTone(Buzzer);
}