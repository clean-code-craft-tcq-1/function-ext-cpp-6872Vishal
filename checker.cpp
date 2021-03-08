#include <assert.h>
#include <iostream>
using namespace std;

#define Temperature_Min  0
#define Temperature_Max  45
#define SOC_Min  20
#define SOC_Max  80
#define ChargeRate_Min  0.0
#define ChargeRate_Max  0.8
/* BMS : Battery Management System */
enum BMS_Parameters {Temperature,Sate_of_Charge,Charge_Rate};
const char* BMS_Parameters_Name[] = { "Temperature" ,"SOC" , "ChargeRate" };

const char* BMS_Lang_Names[][]={ {"Temperature" ,"SOC" , "ChargeRate"},{"Temperatur" , "Ladezustand" , "Ladestrom"} };
// enum BMS_Parameters_Min_Value {Temperature_Min = 0,  SOC_Min = 20, ChargeRate_Min = 0.0};
// enum BMS_Parameters_Max_Value {Temperature_Max = 45, SOC_Max = 80, ChargeRate_Max = 0.8};

class BMS{
  private:
  // Variable to verify BMS OK or Not_OK //
    bool BMS_OK;
  public:
    BMS()
    { BMS_OK = true; }
    /* Verifies the given Parameter is within limits or not */
    void Verify_Parameter(float parameter,float max,float min,BMS_Parameters name)
    {
      if(parameter < min)
      {
        cout <<BMS_Parameters_Name[name]<<" is below the Minimum Thershold! \n";
        BMS_OK = false;
      }
      else if(parameter > max)
      {
        cout <<BMS_Parameters_Name[name]<<" is above the Maximum Thershold! \n";
        BMS_OK = false;
      }
      else
      {
        //do nothing 
      }
    }
  bool Send_BMS_Result()
  {
    return BMS_OK;
  }
  
};
/* Returns the Battery state : OK or Not_OK */
bool batteryIsOk(float temperature, float soc, float chargeRate) {
  class BMS class_obj;
  class_obj.Verify_Parameter(temperature,Temperature_Max,Temperature_Min,Temperature);
  class_obj.Verify_Parameter(soc,SOC_Max,SOC_Min,Sate_of_Charge);
  class_obj.Verify_Parameter(chargeRate,ChargeRate_Max,ChargeRate_Min,Charge_Rate);
  return class_obj.Send_BMS_Result();
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
