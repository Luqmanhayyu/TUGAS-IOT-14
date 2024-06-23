==========================================
//PENJELASAN (1)

#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int sensor_Pin = A0;
int nilai_ADC_sensor = 0;

LiquidCrystal.h: Library to control the LCD.
lcd(): Initializes the LCD with the specified digital pins.
sensor_Pin: Defines the analog pin where the temperature sensor is connected.
nilai_ADC_sensor: Variable to store the sensor's ADC value.

==========================================
//PENJELASAN (2)

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("CEK SUHU RUANGAN");
  lcd.setCursor(0, 1);
  lcd.print("TUNGGU 1 DETIK");
  delay(1000);
  lcd.clear();
}

lcd.begin(16, 2): Initializes the LCD with 16 columns and 2 rows.
Displays the initial message "CEK SUHU RUANGAN" and "TUNGGU 1 DETIK" for 1 second.
lcd.clear(): Clears the display.

==========================================
//PENJELASAN (3)

void loop() {
  nilai_ADC_sensor = analogRead(sensor_Pin);
  double Celcius = ((5.0 / 1024.0) * analogRead(sensor_Pin) * 100);
  lcd.setCursor(0, 0);
  lcd.print("SUHU RUANGAN:");
  lcd.setCursor(0, 1);
  lcd.print(Celcius);
  lcd.print((char)223);  // Degree symbol
  lcd.print("C");
}

analogRead(sensor_Pin): Reads the analog voltage from the sensor.
Celcius: Converts the ADC value to a temperature in Celsius. The conversion formula assumes the sensor provides 10mV per degree Celsius.
Updates the LCD to display "SUHU RUANGAN:" on the first line and the temperature on the second line with a degree symbol and "C".

==========================================
//CARA KERJA

Initialization: The LCD is initialized, and an initial message is displayed for 1 second.
Temperature Reading: In the loop() function, the Arduino continuously reads the analog value from the temperature sensor.
Conversion: The read analog value (ADC count) is converted to Celsius using the formula ((5.0 / 1024.0) * analogRead(sensor_Pin) * 100).
Display Update: The LCD is updated with the text "SUHU RUANGAN:" and the calculated temperature in Celsius.
This setup provides a continuous real-time display of the room temperature on the LCD.
