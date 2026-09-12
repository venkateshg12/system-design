#include <iostream>
#include <string>

using namespace std;

/*
Encapsulation says 2 things:
1. An Object's Characteristics and its behaviour are encapsulated together
within that Object.
2. All the characteristics or behaviours are not for everyone to access.
Object should provide data security.

We follow above 2 pointers about Object of real world in programming by:
1. Creating a class that act as a blueprint for Object creation. Class contain
all the characteristics (class variable) and behaviour (class methods) in one block,
encapsulating it together.
2. We introduce access modifiers (public, private, protected) etc to provide data
security to the class members.

In our real world example of Banking System, the characteristics of a bank
account such as accountNumber and balance, and its behaviours such as
deposit(), withdraw(), transferMoney() and checkBalance() are encapsulated
together inside the BankAccountService class.

However, sensitive characteristics like accountNumber and balance should not
be directly accessible or modifiable by everyone.

Therefore, we make them private and provide controlled public methods to
access or modify them.
*/

class BankAccountService
{
private:
    string accountNumber;
    double balance;

    /*
    These characteristics are private.

    This means that code outside this class cannot directly access or modify
    accountNumber and balance.

    For example:

        account->balance = 500000;       // Not allowed
        account->accountNumber = "...";  // Not allowed

    Instead, the outside world must use the public methods provided by
    this class to interact with this data.

    This is how we provide data security to the object's internal state.
    */

public:

    BankAccountService(string accountNumber, double balance)
    {
        this->accountNumber = accountNumber;
        this->balance = balance;
    }

    /*
    Getter method for accountNumber.

    Since accountNumber is private, the outside world cannot directly access it.

    We provide this getter method to allow the outside world to READ the
    accountNumber in a controlled way.
    */
    string getAccountNumber()
    {
        cout << accountNumber << endl;
        return accountNumber;
    }

    double getBalance()
    {
        cout << balance << endl;
        return balance;
    }

    /*
    Setter method for accountNumber.

    A setter allows the outside world to MODIFY a private variable through
    a controlled public method.

    Instead of directly doing:

        account->accountNumber = "ACC456";    // Not allowed

    We can do:

        account->setAccountNumber("ACC456");

    This gives the class control over how its internal data is modified.
    */
    void setAccountNumber(string accountNumber)
    {
        this->accountNumber = accountNumber;
    }

    
    void deposit(double amount)
    {
        balance += amount;

        cout << "Deposited ₹" << amount<< " | Current Balance: ₹" << balance << endl;
    }

    void withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient balance." << endl;
            return;
        }

        balance -= amount;
        cout << "Withdrawn ₹" << amount << " | Current Balance: ₹" << balance << endl;
    }

    
    void transferMoney(string receiverAccount, double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient balance." << endl;
            return;
        }

        balance -= amount;
        cout << "Transferred ₹" << amount << " to account " << receiverAccount << " | Current Balance: ₹" << balance << endl;
    }

    double checkBalance()
    {
        return balance;
    }

};


int main()
{

    BankAccountService *account = new BankAccountService("ACC123", 10000);

    account->getAccountNumber();
    account->getBalance();

    /*
    We can perform banking operations through public methods.

    The methods themselves control how the private balance is modified.
    */

    account->deposit(2000);

    account->withdraw(2000);

    account->transferMoney("ACC456", 2000);


    cout << "Current Balance: ₹"<< account->checkBalance() << endl;


    account->setAccountNumber("ACC456");

    cout << "Updated Account Number: "<< account->getAccountNumber() << endl;

    /*
    delete is used to destroy an object that was dynamically allocated using new
    and release its associated memory.

    Java doesn't require delete because memory is managed automatically by the
    Garbage Collector.

        new BankAccountService(...)
                ↓
          Object created
                ↓
             Use object
                ↓
          delete account
                ↓
        Destructor called
                ↓
          Memory released
    */

    delete account;

    return 0;
}