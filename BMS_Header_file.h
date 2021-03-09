enum BMS_Parameters {Temperature,Sate_of_Charge,Charge_Rate};
enum BMS_Lang {English,German};

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
    /* Verifies the given Parameter is within Tolerance of 5% */
    void Verify_Parameter_Tolerance(float parameter,float max,float min,const char* Parameter_Name);
    /* Verifies the given Parameter is within limits or not */
    void Verify_Parameter(float parameter,BMS_Parameters name_en,BMS_Lang Language_en);
  
    bool Send_BMS_Result()
    {
      return BMS_OK;
    }
  
};
