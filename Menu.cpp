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
        cout << "\nSupplier Menu:\n"
             << "1. View available products\n"
             << "2. Add a new product to inventory\n"
             << "3. Update the price of an existing product\n"
             << "4. Remove a product from inventory\n"
             << "5. View total profit\n"
             << "6. Return to main menu\n"
             << "Enter your choice: ";
        choice = getValidatedInt("");

        switch (choice) {
            case 1:
                supplier.viewProducts();
                break;

            case 2: { // Add product
                supplier.viewProducts();
                int id = getValidatedInt("Enter product ID: ");
                Product* existingProduct = supplier[id];

                if (existingProduct) { // If product exists
                    int additionalQuantity = getValidatedInt("Enter additional quantity to add: ");
                    existingProduct->addQuantity(additionalQuantity);
                    cout << "Updated product quantity successfully." << endl;
                } else { // If product doesn't exist
                    string name;
                    double price;
                    int quantity;
                    cout << "Product ID not found. Enter product details:\n";
                    cout << "Enter product name: ";
                    cin >> name;
                    price = getValidatedDouble("Enter product price: ");
                    quantity = getValidatedInt("Enter product quantity: ");
                    supplier.addProduct(Product(id, name, price, static_cast<unsigned int>(quantity)));
                    cout << "New product added successfully." << endl;
                }
                break;
            }

            case 3: { // Update product price
                int id = getValidatedInt("Enter product ID to update price: ");
                double newPrice = getValidatedDouble("Enter new price: ");
                if (supplier.change_price(id, newPrice)) {
                    cout << "Price updated successfully." << endl;
                } else {
                    cout << "Product not found or update failed." << endl;
                }
                break;
            }

            case 4: { // Remove product
                int id = getValidatedInt("Enter product ID to remove: ");
                Product* product = supplier[id];
                if (product && supplier.remove_Product(*product)) {
                    cout << "Product removed successfully." << endl;
                } else {
                    cout << "Product not found or removal failed." << endl;
                }
                break;
            }

            case 5: // View total profit
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
        cout << "\nBuyer Menu:\n"
             << "1. View available products\n"
             << "2. Add a product to cart\n"
             << "3. Remove a product from cart\n"
             << "4. View cart contents and total price\n"
             << "5. Complete purchase\n"
             << "6. Return to main menu\n"
             << "Enter your choice: ";
        choice = getValidatedInt("");

        switch (choice) {
            case 1: // View products
                supplier.viewProducts();
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
