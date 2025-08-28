#pragma once
#include<iostream>
using namespace std;
#include "vehicle.h"
#include "car.cpp"
#include "bike.cpp"

class factoryvehicle{
    public:
    static vehicle* createvehicle(const string type){
        if(type=="car") return new car();
        else if(type=="bike") return new bike();
        else return nullptr;
    }
};