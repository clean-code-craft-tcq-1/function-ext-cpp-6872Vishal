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
struct BMS_Parameters_MAX_and_MIN_Values
{
  enum BMS_Parameters Parameter_Name;
  float Minimum_Value;
  float Maximum_Value;
  const char* BMS_English_Name[];
};

struct BMS_Parameters_MAX_and_MIN_Values BMS_Parameter_MaxMin_st[3]={ {Temperature, (float)0 , (float)45 , "Temperature"}, 
                                                                      {Sate_of_Charge, (float)20 , (float)80 , "SOC"}, 
                                                                      {Charge_Rate, (float)0.0 , (float)0.8 , "ChargeRate"} 
                                                                    };

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
    void Verify_Parameter(float parameter,BMS_Parameters name,BMS_Lang Language)
    {
      float min = BMS_Parameter_MaxMin_st[name].Minimum_Value;
      float max = BMS_Parameter_MaxMin_st[name].Maximum_Value;
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
  class_obj.Verify_Parameter(temperature,Temperature,English);
  class_obj.Verify_Parameter(soc,Sate_of_Charge,English);
  class_obj.Verify_Parameter(chargeRate,Charge_Rate,English);
  return class_obj.Send_BMS_Result();
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
  assert(batteryIsOk(41, 77, 0.7) == true);
}
