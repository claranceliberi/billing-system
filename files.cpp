#include <iostream>
#include <fstream>

using namespace std;




void write(){
    fstream file;
    file.open("file.txt",ios::out);
    

    if(!file){
        cout << "File not created";
    }else {
        cout << "File created sucesfuly";
        file << "Dealing with file";
        file.close();
    }
}

void read(){
    fstream file;
    string line;

    file.open("file.txt",ios::in);

    if(!file){
        cout << "File not created";
    }else {

        while(getline(file,line)){
            cout << line  << "\n";
        }

        file.close();
    }
}


int main(){

    read();

    return 0;
}