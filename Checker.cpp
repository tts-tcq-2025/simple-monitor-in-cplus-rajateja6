#include <assert.h>
#include <iostream>
using namespace std;

const float TEMP_MIN = 0;
const float TEMP_MAX = 45;
const float SOC_MIN = 20;
const float SOC_MAX = 80;
const float CHARGE_RATE_MAX = 0.8;

bool temperatureIsOk(float temperature){
 if(temperature < TEMP_MIN || temperature > TEMP_MAX) {
    cout << "Temperature out of range!\n";
    return false;
  }
  return true; 
}

bool socIsOk(float soc){
 if(soc < SOC_MIN || soc > SOC_MAX) {
    cout << "State of Charge out of range!\n";
    return false;
  }
  return true; 
}

bool chargeRateIsOk(float chargeRate){
 if(chargeRate > CHARGE_RATE_MAX) {
    cout << "Charge Rate out of range!\n";
    return false;
  }
  return true; 
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
  return ( temperatureIsOk(temperature) &&
           socIsOk(soc) &&
           chargeRateIsOk(chargeRate) );
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
  return ( 0 );
}
