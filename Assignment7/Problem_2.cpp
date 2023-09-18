//  Create a user defined class “Fraction” with data members numerator and denominator. Provide 
// constructors, getter/setters and methods like lowestForm() and decimalValue(). The 
// setDenominator() method should throw exception if value is zero. Overload operators +, -, *, /, =, 
// ==, !=, <, >

#include<iostream>

using namespace std;


class Fraction{

    private:
    int denominator;
    int numerator ;

    public:
    Fraction(){
        this->denominator = 1;
        this->numerator = 0;
    }

    Fraction(int deno,int num){
        if(deno==0){
            throw 2;
        }
        else{
            this->denominator = deno;
            this->numerator = num;
        }
    }

    void setdeno(int deno){
        int temp = deno;
        if(temp == 0){
            throw 2;
        }
        this->denominator = deno;
    }

    void setnum(int num){
        this->numerator = num;
    }

    float decimalValue(){
        float temp = float(this->numerator)/float(this->denominator);
        cout<<"The decimal form is :"<<temp<<endl;

        return temp;
    }

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }


    void lowestFraction() {
        int commonDivisor = gcd(numerator, denominator);
        
        this->numerator /= commonDivisor;
        this->denominator /= commonDivisor;

        cout<<"The lowest Fraction == "<<this->numerator<<"/"<<this->denominator<<endl;

    }

    Fraction operator+(Fraction &other){
        int n = this->denominator*other.numerator + other.denominator*this->numerator;
        int d = this->denominator*other.denominator ;

        return Fraction(d,n);
    }

    Fraction operator-(Fraction &other){
        int n = this->denominator*other.numerator - other.denominator*this->numerator;
        int d = this->denominator*other.denominator ;

        return Fraction(d,n);
    }

    Fraction operator*(Fraction &other){
        int n = other.numerator*this->numerator;
        int d = this->denominator*other.denominator ;

        return Fraction(d,n);
    }

    Fraction operator/(Fraction &other){
        int n = this->numerator*this->denominator;
        int d = other.denominator*other.numerator ;

        return Fraction(d,n);
    }

    bool operator==(Fraction &other){
        bool flag = false;
        if(this->decimalValue() == other.decimalValue()){
            return true;
        }
        
        return false;
    }

    bool operator!=(Fraction &other){
        bool flag = false;
        if(this->decimalValue() != other.decimalValue()){
            return true;
        }
        
        return false;
    }

    bool operator<(Fraction &other){
        bool flag = false;
        if(this->decimalValue() < other.decimalValue()){
            return true;
        }
        
        return false;
    }

    bool operator>(Fraction &other){
        bool flag = false;
        if(this->decimalValue() > other.decimalValue()){
            return true;
        }
        
        return false;
    }


    









};


int main(){


try{
    Fraction f1(2,53);
    try{
        f1.setdeno(5);

    }
    catch(int e){
        cout<<"Enter non Zero Value";
    }

    f1.decimalValue();
    f1.lowestFraction();
}
catch(int error){
    cout<<"Enter non Zero Value";
}
Fraction f2;






    return 0;
}