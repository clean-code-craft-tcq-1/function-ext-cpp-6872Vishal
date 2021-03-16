#include <string>
class base
{
protected:
std::string accumulator_str;
//float Parameters_reported_value[Max_NoOf_BMS_Parameters];
public:
virtual void accumulator(float ,BMS_Parameters ,std::string ,std::string) = 0;
virtual void reporting() = 0;
};

class BMS_Car_System:public base
{
public:
void accumulator(float parameter,BMS_Parameters name_en,std::string para_text,std::string breach_text)
{
  accumulator_str = accumulator_str + para_text + breach_text + "\n";
}
void reporting()
{
std::cout<<"BMS Condition not Good due to: \n"<<accumulator_str;
}
};
