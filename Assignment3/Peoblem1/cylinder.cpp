
#include "cylinder.h"

Cylinder :: Cylinder(float height,float radius):height(height),radius(radius){}

    void Cylinder :: setHeight(float height) {

        this->height = height;
    }

    void Cylinder :: setRadius(float radius){

        this->radius  = radius;
    }

    float Cylinder :: getHeight(){

        return this->height;
    }

    float Cylinder :: getRadius(){

        return this->radius;
    }

    void  Cylinder :: calculateArea(){
        cout<< "Area of Cylinder: "<<(this->pi * this->radius*this->radius*height)<<" cubic meter" <<endl;
    }
