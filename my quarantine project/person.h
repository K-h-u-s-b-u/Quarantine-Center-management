#ifndef PERSON_H
#define PERSON_H
#include<string>

class person
{
    private:
        std::string name;
    std::string address;
    int age;
    int room_no;
    int floor;

    public:
        virtual void fns()=0;
        person();
        person(std::string name,std::string address,int age,int room_no,int floor);
        virtual void get_info();
        std::string get_name();
        virtual ~person();

    protected:


};

#endif // PERSON_H
