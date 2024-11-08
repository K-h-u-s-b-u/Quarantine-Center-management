#include "covid_positive.h"
#include "person.h"
#include<iostream>
#include<string>
covid_positive::covid_positive()
{
    //ctor
}

void covid_positive::fns(){
    //override
}

covid_positive::covid_positive(std::string name,std::string address,int age,int room_no,int floor,std::string viral_strain)
:person{name,address,age,room_no,floor}
{
this->viral_strain=viral_strain;
}

void covid_positive::get_info(){
    std::cout<<"the person is covid positive"<<std::endl;
    person::get_info();
    std::cout<<viral_strain<<std::endl;
}

covid_positive::~covid_positive()
{
    //dtor
}
