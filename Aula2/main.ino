    #define BUTTON_PIN 2
    #define LED_PIN 1

    boolean button = 0, led = 0;

    //configrações:
    void setup()
    {
        pinMode(BUTTON_PIN,INPUT_PULLUP);
        pinMode(LED_PIN,OUTPUT);
    }
    //lógica
    void loop()
    {
        /*if(!button){
            led = 1;
        }else{
            led = 0;
        } */
        led = !button;
        //I-O's:
        button = digitalRead(BUTTON_PIN);
        digitalWrite(LED_PIN,led);
    }


// Exercicio 2:

#define BUTTON_PIN 9  // Botão Liga
#define SIREN_PIN 8   // Sirene

// Sensores
#define IR_BARRIER 1   // Barreira Infravermelha
#define WINDOW_1 2     // Sensor Janela 1
#define WINDOW_2 3     // Sensor Janela 2
#define PRESENCE_1 4   // Sensor de Presença Sala
#define PRESENCE_2 5   // Sensor de Presença Cozinha
#define PRESENCE_3 6   // Sensor de Presença Quintal
#define PRESENCE_4 7   // Sensor de Presença Corredor

bool onButton = 0, barSensor = 0, windowSensor1 = 0; // Estado do sistema
bool roomSensor = 0, kitchenSensor = 0;

void setup() {
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(IR_BARRIER, INPUT_PULLUP);
    pinMode(WINDOW_1, INPUT_PULLUP);
    pinMode(WINDOW_2, INPUT_PULLUP);
    pinMode(PRESENCE_1, INPUT_PULLUP);
    pinMode(PRESENCE_2, INPUT_PULLUP);
    pinMode(PRESENCE_3, INPUT_PULLUP);
    pinMode(PRESENCE_4, INPUT_PULLUP);
    pinMode(SIREN_PIN, OUTPUT);
}

void loop() {
    onButton = digitalRead(BUTTON_PIN) == LOW; // Botão ligado ativa o sistema

    if (onButton) {
        // Verifica se alguma das condições de alarme foi acionada
        if (digitalRead(IR_BARRIER) == LOW || 
            (digitalRead(WINDOW_1) == LOW && digitalRead(WINDOW_2) == LOW) || 
            digitalRead(PRESENCE_1) == HIGH || 
            digitalRead(PRESENCE_2) == HIGH || 
            digitalRead(PRESENCE_3) == HIGH || 
            digitalRead(PRESENCE_4) == HIGH) {
            sirenState = true;
        } else {
            sirenState = false;
        }
    } else {
        sirenState = false; // Se o botão não estiver ligado, a sirene não dispara
    }

    digitalWrite(SIREN_PIN, sirenState);
}
