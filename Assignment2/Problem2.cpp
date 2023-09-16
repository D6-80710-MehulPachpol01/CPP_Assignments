#include<iostream>

using namespace std;

class Toolbooth
{
private:

    /* data */

    int cars;
    int fine;

public:

Toolbooth(){
    this->cars = 0;
    this->fine = 0;
}

void PayingCar(){
    this->cars++;
    this->fine +=50;
}

void NonPayingCar(){
    this->cars++;

}

// void Display(){
//     cout<<"Cars Passed :"<<this->cars<<endl;
//     cout<<"Cars Fined :"<<this->fine/50<<endl;
//     cout<<"Fine Collected :"<<this->fine<<endl;
// }

void Display() {
        std::cout << "+------------------+------------------+------------------+" << std::endl;
        std::cout << "|   Cars Passed    |   Cars Fined     |   Cars Not Fined |" << std::endl;
        std::cout << "+------------------+------------------+------------------+" << std::endl;
        cout<<"        "<<this->cars<<"                    "<<this->fine/50<<"                    "<<this->cars - (this->fine/50)<<endl;
        
        std::cout << "+------------------+------------------+------------------+" << std::endl;
        std::cout << "|   Fine Collected : " << fine << " |" << std::endl;
        std::cout << "+------------------+" << std::endl;
    }




 
};


int menu(){
    int choice;

    cout<<"0:Exit"<<endl;
    cout<<"1:Fine Car: "<<endl;
    cout<<"2:No Fine: "<<endl;
    cout<<"3:Daily Report: "<<endl;

    cout<<"Enter your choice: ";
    cin>>choice;
    return choice;
}





int main() {



    Toolbooth t1;

    int opt;

    while((opt=menu())!=0){

                    cout<<"================================================================================================="<<endl;



        switch(opt){
            case 1:
            t1.PayingCar();
            break;
            cout<<"================================================================================================="<<endl;

            case 2:
            t1.NonPayingCar();
            break;
            cout<<"================================================================================================="<<endl;

            case 3:
            t1.Display();
            break;

            cout<<"================================================================================================="<<endl;


            default:
            cout<<"Invalid input"<<endl;
        }

        cout<<"Thank you"<<endl;
        cout<<"================================================================================================="<<endl;

    }








    t1.PayingCar();
    t1.PayingCar();
    t1.PayingCar();
    t1.PayingCar();
    t1.NonPayingCar();
    t1.NonPayingCar();
    t1.NonPayingCar();
    t1.NonPayingCar();
    t1.Display();
    return 0;
}
