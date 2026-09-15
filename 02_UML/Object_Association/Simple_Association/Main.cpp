#include <iostream>
using namespace std;

class Manager {
public:
    void manage() {
        cout << "Manager is managing\n";
    }
};

class Employee {
public:
    void workWith(Manager& manager) {
        manager.manage();
    }
};

int main() {
    Manager manager;
    Employee employee;

    employee.workWith(manager);
}