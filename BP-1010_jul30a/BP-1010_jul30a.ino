#include "arduino_secrets.h"
#include "thingProperties.h"

#include <NodeAP.h>

void setup() {
  Node_AP_Init();
  
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

  TimerInit();
}

void loop() {
  //StartToConfig();        //Enter "conf" to config menu
  Routine();
  //WebServerLoop();
  //Mode_Process();
  
  ArduinoCloud.update();
  onAirTempChange();
  // Your code here 
}

void onSoilHumiDryChange() {
  // Do somethi
}
void onSwitch1Change() {
  // Do something
}

/*--- ArduinoIoTCloud function ------------------------------*/
void onAirTempChange() {
  airTemp=10; //SensorVal.air_temp;
}
