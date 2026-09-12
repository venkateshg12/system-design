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

2. We introduce access modifiers (public, private, protected, default) etc to provide data
security to the class members.

In our real world example of Banking System, imagine a bank account having
characteristics like accountNumber and balance, and behaviours like deposit(),
withdraw(), transferMoney() and checkBalance().

All these characteristics and behaviours belong to the same BankAccountService
object, so they are encapsulated together within that Object.

But we should not allow everyone to directly access or modify sensitive data
like balance and accountNumber.

For example, we should NOT allow someone to do:

    account.balance = -50000;

Instead, we make balance private and provide controlled methods like
deposit(), withdraw() and checkBalance() to access or modify it.

This provides data security and prevents the outside world from directly
changing the internal state of the object.
*/
class BankAccountService {

    // These variables are private so they cannot be directly accessed
    // or modified from outside this class.
    private String accountNumber;
    private double balance;

    public BankAccountService(String accountNumber, double balance) {
        this.accountNumber = accountNumber;
        this.balance = balance;
    }

    /*
    Getter method -->

    Since accountNumber and balance are private, the outside world
    cannot directly access them.

    We provide getter methods to allow controlled access to this data.

    getBalance() allows the outside world to READ the current balance.
    */

    public double getBalance() {
        System.out.println(balance);
        return balance;
    }

    /*
    Getter method for accountNumber.

    It allows the outside world to READ the account number without
    directly accessing the private variable.
    */

    public String getAccountNumber() {
        System.out.println(accountNumber);
        return accountNumber;
    }

    /*
    Setter method -->

    A setter allows the outside world to MODIFY a private variable
    through a controlled method.

    Instead of directly doing:

        account.accountNumber = "ACC456";   // Not allowed

    We provide:

        account.setAccountNumber("ACC456");

    This gives the class control over how its internal data is modified.
    */

    public void setAccountNumber(String accountNumber) {
        this.accountNumber = accountNumber;
    }


    public void deposit(double amount) {

        balance += amount;

        System.out.println("Deposited ₹" + amount +" | Current Balance: ₹" + balance);
    }

    public void withdraw(double amount) {

        if (amount > balance) {
            System.out.println("Insufficient balance.");
            return;
        }

        balance -= amount;
        System.out.println(    "Withdrawn ₹" + amount +" | Current Balance: ₹" + balance);
    }


    public void transferMoney(String receiverAccount, double amount) {

        if (amount > balance) {
            System.out.println("Insufficient balance.");
            return;
        }

        balance -= amount;
        System.out.println("Transferred ₹" + amount +" to account " + receiverAccount + " | Current Balance: ₹" + balance);
    }

  
    public double checkBalance() {
        return balance;
    }

}

// Main Method
public class Encapsulation {

    public static void main(String[] args) {

        /*
        Creating an Object of BankAccountService.

        The object contains both:

        Characteristics:
            accountNumber
            balance

        Behaviours:
            deposit()
            withdraw()
            transferMoney()
            checkBalance()

        Therefore, the object's data and the methods that operate
        on that data are bundled together inside the class.
        */

        BankAccountService account =  new BankAccountService("ACC123", 10000);

        
        // We can access the data through public getter methods.
        

        account.getBalance();
        account.getAccountNumber();

        /*
        We can perform operations on the private balance through
        public methods.

        We CANNOT directly access balance because it is private.

        For example:

            account.balance = 500000;   // Not allowed

        Instead, we must use controlled methods:

            account.deposit(2000);
            account.withdraw(2000);
            account.transferMoney("ACC456", 2000);
        */

        account.deposit(2000);
        account.withdraw(2000);
        account.transferMoney("ACC456", 2000);

        /*
        Setting an arbitrary value directly to balance is not allowed
        because balance is private.

        account.balance = -50000;   //  Not allowed
        */

        System.out.println("Current Balance: ₹" + account.checkBalance());

        /*
        We can modify accountNumber using the setter method.

        The accountNumber itself is private, but the class provides
        a controlled way to modify it.
        */

        account.setAccountNumber("ACC456");
        System.out.println("Updated Account Number: " +account.getAccountNumber());
    }
}