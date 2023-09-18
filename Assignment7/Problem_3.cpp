#include <iostream>
using namespace std;
enum account_type
{
    SAVING,
    CURRENT,
    DMAT
};
class insufficent_funds
{
private:
    int accno;
    double cur_balance;
    double withdraw_amount;

public:
    insufficent_funds()
    {
    }
    insufficent_funds(int id, double cbal, double wamnt)
    {
        this->accno = id;
        this->cur_balance = cbal;
        this->withdraw_amount = wamnt;
    }
    void display()
    {
        cout << "------------------------------------------------" << endl;
        cout << "Insufficent Funds" << endl;
        cout << "Id :" << this->accno << endl;
        cout << "Current balance =" << this->cur_balance << endl;
        cout << "Request amount for withdrawal =" << this->withdraw_amount << endl;
        cout << "------------------------------------------------" << endl;
    }
};
class account : public insufficent_funds
{
private:
    int id;
    account_type type;
    double balance;

public:
    account()
    {
        id = 0;
        type = SAVING;
        balance = 0.0;
    }
    account(int id, account_type type)
    {
        this->id = id;
        this->type = type;
    }
    void set_id(int id)
    {
        this->id = id;
    }
    void set_type(account_type type)
    {
        this->type = type;
    }
    int get_id()
    {
        return this->id;
    }
    account_type get_type()
    {
        return this->type;
    }
    double get_balance()
    {
        return this->balance;
    }
    void deposit(double amount)
    {
        if (amount < 0)
            throw "Error. Msg :Negative deposit ammount";
        this->balance += amount;
        cout << " Updated Balance = " << this->balance << endl;
    }
    void withdraw(double amount)
    {
        if (this->balance < amount)
            throw new insufficent_funds(this->id, this->balance, amount);
        this->balance -= amount;
    }
    void accept()
    {
        int id;
        int type;
        cout << "Enter Customer details:" << endl;
        cout << "Id:" << endl;
        cin >> id;
        this->set_id(id);
        cout << "select Account type :" << endl;
        cout << "   1.Savings Account" << endl;
        cout << "   2.Current Account" << endl;
        cout << "   3.DMAT Account" << endl;
        cin >> type;
        this->set_type((account_type)type);
        cout << "Enter current balance :" << endl;
        cin >> this->balance;
    }
    void display()
    {
        cout << "------------------------------------------------" << endl;
        cout << "Customer id:" << this->id << endl;
        cout << "Account type:" << this->type << endl;
        cout << "Current balance: " << this->balance << endl;
        cout << "------------------------------------------------" << endl;
    }
};
int menu()
{
    int ch;
    cout << "Enter a choice:" << endl;
    cout << "1.Store Account details" << endl;
    cout << "2.Withdraw" << endl;
    cout << "3.Deposit" << endl;
    cout << "4.Display account details" << endl;
    cout << "0.Exit" << endl;
    cin >> ch;
    return ch;
}
int main()
{
    int ch, id, flag = 0, i = 0, num = 5;
    account *array[num];
    double amount;
    while ((ch = menu()) != 0)
    {
        switch (ch)
        {
        case 1:
            if (i < 5)
            {
                array[i] = new account;
                array[i]->accept();
                array[i]->display();
                i++;
                flag = 1;
            }
            else
                cout << "Cant store anymore details." << endl;
            break;
        case 2:
            cout << "Enter account id" << endl;
            cin >> id;
            for (int j = 0; j < i; j++)
            {
                if (id == (array[j]->get_id()))
                {
                    cout << "Enter the ammount to be withdrawn." << endl;
                    cin >> amount;
                    array[j]->withdraw(amount);
                    flag = 1;
                }
            }
            break;
        case 3:
            cout << "Enter account id" << endl;
            cin >> id;
            for (int j = 0; j < i; j++)
            {
                if (id == (array[j]->get_id()))
                {
                    cout << "Enter the ammount to be deposited." << endl;
                    cin >> amount;
                    array[j]->deposit(amount);
                    flag = 1;
                }
            }
            break;
        case 4:
            cout << "Enter account id" << endl;
            cin >> id;
            for (int j = 0; j < i; j++)
            {
                if (id == (array[j]->get_id()))
                {
                    array[j]->display();
                    flag = 1;
                }
            }
            break;
        }
        if (flag == 0)
        {
            cout << "Error: Msg->Invalid acount id" << endl;
        }
    }
    
}