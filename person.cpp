#include "person.h"
#include<iostream>
#include<string>
person::person()
{
    //ctor
}

person::person(std::string name,std::string address,int age,int room_no,int floor){
  this->name=name;
  this->address=address;
  this->age=age;
  this->room_no=room_no;
  this->floor=floor;
}

void person::get_info(){
   std::cout<<"name"<<" "<<name<<std::endl;
   std::cout<<"address"<<" "<<address<<std::endl;
   std::cout<<"age"<<" "<<age<<std::endl;
   std::cout<<"room_no"<<" "<<room_no<<std::endl;
   std::cout<<"floor"<<" "<<floor<<std::endl;
}

std::string person::get_name(){
    return name;
}

person::~person()
{
    //dtor
}
