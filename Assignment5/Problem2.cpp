#include <iostream>
using namespace std;


class Stack{
private:
int size;
int top = -1;
int *arr;


public:
Stack(){
this->size = 5;
arr = new int[this->size];
}

//Copy Constructor

    Stack(const Stack& other) {
        size = other.size;
        top = other.top;
        arr = new int[size];
        for (int i = 0; i <= top; i++) {
            arr[i] = other.arr[i];
        }
    }

//operator overloading 
 
    Stack& operator=(const Stack& other) {
        if (this == &other) {
            return *this; 
        }
        delete[] arr;

        size = other.size;
        top = other.top;
        arr = new int[size];
        for (int i = 0; i <= top; i++) {
            arr[i] = other.arr[i];
        }

        return *this; 
    }

    ~Stack() {
        delete[] arr;
    }


Stack(int size){
this->size =size;
arr = new int[this->size];


}




void push(){
if(isFull()){
cout<<"Stack is full"<<endl;


}
else{
int ele;
cout<<"Enter the element: "<<endl;
cin>>ele;
top++;
arr[top] = ele;


}
cout<<"------------------------------------------"<<endl;
}
void pop(){
if(isEmpty()){
cout<<"Stack is Empty"<<endl;
}
else{
top--;
}
cout<<"------------------------------------------"<<endl;


}
void peek(){
if(isEmpty()){
cout<<"Stack is Empty"<<endl;
}
else{
cout<<arr[top]<<endl;
}
cout<<"------------------------------------------"<<endl;




}
bool isEmpty(){


if(top==-1){
return true;
}
else{
return false;
}


}
bool isFull(){
if(top==(size-1)){
return true;
}
else{
return false;
}


}
void print(){
cout<<"Elements of stack are: "<<endl;
for(int i=top;i>=0;i--){
cout<<arr[i]<<" ";
}
cout<<endl;
cout<<"------------------------------------------"<<endl;


}
};


int menu(){
int choice;

cout<<"Select the operation on stack:"<<endl;
cout<<"0:EXIT"<<endl<<"1:PUSH"<<endl<<"2:POP"<<endl;
cout<<"3:PEEK"<<endl<<"4:IsEmpty"<<endl<<"5:IsFull"<<endl;
cout<<"6:Print"<<endl;
cout<<"Select the operation on stack:";
cin>>choice;
cout<<"------------------------------------------"<<endl;
return choice;

}

int main(){
Stack s;
Stack s1;


int opt;
while((opt=menu())!=0){
switch(opt){
case 1:
s.push();
break;
case 2:
s.pop();
break;
case 3:
s.peek();
break;


case 4:
if(s.isEmpty()){
cout<<"Stack is empty"<<endl;
}
else{
cout<<"Stack is not empty"<<endl;
}
cout<<"------------------------------------------"<<endl;
break;
case 5:
if(s.isFull()){
cout<<"Stack is Full"<<endl;
}
else{
cout<<"Stack is not Full"<<endl;
}
cout<<"------------------------------------------"<<endl;
break;
case 6:
s.print();

}
}

s1 =s;
cout<<"Copied Stack"<<endl;
s1.print();
cout<<"orignal  Stack"<<endl;
s1.pop();
s.print();
cout<<"Copied Stack"<<endl;
s1.print();


return 0;
}




