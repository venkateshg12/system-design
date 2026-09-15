

/*

Composition is a strong whole-part relationship in which the part's lifetime 
is controlled by the whole; when the whole is destroyed, its parts are also destroyed.

*/

#include <iostream>
using namespace std;

class OrderItem {
public:
    OrderItem(string product) {
        cout << product << " created\n";
    }

    ~OrderItem() {
        cout << "OrderItem destroyed\n";
    }
};

class Order {
private:
    OrderItem item1;
    OrderItem item2;

public:
    Order()
        : item1("Laptop"),
          item2("Mouse") {
    }

    ~Order() {
        cout << "Order destroyed\n";
    }
};

int main() {

    {
        Order order;
    }

    // order is destroyed here
    // item1 and item2 are also destroyed
}