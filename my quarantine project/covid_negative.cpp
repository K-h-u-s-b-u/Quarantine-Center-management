#include "covid_negative.h"
#include<string>
#include<iostream>
#include "person.h"
covid_negative::covid_negative()
{
    //ctor
}

void covid_negative::fns(){

}

covid_negative::covid_negative(std::string name,std::string address,int age,int room_no,int floor)
:person{name,address,age,room_no,floor}
{

}

void covid_negative::get_info(){
std::cout<<"the person is covid negative"<<std::endl;
person::get_info();
}

covid_negative::~covid_negative()
{
    //dtor
}
