#ifndef ROOM_CHECK_H
#define ROOM_CHECK_H
#include<unordered_map>
#include<iostream>
#include "person.h"
#include "covid_negative.h"
#include "covid_positive.h"

bool room_check(int low,int limit,std::unordered_map<int,person*> m);

#endif // ROOM_CHECK_H

