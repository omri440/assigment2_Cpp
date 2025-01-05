#ifndef SUPPLIER_H
#define SUPPLIER_H

#include "ShoppingCart.h"

class Supplier : public ShoppingCart {
private:
    double counter = 0; // Total money made by customer purchases.

public:
    // Constructors
    Supplier();  // Default constructor.
    ~Supplier(); // Destructor.

    // Methods
    bool remove_Product(const Product& p);               // Removes a product and updates counter.
    bool remove_Product(const Product& p, int quantity); // Removes a specific quantity and updates counter.
    bool customer_purchases(const Product& p);           // Updates stock and profit for a single product.
    bool customer_purchases(const ShoppingCart& cart);   // Updates stock and profit for multiple products.
    bool change_price(int id, double new_price);         // Changes the price of a product by ID.
    double get_total_profit() const;                     // Returns the total profit (counter - total_price).
    bool addProduct(const Product& p);                   // Adds a product to inventory.
    void viewProducts() const;                           // Views all products in inventory.

    // Operator Overloads
    friend ostream& operator<<(ostream& os, const Supplier& supplier); // Prints supplier details.
};

#endif // SUPPLIER_H
