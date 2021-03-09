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
enum BMS_Lang {English,German};
const char* BMS_Parameters_Name[] = { "Temperature" ,"SOC" , "ChargeRate" };

const char* BMS_Lang_Names[][3]={ {"Temperature" ,"SOC" , "ChargeRate"},{"Temperatur" , "Ladezustand" , "Ladestrom"} };
// enum BMS_Parameters_Min_Value {Temperature_Min = 0,  SOC_Min = 20, ChargeRate_Min = 0.0};
// enum BMS_Parameters_Max_Value {Temperature_Max = 45, SOC_Max = 80, ChargeRate_Max = 0.8};

class BMS{
  private:
  // Variable to verify BMS OK or Not_OK //
    bool BMS_OK;
  public:
    BMS()
    { BMS_OK = true; }
  
    float Return_5Percentage_of_Value(float value_tmp)
    {
      return ((value_tmp * 5)/100);
    }
    void Verify_Parameter_Tolerance(float parameter,float max,float min,BMS_Parameters name,BMS_Lang Language)
    {
      if(parameter < min+Return_5Percentage_of_Value(min))
      {
        cout <<"Low "<<BMS_Lang_Names[Language][name]<<" Warning! \n";
      
      }
      else if(parameter > max-Return_5Percentage_of_Value(max))
      {
        cout <<"High "<<BMS_Lang_Names[Language][name]<<" Warning! \n";
    
      }
      else
      {
        cout<<" "<<BMS_Lang_Names[Language][name]<<" is Normal \n";
      }
    }
    /* Verifies the given Parameter is within limits or not */
    void Verify_Parameter(float parameter,float max,float min,BMS_Parameters name,BMS_Lang Language)
    {
      if(parameter < min)
      {
        cout <<"Low "<<BMS_Lang_Names[Language][name]<<" Breach! \n";
        BMS_OK = false;
      }
      else if(parameter > max)
      {
        cout <<"High "<<BMS_Lang_Names[Language][name]<<" Breach! \n";
        BMS_OK = false;
      }
      else
      {
        Verify_Parameter_Tolerance(parameter,max,min,name,Language);
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
  class_obj.Verify_Parameter(temperature,Temperature_Max,Temperature_Min,Temperature,English);
  class_obj.Verify_Parameter(soc,SOC_Max,SOC_Min,Sate_of_Charge,English);
  class_obj.Verify_Parameter(chargeRate,ChargeRate_Max,ChargeRate_Min,Charge_Rate,English);
  return class_obj.Send_BMS_Result();
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
  assert(batteryIsOk(41, 77, 0.7) == true);
}
