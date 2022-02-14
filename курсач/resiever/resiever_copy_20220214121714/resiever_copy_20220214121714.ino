void setup(){
  Serial.begin(9600); // Устанавливаем частоту работы Ардуино
}
void loop(){  // запускаем постоянную работу Ардуино
  while (Serialpr.available()){
   // Пришло! Считываем и анализируем
  bb=Serialpr.read();
  
  delay(2);
  Serial.println(bb); //для отладки
  Serial.print(' '); //для отладки
 
  } //конец while
}