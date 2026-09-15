#include <iostream>
#include <vector>
using namespace std;

class Employee
{
public:
    string name;
    Employee(string name)
    {
        this->name = name;
    }
};

class Department
{
private:
    vector<Employee *> employees;

public:
    Department(vector<Employee *> employees)
    {
        this->employees = employees;
    }
};

int main()
{

    Employee e1("Alice");
    Employee e2("Bob");

    vector<Employee *> employees = {&e1, &e2};

    Department department(employees);
}

