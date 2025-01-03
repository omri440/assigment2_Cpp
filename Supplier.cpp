#include "Supplier.h"

// Default constructor
Supplier::Supplier() : totalProfit(0) {}

// Copy constructor
Supplier::Supplier(const Supplier& other) : ShoppingCart(other), totalProfit(other.totalProfit) {}

// Destructor
Supplier::~Supplier() = default;

// Add a product to the inventory
void Supplier::addProductToInventory(const Product& product) {
    products.push_back(product);
}

// Update the price of a product by ID
void Supplier::updateProductPrice(int productId, double newPrice) {
    for (auto& product : products) {
        if (product.getId() == productId) {
            product.setPrice(newPrice);
            return;
        }
    }
    cout << "Product with ID " << productId << " not found." << endl;
}

// Sell a product, adjusting quantity and tracking profit
void Supplier::sellProduct(int productId, int quantity) {
    for (auto& product : products) {
        if (product.getId() == productId) {
            if (product.getQuantity() >= quantity) {
                totalProfit += product.getPrice() * quantity;
                product.setQuantity(product.getQuantity() - quantity);
                return;
            } else {
                cout << "Not enough stock for product ID " << productId << "." << endl;
                return;
            }
        }
    }
    cout << "Product with ID " << productId << " not found." << endl;
}

// Get the total profit from sales
double Supplier::getTotalProfit() const {
    return totalProfit;
}

// Assignment operator
Supplier& Supplier::operator=(const Supplier& other) {
    if (this != &other) {
        ShoppingCart::operator=(other);
        totalProfit = other.totalProfit;
    }
    return *this;
}
