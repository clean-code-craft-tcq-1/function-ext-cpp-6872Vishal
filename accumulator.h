class base
{
protected:
char* BMS_Parameters_Names[][Max_NoOf_BMS_Parameters] = {};
public:
virtual void accumulator(const char* ) = 0;
}

class derieved1:public base
{
public:
void accumulator(const char* text)
{

}
}
