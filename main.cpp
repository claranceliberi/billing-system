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
        void remove();
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
            remove();
            break;
        case 4:
            menu();
            break;
        default:
            cout << "\t Invalid choicen   \n";
            break;
    }

    goto m;
}
