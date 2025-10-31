#include "ConsoleCustomerPrinter.h"

void ConsoleCustomerPrinter::print(const ICustomer& customer) const {
    cout << "Customer: " << customer.getName() << endl;
    cout << "Email: " << customer.getEmail() << endl;
    cout << "Phone: " << customer.getPhone() << endl;
    cout << "VIP Status: " << (customer.isVIP() ? "Yes" : "No") << endl;
    cout << "Loyalty Points: " << customer.getLoyaltyPoints() << endl;

    cout << "Orders:" << endl;
    const auto& orders = customer.getOrders();
    if (orders.empty()) {
        cout << " - No orders yet" << endl;
    }
    else {
        for (const auto& d : orders)
            cout << " - " << d.getName() << endl;
    }

    cout << "Preferences: " << customer.getPreferences() << endl;
}
