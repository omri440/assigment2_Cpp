#include "Product.h"

// Initialize static ID generator
int Product::nextId = 1;

// Default Constructor
Product::Product() : name("Unknown"), price(0.0), quantity(0), id(nextId++) {}

// Parameterized Constructor
Product::Product(const string& name, double price, int quantity)
    : name(name), price(price), quantity(quantity), id(nextId++) {}

// Copy Constructor
Product::Product(const Product& other)
    : name(other.name), price(other.price), quantity(other.quantity), id(other.id) {}

// Destructor
Product::~Product() {}

// Getters
string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

int Product::getQuantity() const {
    return quantity;
}

int Product::getId() const {
    return id;
}

// Setters
void Product::setName(const string& name) {
    this->name = name;
}

void Product::setPrice(double price) {
    this->price = price;
}

void Product::setQuantity(int quantity) {
    this->quantity = quantity;
}

// Operator Overloads
Product& Product::operator=(const Product& other) {
    if (this != &other) {
        name = other.name;
        price = other.price;
        quantity = other.quantity;
        // ID remains unchanged
    }
    return *this;
}

bool Product::operator==(const Product& other) const {
    return id == other.id;
}

bool Product::operator!=(const Product& other) const {
    return !(*this == other);
}

// Overload << to print product details
ostream& operator<<(ostream& os, const Product& product) {
    os << "Product ID: " << product.id << "\n"
       << "Name: " << product.name << "\n"
       << "Price: " << product.price << "\n"
       << "Quantity: " << product.quantity << "\n";
    return os;
}
