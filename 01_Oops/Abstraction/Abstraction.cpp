#include <string>
#include <iostream>

using namespace std;

/*
Abstract class -->
1. Acts as an interface for the outside world to perform banking operations.
2. This abstract class tells 'WHAT' all it can do rather than 'HOW' it does that.
3. Since this is an abstract class we cannot directly create Objects of this class.
4. We need to Inherit it first and then that child class will have the responsibility to
provide implementation details of all the abstract (pure virtual) methods in the class.

5. In our real world example of Banking System, imagine you are using a banking
application and able to perform banking operations like deposit, withdraw,
transfer money and check balance by simply using buttons/options provided by
the application. You don't need to know how these operations work internally,
and all those implementation details are hidden behind the banking service.

6. This Class 'BankingService' denotes that user-facing interface/operations
like deposit, withdraw, transfer money and check balance.
*/


class BankingService
{
public:

    /*
    virtual function :- A virtual function allows C++ to decide at runtime which overridden
    function should be called based on the actual object, rather than the reference/pointer type.

    virtual :- virtual declares a virtual function that can be overridden by a derived class.

    = 0 :- This is a pure virtual function. The base class does not provide an implementation,
    and derived concrete classes are required to implement it.
    */

    /* if write the methods without virtual then the parent class reference or pointer will be executed
        rather than the actual child class object which we wrttien with keyword "new";
    */

    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual void transferMoney(string receiverAccount, double amount) = 0;
    virtual double checkBalance() = 0;

    virtual ~BankingService() {} // destructor

    /*
    When an object of a derived class is deleted through a base-class pointer, if the base
    destructor is virtual, the derived-class destructor is called first, followed by the
    base-class destructor. If the base destructor is not virtual, deleting the derived object
    through the base pointer results in undefined behavior.
    */

    /*
    Runtime polymorphism is an OOP mechanism in which a parent class reference or pointer can refer 
    to a child class object, and the overridden method of the actual object is selected and executed at runtime.
    */
};

/*
1. This is a Concrete class (A class that provides implementation details of an abstract class).
Now anyone can make an Object of 'BankAccountService' and can assign it to
'BankingService' (Parent class) pointer (See main method for this).

2. In our real world example of Banking System, the abstract class only tells us
WHAT banking operations are available, such as deposit, withdraw, transferMoney
and checkBalance.

But we need an actual class that provides the implementation of WHAT happens
when we perform these operations.

'BankAccountService' class denotes that actual implementation.

For example:
    - deposit() actually adds money to the balance.
    - withdraw() checks the balance and removes money.
    - transferMoney() checks the balance and deducts the transferred amount.
    - checkBalance() returns the current balance.

3. Therefore, to represent a banking service in programming we created 2 classes.

One class to denote all the operations available to the outside world
('BankingService' abstract class).

And another class to denote the actual implementation of all those operations
('BankAccountService' concrete class).

*/
class BankAccountService : public BankingService
{
public:
    string accountNumber;
    double balance;

    BankAccountService(string accountNumber, double balance)
    {
        this->accountNumber = accountNumber;
        this->balance = balance;
    }

    void deposit(double amount)
    {
        balance += amount;

        cout << "Deposited ₹" << amount
             << " | Current Balance: ₹" << balance
             << endl;
    }

    void withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient balance" << endl;
            return;
        }

        balance -= amount;

        cout << "Withdrawn ₹" << amount
             << " | Current Balance: ₹" << balance
             << endl;
    }

    void transferMoney(string receiverAccount, double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient balance." << endl;
            return;
        }

        balance -= amount;

        cout << "Transferred ₹" << amount
             << " to account " << receiverAccount
             << " | Current Balance: ₹" << balance
             << endl;
    }

    double checkBalance()
    {
        return balance;
    }
};

int main()
{
    /*
    Here we are creating an object of 'BankAccountService' but storing its
    address in a 'BankingService' (Parent class) pointer.

    BankingService* account
            ↓
       Parent pointer

    new BankAccountService(...)
            ↓
       Actual child object

    This is possible because BankAccountService inherits from BankingService.

    The outside world interacts with the object through the 'BankingService'
    interface rather than directly depending on the implementation details
    of 'BankAccountService'.

    This is one of the important benefits of Abstraction and Polymorphism.
    */

    BankingService *account = new BankAccountService("ACC123", 10000);

    account->deposit(2000);

    account->withdraw(2000);

    account->transferMoney("ACC456", 2000);

    account->checkBalance();

    /*
    delete is used to destroy an object that was dynamically allocated using new
    and release its associated memory.

    Java doesn't require delete because memory is managed automatically by the
    Garbage Collector.
    */

    delete account;

    return 0;
}