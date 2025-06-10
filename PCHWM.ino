#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);
int numCoresDetected = 0;

unsigned long lastDataTime = 0;
const unsigned long timeout = 5000;
bool isStandby = false;

void detectCpuCores(String cpuData) {
  if (numCoresDetected == 0) {
    numCoresDetected = 1;
    int startIdx = 0, commaIdx;
    while ((commaIdx = cpuData.indexOf(',', startIdx)) != -1) {
      numCoresDetected++;
      startIdx = commaIdx + 1;
    }
    if (numCoresDetected > 16) numCoresDetected = 16;
  }
}

void setup() {
  lcd.init();
  lcd.backlight();
  setupCustomChars();
  Serial.begin(115200);
}

void loop() {
  if (Serial.available() > 0) {
    lastDataTime = millis();
    isStandby = false;
    String input = Serial.readStringUntil('\n');
    if (input.startsWith("ROW1:")) {
      lcd.setCursor(0, 0);
      lcd.print(input.substring(5));
    } else if (input.startsWith("CPU_ROW:")) {
      updateCpuLoadGraph(input.substring(8));
    } else if (input.startsWith("ROW3:")) {
      lcd.setCursor(0, 2);
      lcd.print(input.substring(5));
    } else if (input.startsWith("ROW4:")) {
      lcd.setCursor(0, 3);
      lcd.print(input.substring(5));
    }
    lcd.backlight();
  }

  if (millis() - lastDataTime >= timeout && !isStandby) {
    isStandby = true;
    lcd.clear();
    lcd.setCursor(5, 1);
    lcd.print("");
    lcd.noBacklight();
  }
}

void updateCpuLoadGraph(String cpuData) {
  lcd.setCursor(0, 1);
  lcd.print("                    ");

  if (cpuData.startsWith("[")) {
    cpuData = cpuData.substring(1);
  }
  if (cpuData.endsWith("]")) {
    cpuData = cpuData.substring(0, cpuData.length() - 1);
  }

  int numCores = 1;
  for (int i = 0; i < cpuData.length(); i++) {
    if (cpuData.charAt(i) == ',') {
      numCores++;
    }
  }

  numCores = min(numCores, 16);

  int graphWidth = numCores;
  int padding = (20 - (graphWidth + 2)) / 2;

  lcd.setCursor(padding, 1);
  lcd.print("[");

  int startIdx = 0, commaIdx;
  for (int i = 0; i < numCores; i++) {
    commaIdx = cpuData.indexOf(',', startIdx);
    int value = (commaIdx == -1) ? cpuData.substring(startIdx).toInt() : cpuData.substring(startIdx, commaIdx).toInt();
    startIdx = (commaIdx == -1) ? cpuData.length() : commaIdx + 1;

    lcd.write(getCustomChar(value));
  }

  lcd.print("]");

  for (int i = padding + graphWidth + 2; i < 20; i++) {
    lcd.setCursor(i, 1);
    lcd.print(" ");
  }
}

byte customChars[8][8] = {
  { B00000, B00000, B00000, B00000, B00000, B00000, B00000 },  // 0%
  { B00000, B00000, B00000, B00000, B00000, B00000, B11111 },  // 14%
  { B00000, B00000, B00000, B00000, B00000, B11111, B11111 },  // 28%
  { B00000, B00000, B00000, B00000, B11111, B11111, B11111 },  // 42%
  { B00000, B00000, B00000, B11111, B11111, B11111, B11111 },  // 57%
  { B00000, B00000, B11111, B11111, B11111, B11111, B11111 },  // 71%
  { B00000, B11111, B11111, B11111, B11111, B11111, B11111 },  // 85%
  { B11111, B11111, B11111, B11111, B11111, B11111, B11111 }   // 100%
};

byte getCustomChar(int percent) {
  if (percent <= 0) return 0;
  if (percent <= 14) return 1;
  if (percent <= 28) return 2;
  if (percent <= 42) return 3;
  if (percent <= 57) return 4;
  if (percent <= 71) return 5;
  if (percent <= 85) return 6;
  return 7;
}

void setupCustomChars() {
  for (int i = 0; i < 8; i++) {
    lcd.createChar(i, customChars[i]);
  }
}

void updateRow(int row, String data) {
  lcd.setCursor(0, row);
  clearLine(row);
  lcd.print(formatRow(data));
}

void clearLine(int row) {
  lcd.setCursor(0, row);
  for (int i = 0; i < 20; i++) {
    lcd.print(" ");
  }
  lcd.setCursor(0, row);
}

void updateCenteredRow(int row, String data) {
  int totalWidth = 18;
  int padding = (20 - data.length()) / 2;
  lcd.setCursor(padding, row);
  clearLine(row);
  lcd.print(data);
}

String formatRow(String data) {
  String formatted = "";
  int len = data.length();
  if (len > 20) {
    formatted = data.substring(0, 20);
  } else {
    formatted = data;
    for (int i = len; i < 20; i++) {
      formatted += " ";
    }
  }
  return formatted;
}
