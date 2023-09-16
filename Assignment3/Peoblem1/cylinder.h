#ifndef CYLINDER_H
#define CYLINDER_H

#include<iostream>

using namespace std;


class Cylinder{


    float height;
    float radius;
    const double pi = 3.14;

    public:

    Cylinder(float height,float radius);

    void setHeight(float height)  ;

    void setRadius(float radius) ;

    float getHeight();

    float getRadius();

    void calculateArea();

};

#endif 
