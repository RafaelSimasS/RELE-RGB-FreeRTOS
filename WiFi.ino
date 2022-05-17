void vTaskWiFi(void * parametros){
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  Serial.print("Connecting to WiFi ..");
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.println('.');
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.println("Connected to WiFi!");
  }
  Serial.println(WiFi.localIP());
  while(1)
  {
    vTaskDelay(50 / portTICK_PERIOD_MS);
  }
}
