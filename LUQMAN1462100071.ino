#include <LiquidCrystal.h>
//
//Luqman Hayyu Winata - 1462100071
//PROJECT TUGAS IOT KE 14
//

// Inisialisasi library LiquidCrystal untuk mengontrol LCD
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

// Deklarasi pin sensor yang terhubung ke pin analog A0
int sensor_Pin = A0;

// Variabel untuk menyimpan nilai yang dibaca dari sensor
int nilai_ADC_sensor = 0;

void setup() {
  // Mengatur LCD dengan ukuran 16 kolom dan 2 baris
  lcd.begin(16, 2);
  
  // Menempatkan kursor pada kolom 0, baris 0
  lcd.setCursor(0, 0);
  
  // Menampilkan teks "CEK SUHU RUANGAN" pada baris pertama
  lcd.print("CEK SUHU RUANGAN");
  
  // Menempatkan kursor pada kolom 0, baris 1
  lcd.setCursor(0, 1);
  
  // Menampilkan teks "TUNGGU 1 DETIK" pada baris kedua
  lcd.print("TUNGGU 1 DETIK");
  
  // Menunggu selama 1 detik (1000 milidetik)
  delay(1000);
  
  // Membersihkan layar LCD
  lcd.clear();
}

void loop() {
  // Membaca nilai analog dari sensor dan menyimpannya di variabel nilai_ADC_sensor
  nilai_ADC_sensor = analogRead(sensor_Pin);
  
  // Menghitung nilai suhu dalam derajat Celcius
  double Celcius = ((5.0 / 1024.0) * analogRead(sensor_Pin) * 100);
  
  // Menempatkan kursor pada kolom 0, baris 0
  lcd.setCursor(0, 0);
  
  // Menampilkan teks "SUHU RUANGAN:" pada baris pertama
  lcd.print("SUHU RUANGAN:");
  
  // Menempatkan kursor pada kolom 0, baris 1
  lcd.setCursor(0, 1);
  
  // Menampilkan nilai suhu dalam derajat Celcius
  lcd.print(Celcius);
  
  // Menampilkan simbol derajat (°)
  lcd.print((char)223);  // Karakter untuk simbol derajat
  
  // Menampilkan huruf "C" untuk Celsius
  lcd.print("C");
}
