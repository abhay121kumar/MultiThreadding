#include<iostream>
using namespace std;
#include<fstream>

int main(){
    ofstream fout("writetofile.txt");
    if(!fout){
        cout<<"file could not be opened"<<endl;
        return 1;
    }
    fout<<"this text i have written in vscode but going to directly reflect in the file"<<endl;
    fout.close();
    return 0;
}