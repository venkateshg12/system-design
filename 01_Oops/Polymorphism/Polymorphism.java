/*
Polymorphism means "many forms".

We know that in a company, different types of employees can perform
the same type of operation but the actual behaviour can be different.

For example, all employees can work, but a Developer works by writing
code while a Designer works by designing UI.

We represent this scenario in programming by defining a common method
in the parent class and overriding that method in different child classes.

When a parent class reference refers to a child class object and the
overridden method is called, the child class implementation is executed.

This is called Runtime Polymorphism.

Polymorphism can also happen through method overloading, where multiple
methods have the same name but different parameters.

This is called Compile-time Polymorphism.
*/


class Employee {

    protected String name;
    protected String employeeId;
    protected String department;

    public Employee(
            String name,
            String employeeId,
            String department) {

        this.name = name;
        this.employeeId = employeeId;
        this.department = department;
    }

    // Common method for all employees.
    public void login() {
        System.out.println(
                name + " : Logged into the company system."
        );
    }

    /*
    This method will be overridden by child classes.

    Developer and Designer can have different implementations
    of the same work() method.

    This is Runtime Polymorphism.
    */
    public void work() {
        System.out.println(
                name + " : Employee is working."
        );
    }

    /*
    Method Overloading.

    Same method name but different parameters.

    This is Compile-time Polymorphism.
    */
    public void work(int hours) {
        System.out.println(
                name + " : Employee worked for " +
                hours + " hours."
        );
    }

    public void logout() {
        System.out.println(
                name + " : Logged out of the company system."
        );
    }
}


/*
Developer is a child class of Employee.

Developer inherits the common functionality of Employee
and overrides the work() method with its own implementation.

Developer works by writing and debugging code.

This demonstrates Runtime Polymorphism.
*/
class Developer extends Employee {

    private final String programmingLanguage;

    public Developer(
            String name,
            String employeeId,
            String department,
            String programmingLanguage) {

        super(name, employeeId, department);
        this.programmingLanguage = programmingLanguage;
    }

    // Overriding work() - Runtime Polymorphism.
    @Override
    public void work() {
        System.out.println(
                name + " : Developer is writing code using " +
                programmingLanguage
        );
    }

    // Specialized method for Developer.
    public void debugCode() {
        System.out.println(
                name + " : Debugging the application."
        );
    }
}


/*
Designer is another child class of Employee.

Designer also overrides the work() method, but its implementation
is different from Developer.

This demonstrates Runtime Polymorphism.
*/
class Designer extends Employee {

    private final String designTool;

    public Designer(
            String name,
            String employeeId,
            String department,
            String designTool) {

        super(name, employeeId, department);
        this.designTool = designTool;
    }

    // Overriding work() - Runtime Polymorphism.
    @Override
    public void work() {
        System.out.println(
                name + " : Designer is designing UI using " +
                designTool
        );
    }

    // Specialized method for Designer.
    public void createPrototype() {
        System.out.println(
                name + " : Creating a UI prototype."
        );
    }
}


// Main Class
public class Polymorphism {

    public static void main(String[] args) {

        /*
        Compile-time Polymorphism.

        Same work() method name but different parameters.

        The compiler decides which method to call based on
        the arguments passed.

        Hence this is Compile-time Polymorphism.
        */

        Employee employee = new Employee(
                "Rahul",
                "EMP101",
                "Engineering"
        );

        employee.work();
        employee.work(8);


        System.out.println("----------------------");


        /*
        Runtime Polymorphism.

        Parent class reference is referring to a Developer object.

        Although the reference type is Employee, the actual object
        is Developer.

        Therefore, Developer's overridden work() method is executed.
        */

        Employee developer = new Developer(
                "Venkatesh",
                "DEV101",
                "Engineering",
                "Java"
        );

        developer.login();

        developer.work(); // Developer's work() is called.

        developer.logout();


        System.out.println("----------------------");


        /*
        Runtime Polymorphism.

        Parent class reference is referring to a Designer object.

        Although the reference type is Employee, the actual object
        is Designer.

        Therefore, Designer's overridden work() method is executed.
        */

        Employee designer = new Designer(
                "Rahul",
                "DES201",
                "Design",
                "Figma"
        );

        designer.login();

        designer.work(); // Designer's work() is called.

        designer.logout();
    }
}