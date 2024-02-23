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
const int LED1 = 13;
const int LED2 = 12;
const int LED3 = 11;
const int LED4 = 10;
const int btn1 = 5;
const int btn2 = 4;
const int btn3 = 3;
const int btn4 = 2;
const int buzzer = 9;

// Definição das frequências sonoras relativas a cada cor
const int freq1 = 294;
const int freq2 = 392;
const int freq3 = 440;
const int freq4 = 880;

/* Vetor que armazena a sequência de 100 cores do jogo.
 *
 * A ideia de criar um vetor dinâmico (e consequentemente criar uma sequência de cores indefinida)
 * foi descartada por questões de limitação de memória dos sistemas embarcados, pois poderiam causar 
 * problemas inesperados na execução do programa.
 */
int sequencia[100] = {};

// Variáveis de controle
int btnPressionado = -1;
int controle = 0;
int cont = 0;

// Declaração das funções auxiliares
void acenderLED(int LED, int freq, int delayLED);
void zerarVetor();

void setup() {
   Serial.begin(9600);
   
   // Define o modo dos pinos
   pinMode(LED1, OUTPUT);
   pinMode(LED2, OUTPUT);
   pinMode(LED3, OUTPUT);
   pinMode(LED4, OUTPUT);
   pinMode(btn1, INPUT_PULLUP);
   pinMode(btn2, INPUT_PULLUP);
   pinMode(btn3, INPUT_PULLUP);
   pinMode(btn4, INPUT_PULLUP);
   pinMode(buzzer, OUTPUT);

   // Mensagem de boas-vindas
   Serial.println("\n\n+--------------------------+");
   Serial.println("| Genius - Jogo da Memória |");
   Serial.println("+--------------------------+");
   Serial.println("| Sua pontuação final será |");
   Serial.println("| exibida assim que você   |");
   Serial.println("| errar uma cor!           |");
   Serial.println("+--------------------------+\n\n");

   // Gera uma seed para criar uma sequência aleatória de cores
   randomSeed(analogRead(A0));
   
   // Rotina de introdução ao jogo
   for (int cont = 0; cont < 2; cont ++) {
      acenderLED(LED1, 0, 150);
      acenderLED(LED2, 0, 150);
      acenderLED(LED3, 0, 150);
      acenderLED(LED4, 0, 150);
      acenderLED(LED3, 0, 150);
      acenderLED(LED2, 0, 150);
   }
   acenderLED(LED1, 0, 150);
   for (int cont = 0; cont <= 3; cont ++) {
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
      delay(100);
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      delay(100);
   }
   delay(1400);
}

void loop() {
   // O jogo armazena uma sequência de 100 cores (mais explicações na linha 31)
   for(controle = 0; controle < 100; controle ++) {

      // Mensagem de inicio de jogo
      if (controle == 0) Serial.println("-> COMECE O JOGO!");

      // Escolhe qual LED será aceso e armazena no vetor
      sequencia[controle] = random(4);

      // Loop que percorre por todo o vetor de sequência e acenderá as respectivas cores
      for (int numero = 0; numero <= controle; numero ++) {
         if (sequencia[numero] == 0) acenderLED(LED1, freq1, 500);
         else if (sequencia[numero] == 1) acenderLED(LED2, freq2, 500);
         else if (sequencia[numero] == 2) acenderLED(LED3, freq3, 500);
         else if (sequencia[numero] == 3) acenderLED(LED4, freq4, 500);
         delay(100);
      }

      // Loop que aguarda a ação do jogador. Ao pressionar um botão, será verificado se tal botão corresponde à cor correta.
      for (int numero = 0; numero <= controle; numero ++) {
         btnPressionado = -1;
         while (btnPressionado == -1) {
            if (digitalRead(btn1) == 0) {
               btnPressionado = 0;
               acenderLED(LED1, freq1, 300);
            } else if (digitalRead(btn2) == 0) {
               btnPressionado = 1;
               acenderLED(LED2, freq2, 300);
            } else if (digitalRead(btn3) == 0) {
               btnPressionado = 2;
               acenderLED(LED3, freq3, 300);
            } else if (digitalRead(btn4) == 0) {
               btnPressionado = 3;
               acenderLED(LED4, freq4, 300);
            }
         }
         delay(10);

         // Se "verdadeiro": Botão errado, fim de jogo! Se falso: Botão correto, o jogo continua!
         if (btnPressionado != sequencia[numero]) {

            // Printa a pontuação final e a reseta em seguida
            Serial.print("-> FIM DE JOGO! Pontuação final: ");
            Serial.print(controle);
            Serial.println("\n\n");
            controle = -1;

            // Rotina de encerramento do jogo
            delay(50);
            acenderLED(LED1, freq4, 180);
            acenderLED(LED2, freq3, 180);
            acenderLED(LED3, freq2, 180);
            acenderLED(LED4, freq1, 180);
            tone(buzzer, freq1);
            for (int cont = 0; cont < 4; cont ++) {
               digitalWrite(LED1, HIGH);
               digitalWrite(LED2, HIGH);
               digitalWrite(LED3, HIGH);
               digitalWrite(LED4, HIGH);
               delay(100);
               digitalWrite(LED1, LOW);
               digitalWrite(LED2, LOW);
               digitalWrite(LED3, LOW);
               digitalWrite(LED4, LOW);
               delay(100);
            }
            noTone(buzzer);

            // Limpa o vetor para iniciar um novo jogo
            zerarVetor();

            delay(1000);
            break;
         }
      }
      
      // Pequeno delay para iniciar um novo loop e prosseguir com uma nova cor
      delay(1000);
   }
   Serial.println("\n\nVocê chegou ao fim do jogo. O sketch está limitado a armazenar um limite de 100 cores devido a questões de limitação de memória dos sistemas embarcados.\n");
   Serial.println("O jogo será reiniciado em instantes...\n\n");

   // Limpa o vetor para iniciar um novo jogo
   zerarVetor();
   delay(5000);
}

// A) Função para acender um determinado LED e acionar o buzzer numa frequência determinada, por um breve período de tempo (em ms)
void acenderLED(int LED, int freq, int delayLED) {
   digitalWrite(LED, HIGH);
   if (freq != 0) tone(buzzer, freq);
   delay(delayLED);
   digitalWrite(LED, LOW);
   noTone(buzzer);
}

// B) Função que limpa o vetor de sequência de cores
void zerarVetor() {
   for (int limpar = 0; limpar < 100; limpar ++) {
      sequencia[limpar] = -1;
   }
}