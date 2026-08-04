#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>
#include <U8g2lib.h>
#include <LiquidCrystal_I2C.h>

const char* ssid="YOUR_WIFI_NAME";
const char* password="YOUR_WIFI_PASSWORD";
const char* firebaseURL="https://YOUR_PROJECT_ID-default-rtdb.asia-southeast1.firebasedatabase.app/tds.json";

#define TDS_PIN 34

U8G2_SH1106_128X64_NONAME_F_HW_I2C oled(U8G2_R0);
LiquidCrystal_I2C lcd(0x27,16,2);

int graph[128];
unsigned long lastGraph=0;
unsigned long lastUpload=0;

int readTDS(){
  long total=0;
  for(int i=0;i<10;i++){
    total+=analogRead(TDS_PIN);
    delay(2);
  }
  float raw=total/10.0;
  float voltage=raw*(3.3/4095.0);
  float tds=(133.42*voltage*voltage*voltage-255.86*voltage*voltage+857.39*voltage)*0.5;
  if(tds<0) tds=0;
  return (int)tds;
}

String getStatus(int tds){
  if(tds<300) return "SAFE";
  if(tds<600) return "CAUTION";
  return "DANGER";
}

void connectWiFi(){
  WiFi.begin(ssid,password);
  while(WiFi.status()!=WL_CONNECTED){
    delay(500);
  }
}

void uploadFirebase(int tds){
  if(WiFi.status()!=WL_CONNECTED) return;
  HTTPClient http;
  http.begin(firebaseURL);
  http.addHeader("Content-Type","application/json");
  http.PUT(String(tds));
  http.end();
}

void setup(){
  Serial.begin(115200);
  Wire.begin(21,22);
  analogReadResolution(12);
  oled.begin();
  lcd.init();
  lcd.backlight();
  for(int i=0;i<128;i++) graph[i]=63;
  connectWiFi();
}

void loop(){
  int tds=readTDS();

  if(millis()-lastGraph>80){
    lastGraph=millis();

    for(int i=0;i<127;i++) graph[i]=graph[i+1];
    graph[127]=map(constrain(tds,0,1000),0,1000,63,18);

    oled.clearBuffer();
    char txt[20];
    sprintf(txt,"%d ppm",tds);
    oled.setFont(u8g2_font_6x12_tf);
    oled.drawStr(0,10,txt);
    String st=getStatus(tds);
    oled.drawStr(80,10,st.c_str());
    oled.drawHLine(0,14,128);
    for(int i=1;i<128;i++){
      oled.drawLine(i-1,graph[i-1],i,graph[i]);
    }
    oled.sendBuffer();

    lcd.setCursor(0,0);
    lcd.print("TDS:      ");
    lcd.setCursor(4,0);
    lcd.print(tds);

    lcd.setCursor(0,1);
    lcd.print("Status:        ");
    lcd.setCursor(8,1);
    lcd.print(st);
  }

  if(millis()-lastUpload>1000){
    lastUpload=millis();
    uploadFirebase(tds);
    Serial.println(tds);
  }
}
