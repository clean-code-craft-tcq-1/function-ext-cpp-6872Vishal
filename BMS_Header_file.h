
struct BMS_Parameters_MAX_and_MIN_Values
{
  enum BMS_Parameters Parameter_Name;
  float Minimum_Value;
  float Maximum_Value;
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
