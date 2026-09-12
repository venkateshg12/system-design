#include <iostream>
#include <string>

using namespace std;

/*
We know that real world Objects show inheritance relationship where we
have a parent object and child objects. A child object has all the
characteristics or behaviours that the parent has, plus some additional
characteristics/behaviours that are specific to that child.

For example, in a company, all employees have common information such as
name, employeeId, department etc and can perform common behaviours such as
login, logout and attendMeeting.

But some specific employees like Developers have programming-related
behaviours such as writeCode(), while Designers have design-related
behaviours such as designUI().

We represent this scenario of real world in programming by creating a
parent class and defining all the characteristics (variables) or behaviours
(methods) that all employees have in the parent class.

Then we create different child classes that inherit from this parent class
and define only those characteristics and behaviours that are specific
to them.

Although objects of these child classes can access or call parent class
characteristics (variables) and behaviours (methods).

Hence providing code reusability.
*/

class Employee
{
protected:
    string name;
    string employeeId;
    string department;

public:

    Employee(string name, string employeeId, string department)
    {
        this->name = name;
        this->employeeId = employeeId;
        this->department = department;
    }

    // Common methods for all employees.

    void login()
    {
        cout << name << " : Logged into the company system." << endl;
    }

    void logout()
    {
        cout << name << " : Logged out of the company system." << endl;
    }

    void attendMeeting()
    {
        cout << name << " : Attending the meeting." << endl;
    }

    void displayEmployeeDetails()
    {
        cout << "Employee ID: " << employeeId
             << " | Name: " << name
             << " | Department: " << department << endl;
    }

    virtual ~Employee() {}
};


/*
Developer is a child class of Employee.

A Developer automatically gets all the common characteristics and
behaviours of Employee such as:

    name
    employeeId
    department
    login()
    logout()
    attendMeeting()
    displayEmployeeDetails()

In addition to these common things, Developer has its own
specialized behaviours such as writeCode() and debugCode().

This is inheritance because Developer IS-A Employee.

Since Developer inherits from Employee, we don't have to write the
common Employee code again.

Hence providing code reusability.
*/
class Developer : public Employee
{
private:
    string programmingLanguage; // Specific to Developer.

public:

    Developer(
        string name,
        string employeeId,
        string department,
        string programmingLanguage
    ) : Employee(name, employeeId, department)
    {
        this->programmingLanguage = programmingLanguage;
    }

    // Specialized method for Developer.

    void writeCode()
    {
        cout << name << " : Writing code using "
             << programmingLanguage << endl;
    }

    void debugCode()
    {
        cout << name << " : Debugging the application."
             << endl;
    }
};


/*
Designer is another child class of Employee.

Designer also automatically gets all the common characteristics
and behaviours of Employee such as:

    name
    employeeId
    department
    login()
    logout()
    attendMeeting()
    displayEmployeeDetails()

In addition to these common things, Designer has its own
specialized behaviours such as designUI() and createPrototype().

This allows us to reuse the common Employee code instead of
writing login(), logout(), attendMeeting() etc again.

This is inheritance because Designer IS-A Employee.

Hence providing code reusability.
*/
class Designer : public Employee
{
private:
    string designTool; // Specific to Designer.

public:

    Designer(
        string name,
        string employeeId,
        string department,
        string designTool
    ) : Employee(name, employeeId, department),
        designTool(designTool)
    {
    }

    // Specialized method for Designer.

    void designUI()
    {
        cout << name << " : Designing UI using "
             << designTool << endl;
    }

    void createPrototype()
    {
        cout << name << " : Creating a UI prototype."
             << endl;
    }
};


// Main Function
int main()
{

    /*
    Creating an Object of Developer.

    Developer gets the common functionality from Employee:

        login()
        logout()
        attendMeeting()
        displayEmployeeDetails()

    Developer also has its own specialized functionality:

        writeCode()
        debugCode()
    */

    Developer developer(
        "Venkatesh",
        "DEV101",
        "Engineering",
        "Java"
    );

    developer.displayEmployeeDetails();

    developer.login();          // Inherited from Employee
    developer.attendMeeting();  // Inherited from Employee
    developer.writeCode();      // Specific to Developer
    developer.debugCode();      // Specific to Developer
    developer.logout();         // Inherited from Employee


    cout << "----------------------" << endl;


    /*
    Creating an Object of Designer.

    Designer gets the common functionality from Employee:

        login()
        logout()
        attendMeeting()
        displayEmployeeDetails()

    Designer also has its own specialized functionality:

        designUI()
        createPrototype()
    */

    Designer designer(
        "Rahul",
        "DES201",
        "Design",
        "Figma"
    );

    designer.displayEmployeeDetails();

    designer.login();           // Inherited from Employee
    designer.attendMeeting();   // Inherited from Employee
    designer.designUI();        // Specific to Designer
    designer.createPrototype(); // Specific to Designer
    designer.logout();          // Inherited from Employee

    return 0;
}