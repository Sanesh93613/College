    if (Serialpr.available()>0) { 
      i=0;
  while (Serialpr.available()){
  digitalWrite(Ledpin,HIGH); // Пришло! Считываем и анализируем
  bb=Serialpr.read();
//обязательная задержка, иначе вылетаем из while:  
  delay(2);
//  Serial.println(bb); //для отладки
//  Serial.print(' '); //для отладки
  {arr[i]=bb; i++;}
  } //конец while
