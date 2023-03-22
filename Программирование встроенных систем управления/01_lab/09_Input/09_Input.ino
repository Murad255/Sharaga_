
void setup() {
  Serial.begin(115200);
  Serial.println(F("Input string"));
}
void loop() {
  if (Serial.available()) {
      Serial.println(Serial.read(), HEX);
  }
  
}


/*
// Ввод целого числа без проверки
char buffer[16];
void setup() {
  Serial.begin(115200);
  Serial.println(F("Test input integer")); 
}

void loop() {
  int index; 
  while (Serial.available()) {
    index = Serial.readBytesUntil('\n', buffer, 15);                    // чтение до 15 символов
    buffer[index] = '\0';                                               // конец строки
 
    Serial.print(F("Input string > ")); Serial.println(buffer);         // вывод полученной строки
    int n = atoi(buffer);                                               // конвертация в челое число
    Serial.print(F("Convert to integer > ")); Serial.println(n);        // вывод челого числа
    buffer[0] = '\0';                                                   // очистка буфера
  }
}
*/

/*
// Ввод строки без проверки
String str;
void setup() {
    Serial.begin(115200);
    delay(500);
    Serial.println("Enter the string . . .");
}
void loop() {
    if(Serial.available()){
        str = Serial.readStringUntil('\n');
 
        Serial.println("You entered string > " + str);
    }
}
*/

/*
// Выполнение команд
// Для правильной работы надо настроить терминал "нет конца строки" или раскоментировать две строки command.replace
String command;
void setup() {
	pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(115200);
    help();
    Serial.print(millis()); Serial.print(F(" : Enter command > "));
}
 
void loop() {
    if(Serial.available()){
       command = Serial.readStringUntil('\n');
//       command.replace("\n","");  // Убрать служебные символы
//       command.replace("\r","");
         
        if(command.equals("init")){
        Serial.println(F("INIT not implemented"));	
    //        initialize();
        }
        else if(command.equals("send")){
        	Serial.println(F("SEND millis()"));
            send_message();
        }
        else if(command.equals("data")){
        	  Serial.println(F("DATA not implemented"));	
  //          get_data();
        }
        else if(command.equals("reboot")){
        	Serial.println(F("Reset arduino UNO"));
            reboot();
        }
        else if(command.equals("help")){
        	Serial.print(F("HELP"));
            help();
        }
        else if(command.equals("led_on")){
             digitalWrite(LED_BUILTIN, HIGH);
             Serial.println(F("Led ON"));
        }
        else if(command.equals("led_off")){
             digitalWrite(LED_BUILTIN, LOW);
             Serial.println(F("Led OFF"));
        }                
        else{
            Serial.println(F("Invalid command"));
        }
     Serial.print(millis()); Serial.print(F(" : Enter command > "));   
    }
}

void help(void)
{
    Serial.println(F("\nThe following commands are described:"));
    Serial.println(F(" init - not implemented"));
    Serial.println(F(" send - send millis()"));
    Serial.println(F(" data - not implemented"));
    Serial.println(F(" reboot - not implemented"));
    Serial.println(F(" help - show command list"));
    Serial.println(F(" led_off - led (pin d13) off"));
    Serial.println(F(" led_on - led (pin d13) on"));	
}

void reboot(void)
{
  asm volatile ("  jmp 0");  	
}

void  send_message(void)
{
	Serial.print(F("Time (msec) "));  Serial.println(millis()); 
}	

*/
