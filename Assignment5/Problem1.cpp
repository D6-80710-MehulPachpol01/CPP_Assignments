#include<iostream>

using namespace std;

// Q1. Write a class Distance to hold feet and inches. Overload operator + as member function and == 
// operator as friend function. Also, overload ++ operator (to increment inches) as member function 
// and -- operator as friend function. Overload << and >> operators to
// accept and display distance


class Distance{
    private:
    int feet;
    int inches;


    public:

    Distance(){
        this->feet = 0;
        this->inches = 0;
    }

    Distance(int feet , int inches){
        this->feet = feet;
        this->inches = inches;
    }

    void Display(){
        cout<<"Feet : "<<this->feet<<endl;
        cout<<"Inches : "<<this->inches<<endl;
    }

    Distance operator+(Distance &other){

        int f = this->feet + other.feet;
        int i = this->inches + other.inches;

        return Distance(f,i);
    }

    void operator++(){
        this
        
        ->inches +=1;
    }


    Distance operator++(int){
        this->inches++;
        return Distance(this->inches , this->feet);
    }

    friend bool operator==(Distance &d1 , Distance &d2);
    friend void operator--(Distance &d1);
    friend void operator>>(istream &input , Distance &d);
    friend void operator<<(ostream &input , Distance &d);
    


};


bool operator==(Distance &d1 , Distance &d2){
    bool flag = false;
    if((d1.feet == d2.feet) && (d1.inches == d2.inches)){
        flag = true;
    }
    return flag;  
}

void operator--(Distance &d1){
    d1.inches -=1; 
}


void operator>>(istream &input , Distance &d){
    cout<<"Enter Feet :"<<endl;
    cin>>d.feet;
    cout<<"Enter Inches :"<<endl;
    cin>>d.inches;
}

void operator<<(ostream &input , Distance &d){
    cout<<"Feet : "<<d.feet<<endl;
    cout<<"Inches : "<<d.inches<<endl;
}






int main(){

    Distance d1(2,2);
    Distance d2(2,2);
    Distance result = d1+d2;
    result.Display();
    bool ans = d1 == d2;
    cout<<ans<<endl;

    --result;
    ++d1;

    result.Display();
    d1.Display();

    return 0;
}