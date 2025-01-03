#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu() : supplier(), buyerCart() {}

void Menu::mainMenu() {
    int choice;

    do {
        cout << "\nMain Menu:\n";
        cout << "1. Enter Supplier Menu\n";
        cout << "2. Enter Buyer Menu\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                supplierMenu();
                break;
            case 2:
                buyerMenu();
                break;
            case 3:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);
}

void Menu::supplierMenu() {
    int choice;
    do {
        cout << "\nSupplier Menu:\n";
        cout << "1. View All Products\n";
        cout << "2. Add New Product\n";
        cout << "3. Update Product Price\n";
        cout << "4. Remove Product\n";
        cout << "5. View Total Profit\n";
        cout << "6. Return to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                supplier.printcart();
                break;
            case 2: {
                string name;
                double price;
                int quantity;

                cout << "Enter product name: ";
                cin >> name;
                cout << "Enter product price: ";
                cin >> price;
                cout << "Enter product quantity: ";
                cin >> quantity;

                Product newProduct(name, price, quantity);
                supplier.addProductToInventory(newProduct);

                cout << "Product added successfully.\n";
                break;
            }
            case 3: {
                int productId;
                double newPrice;

                cout << "Enter product ID to update: ";
                cin >> productId;
                cout << "Enter new price: ";
                cin >> newPrice;

                supplier.updateProductPrice(productId, newPrice);
                break;
            }
            case 4: {
                int productId;

                cout << "Enter product ID to remove: ";
                cin >> productId;

                if (supplier.removeProduct(productId)) {
                    cout << "Product removed successfully.\n";
                } else {
                    cout << "Product not found.\n";
                }
                break;
            }
            case 5:
                cout << "Total Profit: " << supplier.getTotalProfit() << endl; // Fixed line
                break;
            case 6:
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
}

void Menu::buyerMenu() {
    int choice;
    do {
        cout << "\nBuyer Menu:\n";
        cout << "1. View All Products\n";
        cout << "2. Add Product to Cart\n";
        cout << "3. Remove Product from Cart\n";
        cout << "4. View Cart and Total Price\n";
        cout << "5. Checkout\n";
        cout << "6. Return to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                supplier.printcart();
                break;
            case 2: {
                int productId, quantity;

                cout << "Enter product ID to add: ";
                cin >> productId;
                cout << "Enter quantity: ";
                cin >> quantity;

                for (const auto& product : supplier.getProducts()) {
                    if (product.getId() == productId) {
                        Product buyerProduct = product;
                        buyerProduct.setQuantity(quantity);
                        buyerCart.addProduct(buyerProduct);
                        cout << "Product added to cart.\n";
                        break;
                    }
                }
                break;
            }
            case 3: {
                int productId;

                cout << "Enter product ID to remove: ";
                cin >> productId;

                if (buyerCart.removeProduct(productId)) {
                    cout << "Product removed from cart.\n";
                } else {
                    cout << "Product not found in cart.\n";
                }
                break;
            }
            case 4:
                cout << "Your Cart:\n";
                buyerCart.printcart();
                cout << "Total Price: " << buyerCart.getTotalPrice() << endl;
                break;
            case 5:
                cout << "Checkout completed. Thank you!\n";
                buyerCart = ShoppingCart(); // Clear the cart
                break;
            case 6:
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
}
