enum BMS_Parameters {Temperature,Sate_of_Charge,Charge_Rate,Max_NoOf_BMS_Parameters};
enum BMS_Languages {English,German,English_US};

const char* BMS_Parameters_Names[][Max_NoOf_BMS_Parameters]={ {"Temperature" ,    "SOC"      , "ChargeRate"},
                                                              {"Temperatur"  , "Ladezustand" ,  "Ladestrom"} 
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
    bool BMS_Status_bo;
  public:
    enum BMS_Languages BMS_Market_Language_en;
    BMS()
    { BMS_Status_bo = true; }
  
    float Get_5Percent_of_Value(float value_tmp)
    {
      return ((value_tmp * 5)/100);
    }
    /* Verifies the given Parameter is within Tolerance of 5% */
    void Verify_Parameter_Tolerance(float parameter,float max,float min,const char* Parameter_Name);
    /* Verifies the given Parameter is within limits or not */
    void Verify_Parameter(float parameter,BMS_Parameters name_en);
  
    bool Send_BMS_Result()
    {
      return BMS_Status_bo;
    }
    float Fahrenheit_to_Celsius(float temp_fahernheit)
    {
      return ((temp_fahernheit - 32)* 5/9);
    }
  
};
