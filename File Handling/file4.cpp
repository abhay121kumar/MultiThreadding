#include<iostream>
using namespace std;
#include<fstream>

struct student{
    int id;
    char name[50];
};

int main(){
    student s={101,"abhay"};
    ofstream fout("student.bin",ios::binary);
    if(!fout){
        cout<<"could not open file for write"<<endl;
        return 1;
    }
    fout.write((char*)&s,sizeof(s));
    fout.close();
    return 0;
}