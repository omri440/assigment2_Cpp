#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <vector>
#include <iostream>
#include "Product.h"
using namespace std;

class ShoppingCart {
protected:
    vector<Product> items; // List of products in the shopping cart.
    double total_price;    // Total price of products in the cart.

    friend class Supplier; // Allows Supplier class to access protected members.

public:
    // Constructors and Destructor
    ShoppingCart();  // Default constructor initializing an empty cart.
    ~ShoppingCart(); // Destructor to clean up resources.

    // Methods
    bool add_Product(const Product& p);                  // Adds a product to the cart.
    bool add_Product(const Product& p, int quantity);    // Adds a product with a specific quantity.
    bool remove_Product(const Product& p);              // Removes a product from the cart.
    bool remove_Product(const Product& p, int quantity); // Removes a specific quantity of a product.
    const vector<Product>& Get_List() const;            // Returns the list of products in the cart.
    void printcart() const;                             // Prints the shopping cart and total price.
    double Get_total() const;                           // Returns the total price.

    // Operator Overloads
    friend ostream& operator<<(ostream& os, const ShoppingCart& cart); // Prints cart details and total price.
    Product* operator[](int id);                                        // Accesses a pointer to product by its ID.
};

#endif // SHOPPINGCART_H
