/*
BankingService Interface --> Acts as an interface for the outside world
to perform banking operations.

This interface tells WHAT banking operations are available
rather than HOW those operations are performed.

The outside world only needs to know that it can:

    deposit()
    withdraw()
    transferMoney()
    checkBalance()

It does NOT need to know the internal implementation of these operations.

For example, when a customer transfers money, they don't need to know:

    - How the database is updated
    - How the sender's balance is checked
    - How the receiver's balance is updated
    - How the transaction is recorded
    - How fraud detection works
    - How rollback happens if something fails

All of those implementation details are hidden behind
this interface.

Since this is an interface, we cannot directly create an object
of BankingService.

A concrete class must implement it and provide the actual
implementation of these operations.
*/
interface BankingService {

    void deposit(double amount);

    void withdraw(double amount);

    void transferMoney(String receiverAccount, double amount);

    double checkBalance();
}

/*
This is a Concrete class.

It provides the actual implementation details of the
BankingService interface.

The interface told us WHAT banking operations are available.

BankAccountService tells us HOW those operations are performed.

For example, transferMoney() actually performs the required
operations internally.

The outside world does not need to know these implementation details.
It simply calls transferMoney().
*/

class BankAccountService implements BankingService {

    String accountNumber;
    double balance;

    public BankAccountService(String accountNumber, double balance) {
        this.accountNumber = accountNumber;
        this.balance = balance;
    }

    @Override
    public void deposit(double amount) {

        balance += amount;

        System.out.println(
            "Deposited ₹" + amount +
            " | Current Balance: ₹" + balance
        );
    }

    @Override
    public void withdraw(double amount) {

        if (amount > balance) {
            System.out.println("Insufficient balance.");
            return;
        }

        balance -= amount;

        System.out.println(
            "Withdrawn ₹" + amount +
            " | Current Balance: ₹" + balance
        );
    }

    @Override
    public void transferMoney(String receiverAccount, double amount) {

        if (amount > balance) {
            System.out.println("Insufficient balance.");
            return;
        }

        balance -= amount;

        System.out.println(
            "Transferred ₹" + amount +
            " to account " + receiverAccount +
            " | Current Balance: ₹" + balance
        );
    }

    @Override
    public double checkBalance() {

        return balance;
    }
}

public class Abstraction {

    public static void main(String[] args) {

        BankingService account =
            new BankAccountService("ACC123", 10000);

        account.deposit(2000);

        account.withdraw(1000);

        account.transferMoney("ACC456", 3000);

        System.out.println(
            "Final Balance: ₹" + account.checkBalance()
        );
    }
}