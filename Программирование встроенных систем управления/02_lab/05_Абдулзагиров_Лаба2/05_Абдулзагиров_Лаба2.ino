/*
 * МГТУ СТАНКИН
 * Программирование встроенных систем управления
 * Лабораторная работа №2
 * АДМ-21-05
 * Абдулзагиров Мурад Магомедович
 * Murad.Abdulzagirov@gmail.com
 */

//выводы кнопок
#define BUTTON_PIN 2
#define BUTTON_RPLC 3

// выводы светодиодов
#define LED_PIN 12
#define LED_R 9
#define LED_G 10
#define LED_B 11
int rgbLedNum = 0;

boolean buttonWasUp = true;                     // была ли кнопка отпущена?
boolean ledEnabled = false;                     // включен ли свет?
void rgbLedOn(boolean R, boolean G, boolean B); // установка нужного цвета

void setup()
{
    Serial.begin(9600); // инициализация COM порта
    // инициализация выводов светодиодов
    pinMode(LED_PIN, OUTPUT);
    pinMode(LED_R, OUTPUT);
    pinMode(LED_G, OUTPUT);
    pinMode(LED_B, OUTPUT);
    // инициализация входов с внутренним стягивающим резистором
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(BUTTON_RPLC, INPUT_PULLUP);

    Serial.println("\n<------ START ------->");
}

void loop()
{
    // Для определения клика мы сначала понимаем, отпущена ли кнопка прямо сейчас...
    boolean buttonIsUp = !digitalRead(BUTTON_PIN);
    // ...если «кнопка была отпущена и (&&) не отпущена сейчас»...
    if (buttonWasUp && buttonIsUp)
    {
        delay(10);
        // ...и считываем сигнал снова
        buttonIsUp = !digitalRead(BUTTON_PIN);
        if (buttonIsUp)
        { // если она всё ещё нажата...
            // это короткий клик!
            // флаг состояния светодиода (зажечь)
            bool state = true;

            delay(500);
            // ...и считываем сигнал снова
            buttonIsUp = !digitalRead(BUTTON_PIN);
            if (buttonIsUp)    // это длительный клик!
                state = false; //отключим всетодиод

            // установка полученного состояния
            digitalWrite(LED_PIN, state);
            Serial.print("Red led state: ");
            Serial.println(state);
        }
    }

    // запоминаем последнее состояние кнопки для новой итерации
    buttonWasUp = buttonIsUp;
    delay(10); //для работы функции yield() без нажатий
}

void yield()
{
    static long time;
    static long pastTime;
    static boolean pastIsUp = false;    // флаг нажатия в процлом цикле
    static boolean ledIsChange = false; //флаг

    time = millis(); // текущее время
    boolean buttonIsUp = !digitalRead(BUTTON_RPLC);
    if (buttonIsUp && pastIsUp == false) //если кнопка нажать и она была отпущена ранее
    {
        pastIsUp = true;
        pastTime = time;    // сохраняем текущее время
        ledIsChange = true; //разрешаем переключить свет
    }

    // если процло 30 миллисекунд и кнопка была нажата и всё ещё нажата и разрешено переключить свет
    if (time - pastTime >= 30 && pastIsUp && buttonIsUp && ledIsChange)
    {
        // устанавливаем вледующий цвет (или выключение)
        switch (rgbLedNum)
        {
        case 0:
            rgbLedOn(1, 0, 0);
            Serial.println("RGB led state: red");
            rgbLedNum++;
            break;
        case 1:
            rgbLedOn(0, 1, 0);
            Serial.println("RGB led state: green");
            rgbLedNum++;
            break;
        case 2:
            rgbLedOn(0, 0, 1);
            Serial.println("RGB led state: blue");
            rgbLedNum++;
            break;
        case 3:
            rgbLedOn(0, 0, 0);
            Serial.println("RGB led state: off");
            rgbLedNum = 0;
            break;
        default:
            break;
        }
        ledIsChange = false; // запрещаем переключение цвета
    }
    if (!buttonIsUp && pastIsUp == true) //если кнопка сейчас разжата, но она была нажата
        pastIsUp = false;                //устанавливаем статус прошлого нажатия в false
}

/// установка нужного цвета
void rgbLedOn(boolean R, boolean G, boolean B)
{
    digitalWrite(LED_R, R);
    digitalWrite(LED_G, G);
    digitalWrite(LED_B, B);
}
