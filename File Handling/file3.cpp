#include<iostream>
using namespace std;
#include<fstream>
struct student{
    int id;
    char name[50];
};

int main(){
    student s1;
    ifstream fin("student.bin",ios::binary);
    if(!fin){
        cout<<"file could not be opened"<<endl;
        return 1;
    }
    fin.read((char*)&s1,sizeof(s1));
    fin.close();
    cout << "Student ID: " << s1.id << ", Name: " << s1.name << endl;
    return 0;
}