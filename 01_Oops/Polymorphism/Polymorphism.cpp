#include <iostream>
#include <string>

using namespace std;

/*
Polymorphism means "many forms".

We know that in a company, different types of employees can perform
the same type of operation but the actual behaviour can be different.

For example, all employees can work, but a Developer works by writing
code while a Designer works by designing UI.

We represent this scenario in programming by defining a common method
in the parent class and overriding that method in different child classes.

When a parent class pointer refers to a child class object and the
overridden method is called, the child class implementation is executed.

This is called Runtime Polymorphism.

Polymorphism can also happen through function overloading, where multiple
functions have the same name but different parameters.

This is called Compile-time Polymorphism.
*/

class Employee
{
protected:
    string name;
    string employeeId;
    string department;

public:
    Employee(
        string name,
        string employeeId,
        string department)
    {
        this->name = name;
        this->employeeId = employeeId;
        this->department = department;
    }

    // Common method for all employees.
    void login()
    {
        cout << name
             << " : Logged into the company system."
             << endl;
    }

    /*
    This method will be overridden by child classes.

    Developer and Designer can have different implementations
    of the same work() method.

    This is Runtime Polymorphism.
    */
    virtual void work()
    {
        cout << name
             << " : Employee is working."
             << endl;
    }

    /*
    Function Overloading.

    Same function name but different parameters.

    This is Compile-time Polymorphism.
    */
    void work(int hours)
    {
        cout << name
             << " : Employee worked for "
             << hours
             << " hours."
             << endl;
    }

    void logout()
    {
        cout << name
             << " : Logged out of the company system."
             << endl;
    }

    // Virtual destructor for safe polymorphic deletion.
    virtual ~Employee() {}
};

/*
Developer is a child class of Employee.

Developer inherits the common functionality of Employee
and overrides the work() method with its own implementation.

Developer works by writing code.

This demonstrates Runtime Polymorphism.
*/
class Developer : public Employee
{
private:
    string programmingLanguage;

public:
    Developer(
        string name,
        string employeeId,
        string department,
        string programmingLanguage)
        : Employee(name, employeeId, department)
    {
        this->programmingLanguage = programmingLanguage;
    }

    // Overriding work() - Runtime Polymorphism.
    void work() override
    {
        cout << name
             << " : Developer is writing code using "
             << programmingLanguage
             << endl;
    }

    // Specialized method for Developer.
    void debugCode()
    {
        cout << name
             << " : Debugging the application."
             << endl;
    }
};

/*
Designer is another child class of Employee.

Designer also overrides the work() method, but its implementation
is different from Developer.

This demonstrates Runtime Polymorphism.
*/

class Designer : public Employee
{
private:
    string designTool;

public:
    Designer(
        string name,
        string employeeId,
        string department,
        string designTool)
        : Employee(name, employeeId, department)
    {
        this->designTool = designTool;
    }

    // Overriding work() - Runtime Polymorphism.
    void work() override
    {
        cout << name
             << " : Designer is designing UI using "
             << designTool
             << endl;
    }

    // Specialized method for Designer.
    void createPrototype()
    {
        cout << name
             << " : Creating a UI prototype."
             << endl;
    }
};

// Main Function
int main()
{

    /*
    Compile-time Polymorphism.

    Same work() function name but different parameters.

    The compiler decides which function to call based on
    the arguments passed.

    Hence this is Compile-time Polymorphism.
    */

    Employee employee(
        "Rahul",
        "EMP101",
        "Engineering");

    employee.work();
    employee.work(8);

    cout << "----------------------" << endl;

    /*
    Runtime Polymorphism.

    Parent class pointer is referring to a Developer object.

    Although the pointer type is Employee*, the actual object
    is Developer.

    Therefore, Developer's overridden work() method is executed.
    */

    Employee *developer = new Developer(
        "Venkatesh",
        "DEV101",
        "Engineering",
        "Java");

    developer->login();

    developer->work(); // Developer's work() is called.

    developer->logout();

    cout << "----------------------" << endl;

    /*
    Runtime Polymorphism.

    Parent class pointer is referring to a Designer object.

    Although the pointer type is Employee*, the actual object
    is Designer.

    Therefore, Designer's overridden work() method is executed.
    */

    Employee *designer = new Designer(
        "Rahul",
        "DES201",
        "Design",
        "Figma");

    designer->login();

    designer->work(); // Designer's work() is called.

    designer->logout();

    // Cleanup
    delete developer;
    delete designer;

    return 0;
}
