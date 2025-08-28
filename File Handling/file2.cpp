#include<iostream>
using namespace std;
#include<fstream>
#include<string>

int main(){
    ifstream fin("writetofile.txt");
    if(!fin){
        cout<<"file not found"<<endl;
    }
    string line;
    while(getline(fin,line)){
        cout<<line<<endl;
    }
    fin.close();
    return 0;
}