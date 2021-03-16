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
