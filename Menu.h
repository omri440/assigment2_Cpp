#ifndef MENU_H
#define MENU_H

#include "Supplier.h"
#include "ShoppingCart.h"

class Menu {
private:
    Supplier supplier;
    ShoppingCart buyerCart;

    // Helper methods for input validation
    int getValidatedInt(const std::string& prompt);
    double getValidatedDouble(const std::string& prompt);

public:
    Menu();

    void mainMenu();
    void supplierMenu();
    void buyerMenu();
};

#endif
