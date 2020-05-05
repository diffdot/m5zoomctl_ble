#include <M5Stack.h>
#include <BleKeyboard.h>
#include "main.h"

BleKeyboard bleKeyboard("M5 Zoom Controller");
bool blestate = false;

void setup() {
  M5.begin();
  M5.Power.begin();

  bleKeyboard.begin();

  M5.Lcd.clearDisplay();

  M5.Lcd.drawBitmap(0, 0, 320, 240, BUTTONIMG);

}

void loop() {
  M5.update();
  if (bleKeyboard.isConnected()) {
    if (!blestate) {
      blestate = true;
    }

    if (M5.BtnA.wasPressed()) {
      bleKeyboard.press(KEY_LEFT_ALT);
      bleKeyboard.press('a');
      delay(100);
      bleKeyboard.releaseAll();
    } else if (M5.BtnB.wasPressed()) {
      bleKeyboard.press(KEY_F6);
      delay(100);
      bleKeyboard.releaseAll();
    } else if (M5.BtnC.wasPressed()) {
      bleKeyboard.press(KEY_LEFT_ALT);
      bleKeyboard.press('v');
      delay(100);
      bleKeyboard.releaseAll();
    }
  } else {
    if (blestate) {
      blestate = false;
    }
  }
  delay(100);
}
