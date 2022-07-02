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
        int updateById(int id,string data);
        int updateById(int id,vector<string> data);
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

    file.close();
    throw 404;
}

/**
 * @brief Update certain line in csv file by id
 * 
 * @param id 
 * @param data 
 * @return int 
 */
int CSV::updateById(int id, string data){
    // NOTE: i know this function has stupid logic that could never be done in large enterprise application
    // rewriting whole file 😒, i understands how overwhelming it is  and how poor perfomant it is
    // but you need to understand that i was rushing and this was fast for me, or if you have time open PR
    // dealing with file pointers is kinda pain


    fstream file(this->filename);
    ofstream temp;
    int updatedRows =0;
    int linePosition = 0;

    string line,identity, tempFileName = "temp.csv";

    temp.open(tempFileName);

    while(getline(file,line)){

        stringstream s(line);
        
        getline(s,identity,',');

        if(id == stoi(identity)){
            line.replace(line.find(line),line.length(),data);
            updatedRows++;
        }
        temp << line << "\n";

        linePosition = file.tellp();

    }

    temp.close();
    file.close();

    remove(this->filename);
    rename(const_cast<char*>(tempFileName.c_str()),this->filename);

    return updatedRows;
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

    
    // TEST SELECT ALL FUNCTIONALITY
    // map<string, vector<string>> list = csv.selectAll();
    // displayMap(&list);

    // TEST GET FUNCTIONALITY
    // try{
    //     displayVector(csv.selectById(20));
    // }catch(int e){
    //     if(e == 404)
    //     cout << "\nNot found\n" ; 
    // }


    // TEST UPDATE FUNCTIONALITY
    displayVector(csv.selectById(1));
    
    cout << "\n\n" << csv.updateById(1,"1,ntwari,900") << "\n\n";
    displayVector(csv.selectById(1));

    return 0;
}