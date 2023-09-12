#include<iostream>

using namespace std;


class Time{

    int seconds;
    int minutes;
    int hours;
    
    public:

    Time(){

    }

    Time(int min,int sec){
        this->minutes = min;
        this->seconds = sec;
    }

    void setSeconds(int sec){
        this->seconds = sec;

    }

    void setMinutes(int min){
        this->minutes = min;
    }

    int getSeconds(){
        return this->seconds;
    }

    int getMinutes(){

        return this->minutes;
    }


    void Display(){
        cout<<"the time is =>"<<minutes<<" : "<<seconds<<endl;
    }


};

int main(){


    int min , sec;

    cout<<"Enter Time"<<endl;

    cin>>min;
    if(min>59){
        min = 1;
    }
    cin>>sec;

    if(sec>=60){
        min += sec/60;
        sec = sec%60;

    }
    Time t1(min,sec);
    t1.Display();



    


    return 0;
}