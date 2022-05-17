#include <AsyncMqttClient.h>
#include <TridentTD_EasyFreeRTOS32.h>
#include <PortExpander_I2C.h> 
#include <WiFi.h>

const char* ssid = "AGUIAR_ADM";
const char* password = "a0b9c8d7e6";
  
PortExpander_I2C relecontrol(0x27);  // 
PortExpander_I2C entradas(0x20);
#define RXD2 16
#define TXD2 17
int CS_RS485 = 5; //NÃO ESTAMOS USANDO, TESTANDO PARA VER SE SERÁ TRANSPARENTE PARA O SOFTWARE

QueueHandle_t xQueue_dados; 

typedef struct{
    int canalIO;   
    int parametro;    
} variaveis_controladoras_t;

void setup() {  
  Serial.begin(115200);
  xQueue_dados = xQueueCreate(5, sizeof(variaveis_controladoras_t));
  if(xQueue_dados == NULL)
  {
   Serial.println("Fila não foi criada");
  }else
  {
   Serial.println("Fila foi criada");
  }
  
  xTaskCreatePinnedToCore(vTaskRele, "TaskRele", 3000, NULL, 2, NULL, 1);
  xTaskCreatePinnedToCore(vTaskWiFi, "TaskWiFi", 7000, NULL, 1, NULL, 0);
  
}

void loop(){}
