// Write a user defined function factorial() that calculates factorial of given number and it throws
// exception if number entered by user is negative.


#include<iostream>
using namespace std;

int factorial(){

    cout<<"Enter a number"<<endl;
    int a;
    cin>>a;
    if(a<0){
        throw 1;
    }
    int fact = 1;
    while(a>0){
        fact *= a;
        a--;
    }
    cout<<"fact is :" <<fact<<endl;

    return fact;

}


int main(){

    try{
        factorial();
    }
    catch(int error){
        cout<<"enter positive value"<<endl;
    try{
        factorial();
    }
    catch(int error){
        cout<<"enter positive value"<<endl;
        factorial();

    }

    }
    


    return 0;
}