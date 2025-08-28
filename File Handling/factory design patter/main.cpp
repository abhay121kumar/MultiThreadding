#include<iostream>
using namespace std;
#include "factoryvehicle.h"

int main(){
    vehicle *v1 = factoryvehicle::createvehicle("car");
    vehicle *v2 = factoryvehicle::createvehicle("bike");
    if(v1) v1->startEngine();
    if(v2) v2->startEngine();
    return 0;
}