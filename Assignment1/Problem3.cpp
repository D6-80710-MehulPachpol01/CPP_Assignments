#include <iostream>
using namespace std;

int menu(){
    cout<<"Menu - Exit:0"<<endl<< "Accept:1"<<endl<< "Print:2"<<endl;
    int option;
    cin>>option;
    return option;
}

class Student{
    int roll_no;
    string name;
    int marks;

    public:
    void initStudent(){
        roll_no = 1;
        name = "Mehul";
        marks = 90;
    }; 
    void printStudentOnConsole(){
        cout<<"Student details are: "<<endl;
        cout<<"Student Roll no: "<<roll_no<<endl;
        cout<<"Student name: "<<name<<endl;
        cout<<"Student marks: "<<marks<<endl;

    };  
    void acceptStudentFromConsole(){
        cout<<"Write student roll no: ";
        cin>>roll_no;
        cout<<endl;
        cout<<"Write student name: ";
        cin>>name;
        cout<<endl;
        cout<<"Write student marks: ";
        cin>>marks;
        cout<<endl;
    };




};



int main(){
    Student s1;
    s1.initStudent();
    int a;
    
    while((a = menu()) !=0){
        switch(a){
            case 1:{
                s1.acceptStudentFromConsole();
                break;
            }
            
            case 2:{
                s1.printStudentOnConsole();
                break;
        
            }
           
            
            default:{
                cout<<"Invalid input";
                break;

            }
            
        }
    }

    cout<<"Thanks";

    return 0;
}