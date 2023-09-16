#include<iostream>
#include <bits/stdc++.h>

// Write a menu driven program for Student management. In main(), create Array of Objects and
// provide facility for accept, print, search and sort.
// For student accept name, gender, rollNumber and marks of three subjects from user and print name,
// rollNumber, gender and percentage.
// Provide global functions void sortRecords(Studuent[] arr) and int searchRecords(Student[] arr) for
// sorting and searching array.
// Search function returns index of found Student, otherwise returns -1.


using namespace std;

class Student{

    


    public:

    string gender;
    string name;
    int rollnumber;
    int marks[3];

    Student(){
        this->gender = "";
        this->name = "";
        this->rollnumber = 0;
        for(int i = 0;i<3;i++){

            this->marks[i] = 0;

        }
    }

    void Acceptdata(){
        cout<<"Enter Name"<<endl;
        cin>>this->gender;
        cout<<"Enter Gender"<<endl;
        cin>>this->name;
        cout<<"Enter Roll No"<<endl;
        cin>>this->rollnumber;
        cout<<"Enter Marks"<<endl;
        int temp = 0;
        for(int i=0;i<3;i++){
            cout<<"Enter Marks For Subject "<<i+1<<endl;
            cin>>temp ;
            if(temp>100){
                this->marks[i] = 100;

            }
            else{
                this->marks[i] = temp;

            }

        }
    }

    void Display(){
        cout<<"Name :"<<this->name<<endl;
        cout<<"Gender :"<<this->gender<<endl;
        cout<<"Roll No :"<<this->rollnumber<<endl;
        int sum = 0;
        for(int i=0;i<3;i++){
            sum+=marks[i];
        }
        float per = sum/300;
        cout<<"Marks :"<<sum<<"out of 300"<<endl;
    }










   





};

void swap(Student &s1 , Student &s2){
    Student temp = s1;
    s1 = s2;
    s2 = temp;
}

void sortRecords(Student arr[],int size){

    for(int i = 0 ; i<size-1;i++){
        for(int j = 0; j<size-i-1;j++){
            if(arr[j].rollnumber<arr[j+1].rollnumber){
                swap(arr[j],arr[j+1]);
            }
        }
    }

    

}

int searchRecords(Student arr[],int roll,int size){
    for(int i =0;i<size;i++){
        if(arr[i].rollnumber == roll){
            return i;
        }
    }
    
    
    return -1;

}


int main(){



    cout<<"Enter Number of Students"<<endl;
    int size;
    cin>>size;
    Student *arr = new Student[size];

    for(int i =0;i<size;i++){
        arr[i].Acceptdata();
    }
    cout<<"=============================Orignal Array=================================="<<endl;
    for(int i =0;i<size;i++){
        arr[i].Display();
    }

    cout<<"=========================================================================================="<<endl;

    int searchedindex = searchRecords(arr,12,size);
    cout<<"Element found at "<<searchedindex<<endl;

    cout<<"=========================================================================================="<<endl;
    cout<<"==============================SOrted Array======================"<<endl;



    sortRecords(arr , size);
    for(int i =0;i<size;i++){
        arr[i].Display();
    }

    cout<<"=========================================================================================="<<endl;



    // Student s1;
    // s1.Acceptdata();
    // s1.Display();

    // Student s2;

    // swap(s1,s2);
    // s1.Display();
    // s2.Display();


    



    return 0;
}