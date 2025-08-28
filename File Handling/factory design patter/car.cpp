#pragma once
#include<iostream>
#include "vehicle.h"
using namespace std;
class car:public vehicle{
    public:
    void startEngine() override{
        cout<<"car enigne started"<<endl;
    }
};