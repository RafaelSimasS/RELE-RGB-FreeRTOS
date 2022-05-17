void vTaskRele(void * parametros){
//  entradas.init();
  relecontrol.init();
  relecontrol.pinMode(0,OUTPUT); //RELE1
  relecontrol.pinMode(1,OUTPUT); //RELE2
  relecontrol.pinMode(2,OUTPUT); //RELE6
  relecontrol.pinMode(3,OUTPUT); //RELE5
  relecontrol.pinMode(4,OUTPUT); //RELE4
  relecontrol.pinMode(5,OUTPUT); //RELE3
  relecontrol.pinMode(6,OUTPUT); // CS_SDCARD
  relecontrol.pinMode(7,OUTPUT); // pode ser usado como entrada ou saida
  pinMode(CS_RS485, OUTPUT); // NÃO ESTAMOS USANDO, TESTANDO PARA VER SE SERÁ TRANSPARENTE PARA O SOFTWARE
  
  
  variaveis_controladoras_t variaveis_controladoras;
  xQueueReceive(xQueue_dados, &variaveis_controladoras, portMAX_DELAY);
  int receberParametro;
  int receberCanal;
  receberParametro = variaveis_controladoras.parametro;
  receberCanal = variaveis_controladoras.canal;
  while(1)
  {
    for( int rele = 0; rele <= 5; rele++ )
    {
        relecontrol.digitalWrite(rele, HIGH);   // turn the LED on (HIGH is the voltage level)
        vTaskDelay(500 / portTICK_PERIOD_MS);                     // wait for a second
        relecontrol.digitalWrite(rele, LOW);    // turn the LED off by making the voltage LOW
        vTaskDelay(500 / portTICK_PERIOD_MS);
        Serial2.println("Teste RS485 SEM CS CLP VDC I4.0+");
      }
  }
}
