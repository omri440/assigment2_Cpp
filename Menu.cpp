#include "Menu.h"
#include <iostream>
#include <limits>

using namespace std;

Menu::Menu() {}

int Menu::getValidatedInt(const std::string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a non-negative number." << endl;
        } else {
            return value;
        }
    }
}

double Menu::getValidatedDouble(const std::string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value < 0.0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a non-negative number." << endl;
        } else {
            return value;
        }
    }
}

void Menu::mainMenu() {
    int choice;
    do {
        cout << "Main Menu:\n"
             << "1. Supplier Menu\n"
             << "2. Buyer Menu\n"
             << "3. Exit\n"
             << "Enter your choice: ";
        choice = getValidatedInt("");

        switch (choice) {
            case 1:
                supplierMenu();
                break;
            case 2:
                buyerMenu();
                break;
            case 3:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);
}

void Menu::supplierMenu() {
    int choice;
    do {
        cout << "\nstore Menu:\n"
             << "1. print store\n"
             << "2. add quantity to exist product or add new product\n"
             << "3. Change Exist product Price\n"
             << "4. remove product from the store\n"
             << "5. View total profit\n"
             << "6. Exit\n"
             << "Enter your choice: ";
        choice = getValidatedInt("");

        switch (choice) {
            case 1:
                supplier.viewProducts(std::cout);
                break;

            case 2: {
                int id = getValidatedInt("Enter product ID: ");
                Product* existingProduct = supplier[id];
                if (existingProduct) {
                    // If the product exists, update its quantity
                    int additionalQuantity = getValidatedInt("Enter quantity to add: ");
                    existingProduct->addQuantity(additionalQuantity);
                    cout << "Quantity updated for product ID " << id << "." << endl;
                } else {
                    // If the product doesn't exist, create a new one
                    string name;
                    double price;
                    int quantity;
                    cout << "Product not found.\n";
                    cout << "Enter product name: ";
                    cin >> name;
                    price = getValidatedDouble("Enter product price: ");
                    quantity = getValidatedInt("Enter product quantity: ");
                    supplier.addProduct(Product(name, price, quantity));
                    cout << "New product added successfully." << endl;
                }
                break;
            }

            case 3: {
                supplier.viewProducts(std::cout);
                int id = getValidatedInt("Enter product ID to update price: ");
                double newPrice = getValidatedDouble("Enter new price: ");
                supplier.change_price(id, newPrice);
                break;
            }

            case 4: {
                supplier.viewProducts(std::cout);
                int id = getValidatedInt("Enter product ID to remove: ");
                Product* product = supplier[id];
                if (product && supplier.remove_Product(*product)) {
                    cout << "Product removed successfully." << endl;
                } else {
                    cout << "Product not found." << endl;
                }
                break;
            }

            case 5:
                cout << "Total profit: " << supplier.get_total_profit() << endl;
                break;

            case 6:
                cout << "Returning to main menu." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);
}


void Menu::buyerMenu() {
    int choice;
    do {
        cout << "\nShopping Cart Menu:\n"
             << "1. print items store\n"
             << "2. Add Product to cart from store\n"
             << "3. Remove Product\n"
             << "4. View Cart\n"
             << "5. check out\n"
             << "6. Exit\n"
             << "Enter your choice: ";
        choice = getValidatedInt("");

        switch (choice) {
            case 1: // View products
                supplier.viewProducts(std::cout);
                break;

            case 2: { // Add to cart
                int id = getValidatedInt("Enter product ID to add: ");
                int quantity = getValidatedInt("Enter quantity: ");
                Product* product = supplier[id];
                if (product && product->get_quantity() >= static_cast<unsigned int>(quantity)) {
                    buyerCart.add_Product(*product, static_cast<unsigned int>(quantity));
                    supplier.remove_Product(*product, static_cast<unsigned int>(quantity));
                    cout << "Added to cart." << endl;
                } else {
                    cout << "Invalid product ID or insufficient stock." << endl;
                }
                break;
            }

            case 3: { // Remove from cart
                int id = getValidatedInt("Enter product ID to remove: ");
                int quantity = getValidatedInt("Enter quantity: ");
                Product* product = buyerCart[id];
                if (product && product->get_quantity() >= static_cast<unsigned int>(quantity)) {
                    buyerCart.remove_Product(*product, static_cast<unsigned int>(quantity));
                    supplier.addProduct(*product); // Add back to supplier's inventory
                    cout << "Removed from cart." << endl;
                } else {
                    cout << "Invalid product ID or insufficient quantity in cart." << endl;
                }
                break;
            }

            case 4: // View cart
                buyerCart.printcart();
                break;

            case 5: { // Complete purchase
                double totalPrice = buyerCart.Get_total();
                cout << "Total price: " << totalPrice << endl;
                char confirm;
                cout << "Confirm purchase? (y/n): ";
                cin >> confirm;
                if (tolower(confirm) == 'y') {
                    cout << "Purchase completed successfully!" << endl;
                    buyerCart = ShoppingCart(); // Reset the cart
                } else {
                    cout << "Purchase cancelled." << endl;
                }
                break;
            }

            case 6:
                cout << "Returning to main menu." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);
}
