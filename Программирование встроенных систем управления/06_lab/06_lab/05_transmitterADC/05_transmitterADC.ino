// Пример передачи данных по радиоканалу, формирование пакета передачи
// Передатчик

#include <RH_ASK.h>

#define D13_LED     13    // светодиод отпраки пакета
#define D12_LED     12    // светодиод нажатие кнопки
#define D2_KEY      2     // кнопка
#define ID_TRANS    0x1   // Идентификатор передатчика (Адрес)

RH_ASK driver(2000, 8, 7, 0);


struct packet // Пакет для передачи
{
    uint8_t id=ID_TRANS;  // Идентификатор передатчика (адрес передатчика)
    uint8_t key;          // Кнопка
    int num=0;            // Номер ОТПРАВЛЯЕМОГО пакета, при старте 0
    uint16_t adc;         // Значение АЦП
    char text[10];        // Текстовое сообщение
} myPocket;

void setup()
{
  Serial.begin(115200);	  
  Serial.println("\n\n------------ START TRAMSMITTER --------------");
  if (!driver.init())   Serial.println("init failed");
  pinMode(D13_LED, OUTPUT);
  pinMode(D12_LED, OUTPUT);
  pinMode(D2_KEY, INPUT);
  Serial.print("RH_ASK_MAX_MESSAGE_LEN:");Serial.println(RH_ASK_MAX_MESSAGE_LEN);
  Serial.print("Sizeof myPocket:");Serial.println(sizeof(myPocket));
  if(sizeof(myPocket)<RH_ASK_MAX_MESSAGE_LEN) Serial.println("Len pocket OK"); else Serial.println("Len pocket BIG!");
}

void loop()
{
    myPocket.num++;
    strcpy(myPocket.text,"hello");
    myPocket.key=digitalRead(D2_KEY);
    myPocket.adc = analogRead(A0);
    digitalWrite(D12_LED, myPocket.key); 
    digitalWrite(D13_LED, HIGH);     // В начале передачи включить светодиод
    driver.send((uint8_t * )&myPocket, sizeof(myPocket));
    driver.waitPacketSent();
    digitalWrite(D13_LED, LOW);     // В конце передачи выключить светодиод 
    delay(1000);
    
}


/*
// Эмуляция двух передатчиков с разными ID
#include <RH_ASK.h>

#define D13_LED     13    // светодиод отпраки пакета
#define D12_LED     12    // светодиод нажатие кнопки
#define D2_KEY      2     // кнопка
#define ID_TRANS    0x1   // Идентификатор передатчика (Адрес)
#define TIME        200   // Период отсылки сообщений

RH_ASK driver(2000, 8, 7, 0);


struct packet // Пакет для передачи
{
    uint8_t id=ID_TRANS;  // Идентификатор передатчика (адрес передатчика)
    uint8_t key;          // Кнопка
    int num=0;            // Номер ОТПРАВЛЯЕМОГО пакета, при старте 0
    uint16_t adc;         // Значение АЦП
    char text[10];        // Текстовое сообщение
} myPocket;

void setup()
{
  Serial.begin(115200);	  
  Serial.println("\n\n------------ START TRAMSMITTER --------------");
  if (!driver.init())   Serial.println("init failed");
  pinMode(D13_LED, OUTPUT);
  pinMode(D12_LED, OUTPUT);
  pinMode(D2_KEY, INPUT);
  Serial.print("RH_ASK_MAX_MESSAGE_LEN:");Serial.println(RH_ASK_MAX_MESSAGE_LEN);
  Serial.print("Sizeof myPocket:");Serial.println(sizeof(myPocket));
  if(sizeof(myPocket)<RH_ASK_MAX_MESSAGE_LEN) Serial.println("Len pocket OK"); else Serial.println("Len pocket BIG!");
}

void loop()
{
    myPocket.num++;
    strcpy(myPocket.text,"hello");
    myPocket.key=digitalRead(D2_KEY);
    myPocket.adc = analogRead(A0);
    digitalWrite(D12_LED, myPocket.key); 
    send_packet(ID_TRANS,"id=1");    // Первый ID
    myPocket.num++;
    send_packet(ID_TRANS+1,"id=2");  // Второй ID
}

// Отправка пакета с задынным ID и текстовым сообщением
void send_packet(uint8_t id, char *mess){
	myPocket.id=id; 
	strcpy(myPocket.text,mess);
	digitalWrite(D13_LED, HIGH);     // В начале передачи включить светодиод
    driver.send((uint8_t * )&myPocket, sizeof(myPocket));
    driver.waitPacketSent();
    digitalWrite(D13_LED, LOW);     // В конце передачи выключить светодиод 
    delay(TIME);
}
*/
