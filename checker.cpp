#include <assert.h>
#include <iostream>
using namespace std;

/* BMS : Battery Management System */
enum BMS_Parameters {Temperature,Sate_of_Charge,Charge_Rate};
enum BMS_Lang {English,German};
//const char* BMS_Parameters_Name[] = { "Temperature" ,"SOC" , "ChargeRate" };

const char* BMS_Parameters_Names[][3]={ {"Temperature" ,"SOC" , "ChargeRate"},
                                       {"Temperatur" , "Ladezustand" , "Ladestrom"} 
                                      };

struct BMS_Parameters_MAX_and_MIN_Values
{
  enum BMS_Parameters Parameter_Name;
  float Minimum_Value;
  float Maximum_Value;
};

struct BMS_Parameters_MAX_and_MIN_Values BMS_Parameter_MaxMin_st[3]={ {Temperature, (float)0 , (float)45 }, 
                                                                      {Sate_of_Charge, (float)20 , (float)80 }, 
                                                                      {Charge_Rate, (float)0.0 , (float)0.8 } 
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
    void Verify_Parameter_Tolerance(float parameter,float max,float min,const char* Parameter_Name)
    {
      if(parameter < min+Return_5Percentage_of_Value(min))
      {
        cout <<"Low "<<Parameter_Name<<" Warning! \n";
      
      }
      else if(parameter > max-Return_5Percentage_of_Value(max))
      {
        cout <<"High "<<Parameter_Name<<" Warning! \n";
    
      }
      else
      {
        cout<<Parameter_Name<<" is Normal \n";
      }
    }
    /* Verifies the given Parameter is within limits or not */
    void Verify_Parameter(float parameter,BMS_Parameters name_en,BMS_Lang Language_en)
    {
      float min = BMS_Parameter_MaxMin_st[name_en].Minimum_Value;
      float max = BMS_Parameter_MaxMin_st[name_en].Maximum_Value;
      const char* Parameter_Name = BMS_Parameters_Names[Language_en][name_en];
      if(parameter < min)
      {
        cout <<"Low "<<Parameter_Name<<" Breach! \n";
        BMS_OK = false;
      }
      else if(parameter > max)
      {
        cout <<"High "<<Parameter_Name<<" Breach! \n";
        BMS_OK = false;
      }
      else
      {
        Verify_Parameter_Tolerance(parameter,max,min,Parameter_Name);
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
