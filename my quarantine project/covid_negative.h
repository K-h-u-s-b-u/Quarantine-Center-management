#ifndef COVID_NEG_H
#define COVID_NEG_H
#include<string>
#include "person.h"
class covid_negative : public person
{
    public:
        covid_negative();
        covid_negative(std::string name,std::string address,int age,int room_no,int floor);
        virtual void get_info();
        virtual void fns();
        virtual ~covid_negative();

    protected:

    private:
};

#endif // COVID_NEG_H
