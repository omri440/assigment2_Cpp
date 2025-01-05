#include "Product.h"

// Initialize static member
int Product::next_id = 1;

// Copy constructor with the same ID
Product::Product(const Product& p) : id(p.id), name(p.name), price(p.price), quantity(p.quantity) {}

// Copy constructor with a limited quantity
Product::Product(const Product& p, int q) : id(p.id), name(p.name), price(p.price), quantity(q) {}

// Constructor with a new ID
Product::Product(string name, double price, int q) : id(next_id++), name(std::move(name)), price(price), quantity(q) {}

Product::Product(int id, string name, double price, int quantity)
    : id(id), name(std::move(name)), price(price), quantity(quantity) {}
// Getter Methods
double Product::get_price() const {
    return price;
}

unsigned int Product::get_quantity() const {
    return quantity;
}

int Product::get_id() const {
    return id;
}

void Product::addQuantity(unsigned int additionalQuantity) {
    this->quantity += additionalQuantity;
}
// Operator Overloads
ostream& operator<<(ostream& os, const Product& p) {
    os << "Product [ID: " << p.id
       << ", Name: " << p.name
       << ", Price: " << p.price
       << ", Quantity: " << p.quantity << "]";
    return os;
}

bool Product::operator==(const Product& other) const {
    return id == other.id;
}

bool Product::operator==(int other_id) const {
    return id == other_id;
}

bool Product::operator!=(const Product& other) const {
    return id != other.id;
}

bool Product::operator!=(int other_id) const {
    return id != other_id;
}

Product& Product::operator++() {
    ++quantity;
    return *this;
}

Product& Product::operator+=(unsigned int q) {
    quantity += q;
    return *this;
}

Product& Product::operator-=(unsigned int q) {
    if (q > quantity) {
        throw std::out_of_range("Cannot decrease by more than the available quantity.");
    }
    quantity -= q;
    return *this;
}
