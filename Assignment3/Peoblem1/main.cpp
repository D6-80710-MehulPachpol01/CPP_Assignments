
#include "cylinder.h"


int main(){


    cout<<"Enter Height"<<endl;
    cout<<"Enter Radius"<<endl;
    float ht,rad;
    cin>>ht;
    cin>>rad;


    Cylinder c1(ht,rad);
    c1.calculateArea();





    return 0;
}