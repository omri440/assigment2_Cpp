#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    static int next_id;         // Static member to generate unique IDs for products.
    int id;                     // Unique ID for each product.
    string name;                // Name of the product.
    double price;               // Price of the product.
    unsigned int quantity;      // Quantity available of the product.

    friend class Supplier;      // Allows Supplier class to access private members.

public:
    // Constructors
    Product(const Product& p); // Copy constructor with the same ID.
    Product(const Product& p, int q); // Copy constructor with a limited quantity.
    Product(string name, double price, int q = 1); // Constructor with a new ID.
    Product(int id, string name, double price, int quantity = 1);
    // Getter Methods
    double get_price() const; // Returns the price of the product.
    unsigned int get_quantity() const; // Returns the quantity of the product.
    int get_id() const; // Returns the product ID.
    const std::string& get_name() const;
    void addQuantity(unsigned int additionalQuantity);
    // Operator Overloads
    friend ostream& operator<<(ostream& os, const Product& p); // Prints product details.
    bool operator==(const Product& other) const; // Compares product IDs.
    bool operator==(int other_id) const; // Compares product ID to an integer.
    bool operator!=(const Product& other) const; // Checks inequality of product IDs.
    bool operator!=(int other_id) const; // Checks inequality with an integer.

    Product& operator++(); // Increments the product quantity by 1.
    Product& operator+=(unsigned int q); // Adds a specific quantity to the product.
    Product& operator-=(unsigned int q); // Decreases a specific quantity of the product.
};

#endif // PRODUCT_H
