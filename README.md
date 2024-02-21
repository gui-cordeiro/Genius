

<h1 align="center">🕹️ Genius - Jogo da Memória 🧠</h1>
<img src="https://github.com/gui-cordeiro/Genius/assets/83349463/a500d03e-9269-4b86-a7f8-bfee74c54520" alt="Logo do projeto Genius"/>
<h3 align="center">🧩 O famoso jogo de memória rodando no seu Arduino (e em outros microcontroladores). 🧩<br> Quantas cores você consegue memorizar?</h3>
<br>

## 📕 Sobre o projeto
Este é um simples projeto baseado no famoso jogo de memória, que roda no Arduino ou em qualquer outro microcontrolador.

## ⁉️ Como o projeto funciona?
<p>O microcontrolador deverá ter quatro LED's, referentes as quatro cores presentes no jogo original, e mais quatro <em>pushbuttons</em> correspondentes a cada uma das cores. Para uma melhor experiência, recomenda-se o uso de um buzzer para a reprodução de sons.</p>
<p>Observe abaixo um exemplo de diagrama esquemático do projeto. Sinta-se livre para fazer as alterações que desejar: </p>
<img alt="Exemplo de diagrama esquemático do projeto" width="55%" src="https://github.com/gui-cordeiro/Genius/assets/83349463/c0f79ea6-8175-4b75-af34-75ecf96c55cd.png"/>

O jogo inicia assim que o microcontrolador é alimentado. A cada rodada, uma cor nova acenderá e será adicionada à sequência que o jogador deverá seguir à risca.

## 🛠️ Linguagens e ferramentas utilizadas no desenvolvimento do projeto
<a href="#"><img alt="Ícone transparente" width="10em" height="20em" src="https://user-images.githubusercontent.com/83349463/151667763-eed1f9e2-ff23-462e-be41-a6046ad8434a.png"/></a>
<a href="https://platformio.org/"><img alt="Ícone do PlatformIO" width="60em" src="https://github.com/gui-cordeiro/ProjetoCafe-IoT/assets/83349463/0bc1ed91-5989-49aa-8849-cb53f44925a5"/></a>
<a href="#"><img alt="Ícone transparente" width="10em" height="20em" src="https://user-images.githubusercontent.com/83349463/151667763-eed1f9e2-ff23-462e-be41-a6046ad8434a.png"/></a>
<a href="https://www.arduino.cc/reference/pt/"><img alt="Ícone do Arduino" width="60em" src="https://github.com/devicons/devicon/blob/master/icons/arduino/arduino-original.svg"/></a>

## 🤝 Como baixar o projeto?
Antes de tudo, é necessário ter o Visual Studio Code junto com a extensão **"PlatformIO"**. Caso não tenha o PlatformIO instalado, fica a recomendação deste [tutorial de instalação](https://youtu.be/OwJOfN30NuQ) disponível no canal do YouTube **MehlCor Tech**, e feito pelo meu parceiro [Arthur Mehl](https://github.com/artmehl).

Com tudo devidamente configurado, faça os passos a seguir:

1) Abra o terminal, selecione um diretório de sua preferência e clone o repositório do projeto.
````bash
git clone https://github.com/gui-cordeiro/Genius.git
````

2) Entre na pasta do repositório.
````bash
cd Genius
````
3) Abra a pasta do projeto no Visual Studio Code.
````bash
code
````
4) Por padrão, o projeto está configurado para funcionar nos Arduinos UNO, Nano e em outros que possuam o chip ATmega328P embutidos. Caso queira usar outra placa de desenvolvimento, altere o documento <code>platformio.ini</code> que está situado na raíz do repositório. Consulte a [documentação do PlatformIO](https://docs.platformio.org/en/latest/boards/index.html#boards) referente à *configuração de outras placas de desenvolvimento* para mais informações.
<img src="https://github.com/gui-cordeiro/Genius/assets/83349463/f65a3f1b-e054-48a8-b913-0b7d3c40fb32.png" alt="Print do arquivo platformio.ini"/>
