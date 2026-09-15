class Manager {
    void manage() {
        System.out.println("Manager is managing");
    }
}

class Employee {
    void workWith(Manager manager) {
        manager.manage();
    }
}

public class Main {
    public static void main(String[] args) {
        Manager manager = new Manager();
        Employee employee = new Employee();

        employee.workWith(manager);
    }
}