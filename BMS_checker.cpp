#include <assert.h>
#include <iostream>
#include "BMS_Header_file.h"
using namespace std;

/* BMS : Battery Management System */
/* Verifies the given Parameter is within Tolerance of 5% or not */
void BMS :: Verify_Parameter_Tolerance(float parameter,float max,float min,const char* Parameter_Name)
{
  if(parameter < min+Return_5Percentage_of_Value(max))
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
void BMS :: Verify_Parameter(float parameter,BMS_Parameters name_en)
{
  float min = BMS_Parameter_MaxMin_st[name_en].Minimum_Value;
  float max = BMS_Parameter_MaxMin_st[name_en].Maximum_Value;
  const char* Parameter_Name = BMS_Parameters_Names[BMS_Market_Language_en][name_en];
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
/* Returns the Battery state : OK or Not_OK */
bool batteryIsOk(float temperature, float soc, float chargeRate,BMS_Languages tmplang_en) {
  class BMS class_obj;
  class_obj.BMS_Market_Language_en = tmplang_en;
  class_obj.Verify_Parameter(temperature,Temperature);
  class_obj.Verify_Parameter(soc,Sate_of_Charge);
  class_obj.Verify_Parameter(chargeRate,Charge_Rate);
  return class_obj.Send_BMS_Result();
}

int main() {
  cout<<"**************1st Test Case***********************\n";
  assert(batteryIsOk(25, 70, 0.7, German) == true);
  cout<<"**************2nd Test Case***********************\n";
  assert(batteryIsOk(50, 85, 0, English) == false);
  cout<<"**************3rd Test Case***********************\n";
  assert(batteryIsOk(44.25, 77, 0.78, German) == true);
    cout<<"**************4th Test Case***********************\n";
  assert(batteryIsOk(1.75, 21.4, 0.03, German) == true);
}
