
// Q3. A shop sells book or tapes. The Book class holds id, title, author, and price; whereas Tape class 
// holds id, title, artist, and price. There is 5% discount on tapes, while 10% discount on books. 
// Assuming that each user Product 3 products (either book or tape), calculate final
// bill. The program should be menu driven and should not cause
// memory leakage.

#include<iostream>

using namespace std;


class Product{

    private:
    int id;
    string title;
    int price;

    public:
    Product(){
        this->id = 0;
        this->title = "";
        this->price = 0;
    }

    Product(int id , string title , int price){
        this->id = id;
        this->title = title;
        this->price = price;
    }

    int getPrice(){
        return this->price;
    }

    virtual void acceptData()
    {
        cout << "Enter the ID = "<<endl;
        cin >> this->id;
        cout << "Enter the title = "<<endl;
        cin >> this->title;
        cout << "Enter the price = "<<endl;
        cin >> this->price;
    }
    virtual void displayData()
    {
        cout << "ID = " << this->id<< endl;
        cout << "Title= " << this->title << endl;
        cout << "Price = " << this->price << endl;
        
    }

    virtual ~Product(){

    }


};


class Book:public Product{
    string author;
    

    public:

    Book(){
        this->author = "";
    }

    Book(int id , string title , string author , int price):Product(id,title,price) {
        
        this->author = author;
        
    }

    void acceptData(){
        Product::acceptData();
        cout<<"Enter Author :"<<endl;
        cin>>this->author;
    }

    void displayData(){
        cout<<"Author :"<<this->author<<endl;
        Product::displayData();
    }

   


};


class Tape:public Product{
    string artist;

    public:

    Tape(){
        this->artist = "";
    }

    Tape(int id , string title , string artist , int price):Product(id,title,price){
        this->artist = artist;
    }


    void acceptData(){
        Product::acceptData();
        cout<<"Enter Artist :"<<endl;
        cin>>this->artist;
    }

    void displayData(){
        cout<<"Author :"<<this->artist;
        Product::displayData();
    }


};

void calculateBill(Product arr[] ,int size){
    int total = 0;
    for(int i = 0;i<size;i++){
        cout<<"THiis is totoal"<<total<<endl;
        total += arr[i].getPrice();

    }

    cout<<"BILL"<<endl;
    cout<<"Your Total Product Amount is :"<<total<<endl;
}




enum EMainMenu
{
    EXIT,
    BOOK,
    TAPE,
    DISPLAY
};

EMainMenu menu()
{

    int choice;
    
    cout<<"0.EXIT"<<endl;
    cout<<"1.Buy Books"<<endl;
    cout<<"2.Buy Tapes"<<endl;
    cout<<"3.Display"<<endl;
    cout<<"Enter Choice"<<endl;
    cin>>choice;
    return EMainMenu(choice);
}

int main()
{
    

    EMainMenu choice;
    int prd ;
    cout<<"Enter total products"<<endl;
    cin>>prd;
    Product *ptr[prd];
    int index = 0;
    while ((choice = menu()) != EXIT)
    {
        switch (choice)
        {
        case BOOK:
           
            if (index < prd)
            {
                ptr[index] = new Book();

                 ptr[index]->acceptData();
                 index++;
             }
            break;
        case TAPE:
            if (index < prd)
                ptr[index] = new Tape();
            break;
        case DISPLAY:
            for (int i = 0; i < index; i++)
                ptr[i]->displayData();
            break;
        default:
            cout << "Wrong choice.." << endl;
            break;
        }
        // if (ptr != NULL)
        // {
        //     ptr[index]->acceptData();
        //     index++;
        // }
    }
    cout<<"Before calcBill()"<<endl;
    calculateBill(*ptr,index);
     cout<<"Before for loop"<<endl;
    for(int i = 0;i<index;i++){
        cout<<"for loop";
        delete ptr[i];
    }

    

    return 0;
}
