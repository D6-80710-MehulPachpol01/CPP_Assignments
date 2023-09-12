#include <iostream>
using namespace std;


int menu(){
    cout<<"Menu - Exit:0"<<endl<< "Accept:1"<<endl<< "Print:2"<<endl<<"Leap year check:3"<<endl;
    int option;
    cin>>option;
    return option;
}

struct Date
{
    int day;
    int month; 
    int year;
    
};

void initDate(struct Date* ptrDate){
    ptrDate->day = 8;
    ptrDate->month = 9;
    ptrDate->year = 2023; 
};
void printDateOnConsole(struct Date* ptrDate){
    cout<<"Date is: " << ptrDate->day<<"-"<<ptrDate->month<<"-"<<ptrDate->year<<endl;
};
void acceptDateFromConsole(struct Date* ptrDate){
    cout<<"Write day: ";
    cin>>(ptrDate->day);
    cout<<"Write month: ";
    cin>>(ptrDate->month);
    cout<<"Write year: ";
    cin>>(ptrDate->year);
    


};

bool isLeapYear(struct Date* ptrDate){
    if((ptrDate->year%4==0 && ptrDate->year%100 !=0) || (ptrDate->year%400==0)){
        return true;      
    }
    else{
        return false;
    }
}

int main(){
    struct Date e;
    initDate(&e);
    int a;
    
    while((a = menu()) !=0){
        switch(a){
            case 1:{
                acceptDateFromConsole(&e);
                break;
            }
            
            case 2:{
                printDateOnConsole(&e);
                break;
        
            }
            case 3:{
                if(isLeapYear(&e)){
                    cout<<"Current year is leap year"<<endl;
                }
                else{
                    cout<<"Current year is not a leap year"<<endl;
                }
                break;
            }
            
            
            default:{
                cout<<"Invalid input"<<endl;
                break;

            }
            
        }
    }

    cout<<"Thanks";
    






    return 0;
}