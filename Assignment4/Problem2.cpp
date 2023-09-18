
#include <iostream>
using namespace std;

class Employee {
private:
    int id;
    float sal;

public:
    Employee() {
        this->id = 0;
        this->sal = 0;
    }

    Employee(int id, float sal) {
        this->id = id;
        this->sal = sal;
    }

    int getId() const {
        return this->id;
    }

    float getSal() const {
        return this->sal;
    }

    void setId(int id) {
        this->id = id;
    }

    void setSal(float sal) {
        this->sal = sal;
    }

    void accept() {
        cout << "Enter ID" << endl;
        cin >> this->id;

        cout << "Enter Salary" << endl;
        cin >> this->sal;
    }

    void Display() {
        cout << "ID: " << this->id << endl;
        cout << "Salary: " << this->sal << endl;
    }
};

class Manager : virtual public Employee {
private:
    float bonus;

public:
    Manager() {
        this->bonus = 0;
    }

    Manager(float bonus, int id, float sal) : Employee(id, sal) {
        this->bonus = bonus;
    }

    void setBonus(float bonus) {
        this->bonus = bonus;
    }

    float getBonus() {
        return this->bonus;
    }

    void Display_Manager() {
        cout << "The bonus is: " << this->bonus << endl;
    }
};

class Salesman : virtual public Employee {
private:
    int sale;

public:
    Salesman() {
        this->sale = 0;
    }

    Salesman(int sale, int id, float sal) : Employee(id, sal) {
        this->sale = sale;
    }

    int getSale() {
        return this->sale;
    }

    void setSale(int sale) {
        this->sale = sale;
    }

    void Display_Salesman() {
        cout << "The sale is: " << this->sale << endl;
    }

    void Accept_Salesman() {
        cout << "Enter sales :" << endl;
        cin >> this->sale;
    }
};

class SalesManager : public Manager, public Salesman {
public:
    SalesManager() : Manager(), Salesman() {}

    SalesManager(int sale, int id, float sal, float bonus) : Manager(bonus, id, sal), Salesman(sale, id, sal) {}
};

int main() {
    SalesManager s1(1, 1, 1, 1);
   
    s1.accept();
    s1.Accept_Salesman();
    s1.Display();
    s1.Display_Salesman();
    s1.getId();
    s1.setId(888);
    s1.getId();

    return 0;
}
