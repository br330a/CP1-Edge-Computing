# CP1-Edge-Computing
# Monitoramento de Luminosidade para Vinheria (Arduino)

## Descrição
Projeto para monitorar a luminosidade em ambientes de envelhecimento de vinhos. Utiliza um sensor LDR para medir a luz ambiente, exibindo o valor em um display LCD e sinalizando o estado com LEDs e buzzer.

## Componentes
- Arduino Uno  
- LDR  
- Resistor 10kΩ (divisor de tensão)  
- 3 LEDs (verde, amarelo, vermelho)  
- 3 resistores 220Ω  
- Buzzer ativo  
- LCD 16x2 (sem I2C)  
- Potenciômetro 10kΩ  
- Protoboard e jumpers  

## Funcionamento
O sistema lê o valor do LDR, converte para uma escala de 0% a 100% e classifica o ambiente em três estados:

- 0% a 30%: Pouca luz → LED verde aceso e buzzer desligado  
- 31% a 60%: Luz moderada → LED amarelo aceso e buzzer intermitente (3s ligado / 3s desligado)  
- 61% a 100%: Muita luz → LED vermelho aceso e buzzer ligado continuamente  

## Exibição no LCD
Linha 1: percentual de luminosidade  
Linha 2: status do ambiente  

Exemplo:
Luz: 45%  
Luz moderada  

## Ligações principais
LDR (divisor de tensão):  
- LDR no 5V  
- Resistor 10kΩ no GND  
- Meio ligado ao A0  

LEDs:  
- Verde no pino 8  
- Amarelo no pino 9  
- Vermelho no pino 10  

Buzzer:  
- Pino 7  

LCD (modo 4 bits):  
- RS 12, E 11  
- D4 5, D5 4, D6 3, D7 2  

## Possíveis melhorias
- Calibração do LDR  
- Suavização das leituras  
- Integração com IoT  
- Registro de dados  
