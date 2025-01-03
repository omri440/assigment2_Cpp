#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "Product.h"
#include <vector>
#include <iostream>
using namespace std;

class ShoppingCart {
protected:
    vector<Product> products; // List of products in the cart

public:
    // Constructors and Destructor
    ShoppingCart();
    ShoppingCart(const ShoppingCart& other);
    ~ShoppingCart();

    // Methods
    void addProduct(const Product& product);
    bool removeProduct(int productId);
    void printcart() const;
    double getTotalPrice() const;
    const vector<Product>& getProducts() const; // Add this

    // Operators
    ShoppingCart& operator=(const ShoppingCart& other);
};

#endif
