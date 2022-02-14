#define Ledpin 13
#define RX  8  // * Определяем вывод RX (TX на модуле)
#define TX  9  // * Определяем вывод TX (RX на модуле)

#include <SoftwareSerial.h> // Библиотека программного последовательного порта
#include <TinyGPS.h> //подключение необходимых для работы c GPS библиотек
TinyGPS gps;
SoftwareSerial Serialpr(RX,TX); // Программный последовательный порт HC-12
SoftwareSerial gpsSerial(8, 9); //номера пинов, к которым подключен модуль GPS (RX, TX)
/// Переменные используемые в gps
bool newdata = false;
unsigned long start;
long lat, lon;
unsigned long time, date;
/// Переменные используемые в gps

void setup() {
Serialpr.begin(9600);// установка скорости обмена с приемником
pinMode(A3,INPUT); //Подключаем металлодетектор к Ардуино  
gpsSerial.begin(9600); // установка скорости обмена с приемником                              
delay(100);
}

void loop() {
if(analogRead(A3<n)){  //если показания металлодетектора больше нужного нам числа -> отправляются данные с gps на наземную станцию
Serialpr.write(gps()); //передаем через программный порт HC-12 данные с GPS
delay(50);
}
/////


void gps(){


newdata = readgps();
if (newdata)
{

gps.get_position(&lat, &lon);
gps.get_datetime(&date, &time);
Serial.print("Lat: "); Serial.print(lat);
Serial.print(" Long: "); Serial.print(lon);//
Serial.print(" Date: "); Serial.print(date);//
Serial.print(" Time: "); Serial.println(time);//
}}


// проверка наличия данных gps

bool readgps()
{
while (gpsSerial.available())
{
int b = gpsSerial.read();
//в библиотеке TinyGPS имеется ошибка: не обрабатываются данные с \r и \n
if('\r' != b)
{
if (gps.encode(b))
 return true;
}
}
return false;
}
}