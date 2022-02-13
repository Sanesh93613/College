#define Ledpin 13
#define RX  8  // * Определяем вывод RX (TX на модуле)
#define TX  9  // * Определяем вывод TX (RX на модуле)

#include <SoftwareSerial.h> // Библиотека программного последовательного порта
SoftwareSerial Serialpr(RX,TX); // Программный последовательный порт

word value=273; //условное 3-значное число (2-байтовое)
//передаваемые байты, "DAT"-идентификатор, ";" - разделитель (конец данных):
byte arr[6] = {'D','A','T',0,0,';'}; 

void setup() {
Serialpr.begin(9600);
pinMode(Ledpin,OUTPUT);
delay(100);
}

void loop() {
digitalWrite(Ledpin,HIGH);
//доформируем массив:
arr[3]=lowByte(value);  
arr[4]=highByte(value);  
for (byte i = 0; i < 6; i++) 
Serialpr.write(arr[i]); //передаем массив через программный порт 

delay(50);
digitalWrite(Ledpin,LOW);
delay(4000);
}
