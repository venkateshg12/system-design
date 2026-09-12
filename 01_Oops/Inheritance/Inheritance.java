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
and define only those characteristics and behaviours that are specific to
them.

Although objects of these child classes can access or call parent class
characteristics (variables) and behaviours (methods).

Hence providing code reusability.
*/

class Employee {

    protected String name;
    protected String employeeId;
    protected String department;

    public Employee(String name, String employeeId, String department) {
        this.name = name;
        this.employeeId = employeeId;
        this.department = department;
    }

    // Common methods for all employees
    public void login() {
        System.out.println(name + " : Logged into the company system.");
    }

    public void logout() {
        System.out.println(name + " : Logged out of the company system.");
    }

    public void attendMeeting() {
        System.out.println(name + " : Attending the meeting.");
    }

    public void displayEmployeeDetails() {
        System.out.println(
                "Employee ID: " + employeeId +
                " | Name: " + name +
                " | Department: " + department
        );
    }
}


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
specialized behaviour such as writeCode().

This is inheritance because Developer IS-A Employee.
*/

class Developer extends Employee {

    private final String programmingLanguage; // Specific to Developer.

    public Developer(
            String name,
            String employeeId,
            String department,
            String programmingLanguage) {

        super(name, employeeId, department);
        this.programmingLanguage = programmingLanguage;
    }

    // Specialized method for Developer
    public void writeCode() {
        System.out.println(
                name + " : Writing code using " +
                programmingLanguage
        );
    }

    public void debugCode() {
        System.out.println(
                name + " : Debugging the application."
        );
    }
}


/*
Designer is another child class of Employee.

Designer also automatically gets all the common characteristics
and behaviours of Employee.

But Designer has its own specialized behaviours such as:

    designUI()
    createPrototype()

This allows us to reuse the common Employee code instead of
writing login(), logout(), attendMeeting() etc again.

This is inheritance because Designer IS-A Employee.
*/


class Designer extends Employee {

    private final String designTool; // Specific to Designer.

    public Designer(
            String name,
            String employeeId,
            String department,
            String designTool) {

        super(name, employeeId, department);

        this.designTool = designTool;
    }

    // Specialized method for Designer
    
    public void designUI() {
        System.out.println(
                name + " : Designing UI using " +
                designTool
        );
    }

    public void createPrototype() {
        System.out.println(
                name + " : Creating a UI prototype."
        );
    }
}


// Main Class
public class Inheritance {

    public static void main(String[] args) {

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

        Developer developer = new Developer(
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


        System.out.println("----------------------");


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

        Designer designer = new Designer(
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
    }
}

