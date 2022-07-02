#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;


int main(){

    fstream file("data.csv");

    string line;

    vector<string> row;
    string word;

    while(getline(file,line)){
        stringstream s(line);

        while (getline(s, word, ',')) {
            cout << word << "\t\t" ;
            
        }

        cout << endl;
    }

    return 0;
}