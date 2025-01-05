#include "ShoppingCart.h"

// Default constructor
ShoppingCart::ShoppingCart() : total_price(0.0) {}

// Destructor
ShoppingCart::~ShoppingCart() {}

// Adds a product to the cart and updates the total price
bool ShoppingCart::add_Product(const Product& p) {
    for (auto& item : items) {
        if (item == p) { // Check if the product already exists
            item += p.get_quantity();
            total_price += p.get_price() * p.get_quantity();
            return true;
        }
    }
    items.push_back(p);
    total_price += p.get_price() * p.get_quantity();
    return true;
}

// Adds a product with a specific quantity and updates the total price
bool ShoppingCart::add_Product(const Product& p, int quantity) {
    for (auto& item : items) {
        if (item == p) {
            item += quantity;
            total_price += p.get_price() * quantity;
            return true;
        }
    }
    Product new_product(p);
    new_product += quantity - new_product.get_quantity();
    items.push_back(new_product);
    total_price += p.get_price() * quantity;
    return true;
}

// Removes a product completely from the cart
bool ShoppingCart::remove_Product(const Product& p) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (*it == p) {
            total_price -= it->get_price() * it->get_quantity();
            items.erase(it);
            return true;
        }
    }
    return false; // Product not found
}

// Removes a specific quantity of a product and updates the total price
bool ShoppingCart::remove_Product(const Product& p, int quantity) {
    for (auto& item : items) {
        if (item == p) {
            if (static_cast<int>(item.get_quantity()) > quantity) {
                item -= quantity;
                total_price -= p.get_price() * quantity;
                return true;
            } else {
                return remove_Product(p); // Remove completely if quantity matches or exceeds
            }
        }
    }
    return false; // Product not found
}

// Returns the list of products in the cart
const vector<Product>& ShoppingCart::Get_List() const {
    return items;
}

// Prints the shopping cart and total price
void ShoppingCart::printcart() const {
    cout << "Shopping Cart:\n";
    for (const auto& item : items) {
        cout << item << endl;
    }
    cout << "Total Price: " << total_price << endl;
}

// Returns the total price of the cart
double ShoppingCart::Get_total() const {
    return total_price;
}

// Operator Overloads
ostream& operator<<(ostream& os, const ShoppingCart& cart) {
    os << "Shopping Cart:\n";
    for (const auto& item : cart.items) {
        os << item << endl;
    }
    os << "Total Price: " << cart.total_price << endl;
    return os;
}

// Accesses a pointer to product by its ID
Product* ShoppingCart::operator[](int id) {
    for (auto& item : items) {
        if (item.get_id() == id) {
            return &item;
        }
    }
    return nullptr; // Product not found
}
