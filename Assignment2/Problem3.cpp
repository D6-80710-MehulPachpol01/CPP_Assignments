#include<iostream>
using namespace std;


namespace Na{
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

        
}


int main() {

    Na::Student s1;
    s1.initStudent();
    s1.acceptStudentFromConsole();
    s1.printStudentOnConsole();

    return 0;
}