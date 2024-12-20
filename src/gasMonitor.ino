/* 
  Sketch generated by the Arduino IoT Cloud Thing "Untitled"
  https://create.arduino.cc/cloud/things/30ac66bc-99ae-4825-88f0-479f5590b98d 

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  int cloudTimeMQ135;
  int cloudTimeMQ2;
  int gasConcentrationMQ135;
  int gasConcentrationMQ2;
  int latenciaAtuador;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"
#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;  // Cria uma instância da matriz de LEDs

int sensorPin1 = A0;  // Pino analógico conectado ao sensor MQ-2
int sensorPin2 = A1; // MQ-135

unsigned long startTimeMQ2;
unsigned long cloudReceiveTimeMQ2;
unsigned long startTimeMQ135;
unsigned long cloudReceiveTimeMQ135;

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  
  matrix.begin(); 
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  // Defined in thingProperties.h
  initProperties();
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();

  // Captura o tempo de início em microssegundos
  unsigned long tempoInicio = micros();
  
  // Your code here 
  gasConcentrationMQ2 = analogRead(sensorPin1);  // Lê o valor do sensor
  startTimeMQ2 = millis();
  gasConcentrationMQ135 = analogRead(sensorPin2);
  startTimeMQ135 = millis();
  Serial.println("");
  Serial.println(gasConcentrationMQ2);  // Exibe o valor no monitor serial para debug
  Serial.println(gasConcentrationMQ135);  // Exibe o valor no monitor serial para debug

  
  matrix.clear();  // Limpa a matriz antes de atualizar

  // Mapeia o valor do sensor para a faixa de 0 a 47 (total de LEDs na matriz)
  int numLEDsMQ2 = map(gasConcentrationMQ2, 0, 1023, 0, 47);
  int numLEDsMQ135 = map(gasConcentrationMQ135, 0, 1023, 0, 47);

  Serial.println(numLEDsMQ2);
  Serial.println(numLEDsMQ135);

  // Cria um bitmap para a matriz (8 linhas x 12 colunas)
  uint8_t bitmap[8][12] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
  };  // Array bidimensional


  // Define os LEDs acesos no bitmap
  for (int i = 0; i <= numLEDsMQ2; i++) {
    int row = i / 12;   // Calcula a linha
    int col = i % 12;   // Calcula a coluna
    bitmap[row][col] = 1;  // Acende o LED correspondente
  }

  for (int i = 0; i <= numLEDsMQ135; i++) {
    int row = i / 12 + 4;   // Calcula a linha
    int col = i % 12;   // Calcula a coluna
    bitmap[row][col] = 1;  // Acende o LED correspondente
  }

  // Renderiza o bitmap na matriz de LEDs (bitmap, linhas, colunas)
  matrix.renderBitmap(bitmap, 8, 12);  // 8 linhas e 12 colunas

  // Captura o tempo de início em microssegundos
  unsigned long tempoFim = micros();

  // Calcula a latência
  unsigned long latencia = tempoFim - tempoInicio;
  latenciaAtuador = latencia;
  
  // Exibe o tempo de latência no monitor serial
  Serial.print("Tempo de latência: ");
  Serial.print(latencia);
  
  delay(500);  // Pausa para a próxima leitura
  
}

/*
  Since GasConcentrationMQ2 is READ_WRITE variable, onGasConcentrationMQ2Change() is
  executed every time a new value is received from IoT Cloud.
*/
void onGasConcentrationMQ2Change()  {
  // Add your code here to act upon GasConcentrationMQ2 change
  cloudReceiveTimeMQ2 = millis();
  cloudTimeMQ2 = cloudReceiveTimeMQ2 - startTimeMQ2;  
}

/*
  Since GasConcentrationMQ135 is READ_WRITE variable, onGasConcentrationMQ135Change() is
  executed every time a new value is received from IoT Cloud.
*/
void onGasConcentrationMQ135Change()  {
  // Add your code here to act upon GasConcentrationMQ135 change
  cloudReceiveTimeMQ135 = millis();
  cloudTimeMQ135 = cloudReceiveTimeMQ135 - startTimeMQ135;
}

/*
  Since CloudTimeMQ2 is READ_WRITE variable, onCloudTimeMQ2Change() is
  executed every time a new value is received from IoT Cloud.
*/
void onCloudTimeMQ2Change()  {
  // Add your code here to act upon CloudTimeMQ2 change
}

/*
  Since CloudTimeMQ135 is READ_WRITE variable, onCloudTimeMQ135Change() is
  executed every time a new value is received from IoT Cloud.
*/
void onCloudTimeMQ135Change()  {
  // Add your code here to act upon CloudTimeMQ135 change
}

/*
  Since LatenciaAtuador is READ_WRITE variable, onLatenciaAtuadorChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onLatenciaAtuadorChange()  {
  // Add your code here to act upon LatenciaAtuador change
}