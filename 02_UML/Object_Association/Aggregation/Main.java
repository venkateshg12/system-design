import java.util.List;

class Employee {
    private String name;

    Employee(String name) {
        this.name = name;
    }
}

class Department {
    private List<Employee> employees;

    Department(List<Employee> employees) {
        this.employees = employees;
    }
}

public class Main {
    public static void main(String[] args) {

        Employee e1 = new Employee("Alice");
        Employee e2 = new Employee("Bob");

        List<Employee> employees = new ArrayList<>();

        employees.add(e1);
        employees.add(e2);

        Department department = new Department(employees);

        // Department uses/groups employees.
        // But employees were created independently.
    }
}