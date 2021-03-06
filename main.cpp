#include <iostream>
#include <fstream>

using namespace std;

class Shopping{
    private:
        int pcode;
        float price;
        float discount;
        string pname;
    
    public:
        void menu();
        void administrator();
        void buyer();
        void add();
        void edit();
        void rem();
        void list();
        void receipt();
};

void Shopping :: menu(){
m:
    int choice;
    string email;
    string password;

    cout << "\t\t\t\t______________________________________________________________\n" ;
    cout << "\t\t\t\t                                                              \n" ;
    cout << "\t\t\t\t                      Supermarket Main Menu                   \n" ;
    cout << "\t\t\t\t                                                              \n" ;
    cout << "\t\t\t\t______________________________________________________________\n" ;
    cout << "\t\t\t\t                                                              \n" ;
    cout << "\t\t\t\t                                                              \n" ;
    cout << "\t\t\t\t|      1. Administrator        |\n" ;
    cout << "\t\t\t\t|                              |\n" ;
    cout << "\t\t\t\t|      2. Buyer                |\n" ;
    cout << "\t\t\t\t|                              |\n" ;
    cout << "\t\t\t\t|      3. Exit                 |\n" ;
    cout << "\t\t\t\t|                              |\n" ;
    cout << "\t\t\t\t      Please Select            \n" ;
    cin >> choice;


    switch (choice)
    {
        case 1:
                cout << "\t\t\t Please login           \n";
                cout << "\t\t\t Enter email            \n";
                cin >> email;
                cout << "\t\t\t Enter password         \n";
                cin >> password;

                if(email != "liberi@gmail.com" && password != "root@123")
                    cout << "\t\t\t Invalid Email/Password!!!!         \n";
                else 
                    administrator();

            break;
        case 2:
            buyer();
            break;
        case 3: 
            exit(0);
            break;
    default:
        cout << "Please select one of the option provided above \n";
        break;
    }

    goto m;
}


void Shopping :: administrator(){
    m:
    int choice;

    cout << "\n\n\n";
    cout << "\t\t\t     Administrator Menu      \n";
    cout << "\t\t\t|                            |\n";
    cout << "\t\t\t|____1) Add Product__________|\n";
    cout << "\t\t\t|                            |\n";
    cout << "\t\t\t|____2) Modify Product_______|\n";
    cout << "\t\t\t|                            |\n";
    cout << "\t\t\t|____3) Delete Product_______|\n";
    cout << "\t\t\t|                            |\n";
    cout << "\t\t\t|____4) Bak to Menu__________|\n\n";

    cout << "\t Please enter your choice" ;
    cin >> choice;


    switch(choice){
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            rem();
            break;
        case 4:
            menu();
            break;
        default:
            cout << "\t Invalid choice   \n";
            break;
    }

    goto m;
}

void Shopping :: buyer(){
    m:
    int choice;

      cout << "\n\n\n";
    cout << "\t\t\t     Buyer       \n";
    cout << "\t\t\t|                            |\n";
    cout << "\t\t\t|____1) Buy Product__________|\n";
    cout << "\t\t\t|                            |\n";
    cout << "\t\t\t|____2) Go Back-------_______|\n";
    cout << "\t\t\t|                            |\n";
    cout << "\t Please enter your choice" ;
    cin >> choice;

    switch(choice){
        case 1:
            receipt();
            break;
        case 2:
            menu();
            break;
        default :
            cout << "\t Invalid choice   \n";
            break;

    }
}

void Shopping :: add(){
    m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;


    cout << "\n\n\t\t Add new product";
    cout << "\n\n\t Product code of the product   ";
    cin >> pcode;
    cout << "\n\n\t Name of the product   ";
    cin >> pname;
    cout << "\n\n\t Price  of the product   ";
    cin >> price;
    cout << "\n\n\t Discount  of the product   ";
    cin >> discount;

    data.open("database.txt", ios::in);

    if(!data){
        data.open("database.txt", ios::app | ios::in);
        data << " " << pcode << " " << pname << " " << price << " " << discount << "\n";
        data.close();
    }else {
        data >> c >> n >> p >> d;

        while(!data.eof()){
            if(c == pcode){
                token++;
            }

            data >> c >> n >> p >>  d;
        }

        data.close();
    }

    if(token == 1){
        goto m;
    }else {
        data.open("database.txt", ios::app | ios::in);
        data << " " << pcode << " " << pname << " " << price << " " << discount << "\n";
        data.close();
    }

    cout  << "\n\n\t\t Record inserted";

}

void Shopping::edit(){
    fstream data, data1;

    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout << "\n\t\t\t Modify the record ";
    cout << "\n\t\t\t Product code :";
    cin >> pkey;

     data.open("database.txt", ios::in);

    if(!data){
        cout << "\n\nFile doesn't exists! ";
    }else {
        data1.open("database.txt", ios::app | ios::in);
        data >> pcode >> pname >> price >> discount;
        while(!data.eof()){
            if(pkey == pcode){
                cout << "\n\n\t Product new code   ";
                cin >> c;
                cout << "\n\n\t Name ";
                cin >> n;
                cout << "\n\n\t Price  ";
                cin >> p;
                cout << "\n\n\t Discount ";
                cin >> d;

                data1 << " " << c << " " << n << " " << p << " " << d << "\n";
                cout  << "\n\n\t\t Record edited";

            } else {
                data1 << " " << pcode << " " << pname << " " << price << " " << discount << "\n";
            }

            data >> pcode >> pname >> price >> discount;
        }

        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");
    }

    if(token == 0){
        cout << "\n\n Record not found sorry";
    }

}

void Shopping::rem(){
    fstream data, data1;

    int pkey;
    int token=0;

    cout << "\n\t\t\t Delete product ";
    cout << "\n\t\t\t Product code :";
    cin >> pkey;
    data.open("database.txt", ios::in);

    if(!data){
        cout << "\n\nFile doesn't exists! ";
    }else {
        data1.open("database.txt", ios::app | ios::in);
        data >> pcode >> pname >> price >> discount;
        while(!data.eof()){
            if(pkey == pcode){
                cout << "\n\n\t Product deleted successfully";
            } else {
                data1 << " " << pcode << " " << pname << " " << price << " " << discount << "\n";
            }

            data >> pcode >> pname >> price >> discount;
        }

        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token == 0){
            cout << "\n\n Record not found sorry";
        }

    }
}


void Shopping :: list(){
    fstream data;
    data.open("database.txt", ios::in);

    cout << "\n\n|___________________________________________________________________________|";
    cout << "\n\n|ProNo\t\tName\t\tPrice\n";
    cout << "\n\n|___________________________________________________________________________|";
    data >> pcode >> pname >> price >> discount;
    while(!data.eof()){
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
        data >> pcode >> pname >> price >> discount;
    }

    data.close();
    
}

void Shopping :: receipt(){
    m:
    fstream data;
    int arrc[100];
    int arrq[100];

    char choice;
    int c=0;
    float ammount =0;
    float dis =0;
    float total = 0;


    cout << "\n\n\t\t\t\t   RECEIPT";
    data.open("database.txt",ios::in);

    if(!data){
        cout << "\n\n   Empty database" ;
    }else {
        data.close();
        list();
        
        cout << "\n\n|_________________________________________________________________|";
        cout << "\n\n|                                                                 |";
        cout << "\n\n|            Please place the order                               |";
        cout << "\n\n|                                                                 |";
        cout << "\n\n|_________________________________________________________________|";

        do{
            cout << "\n\nEnter Product code";
            cin >> arrc[c];
            cout << "\n\nEnter the product quantity";
            cin >> arrq[c];
            
            for(int i=0; i<c; i++){
                if(arrc[c] == arrc[i]){
                    cout << "\n\nDuplicated product code\n";
                    goto m;
                }
            }

            c++;

            cout << "\n\nDo you want to buy another product? if yes press y else no";
            cin >> choice;

        }while(choice == 'y');

        cout << "\n\n\t\t\t______________________________RECEIPT____________________\n";
        cout << "\nProduct No \t Product name \t Product quantity \t price \t Ammount \t Ammount with discout \n";

        for(int i=0; i<c; i++){
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> discount;
            
            while(!data.eof()){
                if(pcode == arrc[i]){
                    ammount = price*arrq[i];
                    dis = ammount - (ammount * discount/100);
                    total = total + dis;
                    cout << "\n" << pcode << " \t " << pname << " \t " << arrq[i]  << " \t " << price << " \t " << ammount << " \t "  << dis;
                }

                data >> pcode >> pname >> price >> discount;
            }
        }

        data.close();

    }

    cout << "\n\n_________________________________________________________\n";
    cout << "\n\nTotal Ammount : \n\n";

}

int main(){
    Shopping s;
    s.menu();
}