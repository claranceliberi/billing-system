#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <iterator>

using namespace std;

class CSV{
    private:
        const char *filename;

    public:
        CSV(const char *filename);
        map<string, vector<string>> selectAll();
};

CSV :: CSV(const char *filename){
    this->filename = filename;
}

map<string, vector<string>> CSV::selectAll(){
    fstream file(this->filename);
    string line;

    map<string, vector<string>> dataSet;
    vector<string> row;
    string word;

    while(getline(file,line)){
        row.clear();
        stringstream s(line);

        while (getline(s, word, ',')) {
            row.push_back(word);
        }

        dataSet.insert({row[0], row});

        cout << endl;
    }

    return dataSet;
}


void displayVector(vector<string> _vect){
    copy(_vect.begin(), _vect.end(),ostream_iterator<string>(cout, " "));
}

int main(){

    CSV csv("data.csv");

    
    map<string, vector<string>> list = csv.selectAll();

    map<string,vector<string> >::iterator it;

    for (it = list.begin(); it != list.end(); it++)
    {
        cout << it->first << "\t\t";
        displayVector(it->second);
        cout << endl;
    }


    return 0;
}