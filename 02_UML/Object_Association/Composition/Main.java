import java.util.ArrayList;
import java.util.List;

class OrderItem {

    private String productName;

    OrderItem(String productName) {
        this.productName = productName;
    }
}

class Order {

    private List<OrderItem> items = new ArrayList<>();

    public Order() {
        items.add(new OrderItem("Laptop"));
        items.add(new OrderItem("Mouse"));
    }
}

public class Main {

    public static void main(String[] args) {

        Order order = new Order();

    } // order becomes unreachable here,
      // and its OrderItems are also owned by it.
}