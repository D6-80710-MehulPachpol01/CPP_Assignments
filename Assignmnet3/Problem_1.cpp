#include<iostream>

using namespace std;


class Cylinder{


    float height;
    float radius;
    const double pi = 3.14;

    public:

    Cylinder(float height,float radius):height(height),radius(radius){

    }

    void setHeight(float height){

        this->height = height;
    }

    void setRadius(float radius){

        this->radius  = radius;
    }

    float getHeight(){

        return this->height;
    }

    float getRadius(){

        return this->radius;
    }

    void calculateArea(){
        cout<< "Area of Cylinder: "<<(this->pi * this->radius*this->radius*height)<<" cubic meter" <<endl;
    }

};


int main(){


    cout<<"Enter Height"<<endl;
    cout<<"Enter Radius"<<endl;
    float ht,rad;


    Cylinder c1(ht,rad);
    c1.calculateArea();




    return 0;
}