#include <iostream>
using namespace std;

class Box{

    private:
    int height;
    int width;
    int length;


    public:

    Box(){
        height =3;
        width = 4;
        length = 5;
    }

    void setHeight(int h){
        height = h;
    }

    int getHeight(){
        return height;
    }

    void setwidth(int w){
        width = w;
    }

    int getwidth(){
        return width;
    }

    void setlength(int l){
        length = l;
    }



    int getlength(){
        return length;
    }


    void calculateArea(){
        cout<<"Area of box: "<<length*width*height<<endl;
    }


    void displayDimension(){
        cout<<"Dimensions of the box are: "<<endl; 
        cout<<"height: "<<getHeight()<<endl;
        cout<<"width: "<<getwidth()<<endl;
        cout<<"length: "<<getlength()<<endl;
    }

    void setDimension(){
        int l;
            int h;
            int w;
            cout<<"Enter length: ";
            cin>>l;
            setlength(l);
            cout<<"Enter height: ";
            cin>>h;
            setHeight(h);
            cout<<"Enter width: ";
            cin>>w;
            setwidth(l);
    }

};

int menu(){
    int choice;

    cout<<"0:Exit"<<endl;
    cout<<"1:Enter the dimensions: "<<endl;
    cout<<"2:Show Dimensions of box: "<<endl;
    cout<<"3:Calculate area of box:"<<endl;

    cout<<"Enter your choice: ";
    cin>>choice;
    return choice;
}





int main(){

    Box b1;

    int opt;

    while((opt=menu())!=0){

        switch(opt){
            case 1:
            b1.setDimension();
            break;
            case 2:
            b1.displayDimension();
            break;
            case 3:
            b1.calculateArea();
            break;

            default:
            cout<<"Invalid input"<<endl;
        }

        cout<<"Thank you"<<endl;

    }




    return 0;
}