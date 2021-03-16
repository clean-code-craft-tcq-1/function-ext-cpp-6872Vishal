
class BMS: public BMS_Car_System
{
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
