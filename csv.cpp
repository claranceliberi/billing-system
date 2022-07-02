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
        vector<string> selectById(int id);
};

CSV :: CSV(const char *filename){
    this->filename = filename;
}
/**
 * @brief select everything  from file
 * 
 * @return map<string, vector<string>> 
 */
map<string, vector<string>> CSV::selectAll(){
    fstream file(this->filename);

    map<string, vector<string>> dataSet;
    vector<string> row;
    string word,line;

    while(getline(file,line)){
        row.clear();
        stringstream s(line);

        while (getline(s, word, ',')) {
            row.push_back(word);
        }

        dataSet.insert({row[0], row});

        cout << endl;
    }

    //close file after reading
    file.close();

    return dataSet;
}


/**
 * @brief select specific record in file
 * 
 * @param id 
 * @return vector<string> 
 */
vector<string> CSV::selectById(int id){
    fstream file(this->filename);

    vector<string> foundRow;
    string line,word;
    int foundId;

    while(getline(file,line)){
        foundRow.clear();
        stringstream s(line);

        while(getline(s,word,',')){
            foundRow.push_back(word);
        }

        // assuming that every first element will be interger
        foundId = stoi(foundRow[0]);

        if( foundId == id)
            return foundRow;
    }

    throw 404;
}

void displayVector(vector<string> _vect){
    copy(_vect.begin(), _vect.end(),ostream_iterator<string>(cout, " "));
}

void displayMap(map<string,vector<string>>* list){
    map<string,vector<string> >::iterator it;

    for (it = list->begin(); it != list->end(); it++)
    {
        cout << it->first << "\t\t";
        displayVector(it->second);
        cout << endl;
    }
}

int main(){

    CSV csv("data.csv");

    
    map<string, vector<string>> list = csv.selectAll();

    // displayMap(&list);

    try{
        displayVector(csv.selectById(20));
    }catch(int e){
        if(e == 404)
        cout << "\nNot found\n" ; 
    }

    return 0;
}