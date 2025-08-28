#pragma once
#include<iostream>
using namespace std;
#include "vehicle.h"

class bike:public vehicle{
    public:
    void startEngine() override{
        cout<<"bike engine started"<<endl;
    }
};