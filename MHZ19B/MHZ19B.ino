#include <M5StickC.h>
#include <MHZ19.h>                                        
#include <SoftwareSerial.h> 

#define RX_PIN 26
#define TX_PIN 0
#define BAUDRATE 9600
#define DELAY 2000

MHZ19 myMHZ19;
HardwareSerial mySerial(1);

// the setup routine runs once when M5StickC starts up
void setup(){
  // Initialize the M5StickC object
  M5.begin();
  M5.Lcd.setRotation(1);
  M5.Lcd.setTextSize(3);
  
  mySerial.begin(BAUDRATE, SERIAL_8N1, RX_PIN, TX_PIN);
  myMHZ19.begin(mySerial);
  myMHZ19.autoCalibration();

  // LCD display
  M5.Lcd.print("Hello World\n");
}

// the loop routine runs over and over again forever
void loop() {
    int CO2 = myMHZ19.getCO2();
    M5.Lcd.fillScreen(TFT_BLACK);
    M5.Lcd.setCursor(10, 10);
    
    M5.Lcd.print("CO2: \n ");
    M5.Lcd.print(CO2);
    M5.Lcd.println("ppm ");
    delay(DELAY);
}
