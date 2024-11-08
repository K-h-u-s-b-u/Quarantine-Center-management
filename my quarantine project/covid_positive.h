#ifndef COVID_POS_H
#define COVID_POS_H
#include "person.h"
#include<string>

class covid_positive : public person
{
    public:
        virtual void fns();
        covid_positive();
        covid_positive(std::string name,std::string address,int age,int room_no,int floor,std::string viral_strain);
        virtual void get_info();
        virtual ~covid_positive();

    protected:

    private:
        std::string viral_strain;
};

#endif // COVID_POS_H

