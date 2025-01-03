#ifndef SUPPLIER_H
#define SUPPLIER_H

#include "ShoppingCart.h"

class Supplier : public ShoppingCart {
private:
    double totalProfit;

public:
    // Constructors and Destructor
    Supplier();
    Supplier(const Supplier& other);
    ~Supplier();

    // Methods
    void addProductToInventory(const Product& product);
    void updateProductPrice(int productId, double newPrice);
    void sellProduct(int productId, int quantity);
    double getTotalProfit() const;

    // Operators
    Supplier& operator=(const Supplier& other);
};

#endif
