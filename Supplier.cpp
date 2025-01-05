#include "Supplier.h"
#include <iostream>

// Default constructor
Supplier::Supplier() : ShoppingCart(), counter(0) {}

// Destructor
Supplier::~Supplier() {}

// Removes a product from the cart and updates the counter
bool Supplier::remove_Product(const Product& p) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (*it == p) {
            counter -= it->get_price() * it->get_quantity();
            items.erase(it);
            total_price -= it->get_price() * it->get_quantity();
            return true;
        }
    }
    return false; // Product not found
}

// Removes a specific quantity of a product and updates the counter
bool Supplier::remove_Product(const Product& p, int quantity) {
    for (auto& item : items) {
        if (item == p) {
            if (static_cast<int>(item.get_quantity()) > quantity) {
                item -= quantity;
                counter -= p.get_price() * quantity;
                total_price -= p.get_price() * quantity;
                return true;
            } else {
                return remove_Product(p); // Remove completely if quantity matches or exceeds
            }
        }
    }
    return false; // Product not found
}

// Updates stock and profit for a single product
bool Supplier::customer_purchases(const Product& p) {
    for (auto& item : items) {
        if (item == p) {
            if (item.get_quantity() >= p.get_quantity()) {
                item -= p.get_quantity();
                counter += p.get_price() * p.get_quantity();
                total_price -= p.get_price() * p.get_quantity();
                return true;
            }
        }
    }
    return false; // Product not available or insufficient quantity
}

// Updates stock and profit for multiple products
bool Supplier::customer_purchases(const ShoppingCart& cart) {
    for (const auto& product : cart.Get_List()) {
        if (!customer_purchases(product)) {
            return false; // Purchase failed for at least one product
        }
    }
    counter += cart.Get_total(); // Add the total price of the cart to the counter
    return true;
}

// Changes the price of a product by ID
bool Supplier::change_price(int id, double new_price) {
    for (auto& item : items) {
        if (item.get_id() == id) {
            item.price = new_price;// Update the price directly
            return true;
        }
    }
    return false; // Product not found
}

// Returns the total profit
double Supplier::get_total_profit() const {
    return counter - total_price; // Profit = counter - total price of items in stock
}

// Prints supplier details
ostream& operator<<(ostream& os, const Supplier& supplier) {
    os << "Supplier Inventory:\n";
    for (const auto& item : supplier.items) {
        os << item << endl;
    }
    os << "Total Price of Stock: " << supplier.total_price << endl;
    os << "Total Profit: " << supplier.get_total_profit() << endl;
    return os;
}

// View available products
void Supplier::viewProducts() const {
    if (items.empty()) {
        std::cout << "No products available.\n";
    } else {
        std::cout << "Supplier Inventory:\n";
        for (const auto& item : items) {
            std::cout << item << std::endl;
        }
    }
}

// Add a new product to inventory
bool Supplier::addProduct(const Product& p) {
    return ShoppingCart::add_Product(p);
}
