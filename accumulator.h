#include <string>
class base
{
protected:
std::string accumulator_str;
//float Parameters_reported_value[Max_NoOf_BMS_Parameters];
public:
virtual void accumulator(float ,BMS_Parameters ,std::string ) = 0;
virtual void reporting() = 0;
};

class BMS_Car_System:public base
{
public:
void accumulator(float parameter,BMS_Parameters name_en,string print_text)
{
  accumulator_str = accumulator_str + "\n" + print_text;
}
void reporting()
{
cout<<"BMS Condition not Good due to: \n"<<accumulator_str;
}
};
