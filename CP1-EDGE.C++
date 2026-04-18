#include <LiquidCrystal.h>

// Inicializa o LCD no modo 4 bits (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Definição de pinos
const int ldrPin = A0;
const int ledVerde = 8;
const int ledAmarelo = 9;
const int ledVermelho = 10;
const int buzzer = 7;

// Variáveis para controle do buzzer intermitente
unsigned long tempoAnterior = 0;
bool estadoBuzzer = false;

void setup() {
  lcd.begin(16, 2); // Inicializa LCD 16x2

  // Configura pinos como saída
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);

  // Mensagem inicial
  lcd.setCursor(0,0);
  lcd.print("Vinheria");
  lcd.setCursor(0,1);
  lcd.print("Iniciando...");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Leitura do LDR (0 a 1023)
  int leitura = analogRead(ldrPin);

  // Converte para porcentagem (0 a 100%)
  int luminosidade = map(leitura, 0, 1023, 0, 100);

  // Garante que apenas um LED fique ativo por vez
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, LOW);

  String status; // Texto exibido no LCD

  // ===== ESTADO: POUCA LUZ =====
  if (luminosidade <= 30) {
    digitalWrite(ledVerde, HIGH);   // Indicação segura
    digitalWrite(buzzer, LOW);      // Buzzer desligado
    status = "Pouca luz";
  }

  // ===== ESTADO: ALERTA =====
  else if (luminosidade <= 60) {
    digitalWrite(ledAmarelo, HIGH);
    status = "Luz moderada";

    // Controle de buzzer intermitente (3s ON / 3s OFF)
    unsigned long agora = millis();
    if (agora - tempoAnterior >= 3000) {
      tempoAnterior = agora;
      estadoBuzzer = !estadoBuzzer; // alterna estado
      digitalWrite(buzzer, estadoBuzzer);
    }
  }

  // ===== ESTADO: CRÍTICO =====
  else {
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(buzzer, HIGH); // buzzer contínuo
    status = "Muita luz";
  }

  // ===== ATUALIZAÇÃO DO LCD =====
  lcd.setCursor(0,0);
  lcd.print("Luz: ");
  lcd.print(luminosidade);
  lcd.print("%   "); // limpa resíduos de caracteres

  lcd.setCursor(0,1);
  lcd.print(status);
  lcd.print("        "); // limpa linha

  // Pequeno delay para estabilidade da leitura
  delay(200);
}