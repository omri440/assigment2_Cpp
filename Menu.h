#ifndef MENU_H
#define MENU_H

#include "ShoppingCart.h"
#include "Supplier.h"

class Menu {
private:
    Supplier supplier;   // Supplier object to manage inventory and sales
    ShoppingCart buyerCart; // Buyer’s shopping cart

public:
    Menu(); // Constructor

    void mainMenu();      // Displays the main menu
    void supplierMenu();  // Handles supplier-related actions
    void buyerMenu();     // Handles buyer-related actions
};

#endif
