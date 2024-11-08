#include "room_check.h"
#include<unordered_map>
#include<iostream>
#include "person.h"
#include "covid_negative.h"
#include "covid_positive.h"

bool room_check(int low,int limit,std::unordered_map<int,person*> m){
 for(int i=low;i<=limit;i++){
    if(!m[i]) return true;
 }
 return false;
}
