#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>
using namespace std;

class Product {
private:
    string name;    // Product name
    double price;   // Price per unit
    int quantity;   // Available quantity
    int id;         // Unique product ID

    static int nextId; // Static variable to generate unique IDs

public:
    // Constructors
    Product();
    Product(const string& name, double price, int quantity);

    // Copy Constructor
    Product(const Product& other);

    // Destructor
    ~Product();

    // Getters and Setters
    string getName() const;
    double getPrice() const;
    int getQuantity() const;
    int getId() const;

    void setName(const string& name);
    void setPrice(double price);
    void setQuantity(int quantity);

    // Operator Overloads
    Product& operator=(const Product& other);
    bool operator==(const Product& other) const;
    bool operator!=(const Product& other) const;

    // Print product details
    friend ostream& operator<<(ostream& os, const Product& product);
};

#endif
