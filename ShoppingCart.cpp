#include "ShoppingCart.h"

// Default constructor
ShoppingCart::ShoppingCart() = default;

// Copy constructor
ShoppingCart::ShoppingCart(const ShoppingCart& other) : products(other.products) {}

// Destructor
ShoppingCart::~ShoppingCart() = default;

// Add a product to the cart
void ShoppingCart::addProduct(const Product& product) {
    products.push_back(product);
}

// Remove a product by ID
bool ShoppingCart::removeProduct(int productId) {
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->getId() == productId) {
            products.erase(it);
            return true; // Product removed
        }
    }
    return false; // Product not found
}

// Print the cart contents
void ShoppingCart::printcart() const {
    if (products.empty()) {
        cout << "The cart is empty." << endl;
        return;
    }
    for (const auto& product : products) {
        cout << product << endl;
    }
}

// Calculate the total price of all products
double ShoppingCart::getTotalPrice() const {
    double total = 0;
    for (const auto& product : products) {
        total += product.getPrice() * product.getQuantity();
    }
    return total;
}

// Assignment operator
ShoppingCart& ShoppingCart::operator=(const ShoppingCart& other) {
    if (this != &other) {
        products = other.products;
    }
    return *this;
}

const vector<Product>& ShoppingCart::getProducts() const {
    return products;
}