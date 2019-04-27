
/*********
  Nirun Leeyagart
  https://www.facebook.com/illianoaoi
*********/


#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define DHTPIN D3    // what digital pin we're connected to
#define DHTTYPE DHT11   // DHT 11

LiquidCrystal_I2C lcd(0x27, 16, 2); //ถ้าจอไม่แสดงผล ให้ลองเปลี่ยน 0x3F เป็น 0x27

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  lcd.begin();
  lcd.backlight(); // เปิดไฟ backlight

  Serial.begin(115200);
  Serial.println("DHTxx test!");

  dht.begin();

  lcd.setCursor(0, 0); 
  lcd.print("The System is");
  lcd.setCursor(0, 1); //
  lcd.print("Starting.....");
}

void loop() {
  // หน่วงเวลา 2 วินาทีให้เซนเซอร์ทำงาน
  delay(5000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  // เช็คถ้าอ่านค่าไม่สำเร็จให้เริ่มอ่านใหม่
  if (isnan(h) || isnan(t) || isnan(f)) {
    lcd.clear();
    lcd.setCursor(0, 0); 
    lcd.print("Error!! Sensor");
    return;
  }
  lcd.clear();
  lcd.setCursor(0, 0); 
  lcd.print("Humidity : ");
  lcd.setCursor(11, 0); 
  lcd.print(h);
  lcd.setCursor(0, 1); 
  lcd.print("Temp : ");
  lcd.setCursor(7, 1);
  lcd.print(t);
  lcd.setCursor(11, 1);
  lcd.print(" C");
  

}
