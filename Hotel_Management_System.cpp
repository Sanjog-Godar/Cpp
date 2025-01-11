#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

struct Room {
    int roomNumber;
    string roomType;
    bool isBooked;
    double price;

    Room(int number, string type, double cost)
        : roomNumber(number), roomType(type), isBooked(false), price(cost) {}
};

struct MenuItem {
    string itemName;
    double price;

    MenuItem(string name, double cost)
        : itemName(name), price(cost) {}
};

class HotelManagementSystem {
private:
    vector<Room> rooms;
    vector<MenuItem> menu;
    double totalEarnings;

public:
    HotelManagementSystem() : totalEarnings(0) {
        initializeRooms();
        initializeMenu();
    }

    void initializeRooms() {
        rooms.push_back(Room(101, "Single", 100.0));
        rooms.push_back(Room(102, "Double", 150.0));
        rooms.push_back(Room(103, "Suite", 300.0));
    }

    void initializeMenu() {
        menu.push_back(MenuItem("Burger", 5.99));
        menu.push_back(MenuItem("Pasta", 8.99));
        menu.push_back(MenuItem("Coffee", 2.99));
    }

    void displayRooms() {
        cout << left << setw(10) << "Room No"
             << setw(15) << "Room Type"
             << setw(10) << "Price"
             << "Status" << endl;
        for (const auto& room : rooms) {
            cout << left << setw(10) << room.roomNumber
                 << setw(15) << room.roomType
                 << setw(10) << room.price
                 << (room.isBooked ? "Booked" : "Available") << endl;
        }
    }

    void bookRoom() {
        int roomNumber;
        cout << "Enter the room number to book: ";
        cin >> roomNumber;

        for (auto& room : rooms) {
            if (room.roomNumber == roomNumber) {
                if (!room.isBooked) {
                    room.isBooked = true;
                    totalEarnings += room.price;
                    cout << "Room " << roomNumber << " has been successfully booked.\n";
                } else {
                    cout << "Room " << roomNumber << " is already booked.\n";
                }
                return;
            }
        }
        cout << "Room number " << roomNumber << " does not exist.\n";
    }

    void displayMenu() {
        cout << left << setw(20) << "Item Name"
             << "Price" << endl;
        for (const auto& item : menu) {
            cout << left << setw(20) << item.itemName
                 << "$" << item.price << endl;
        }
    }

    void orderFood() {
        string itemName;
        int quantity;
        double totalCost = 0;

        cout << "Enter the food item name: ";
        cin.ignore();
        getline(cin, itemName);
        cout << "Enter the quantity: ";
        cin >> quantity;

        for (const auto& item : menu) {
            if (item.itemName == itemName) {
                totalCost = item.price * quantity;
                totalEarnings += totalCost;
                cout << "You ordered " << quantity << " " << itemName << "(s) for $" << totalCost << ".\n";
                return;
            }
        }
        cout << "Item not found in the menu.\n";
    }

    void displayEarnings() {
        cout << "Total earnings: $" << totalEarnings << endl;
    }

    void manageHotel() {
        int choice;

        do {
            cout << "\nHotel Management System\n";
            cout << "1. Display Rooms\n";
            cout << "2. Book Room\n";
            cout << "3. Display Menu\n";
            cout << "4. Order Food\n";
            cout << "5. Display Total Earnings\n";
            cout << "6. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                displayRooms();
                break;
            case 2:
                bookRoom();
                break;
            case 3:
                displayMenu();
                break;
            case 4:
                orderFood();
                break;
            case 5:
                displayEarnings();
                break;
            case 6:
                cout << "Exiting the system. Thank you!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 6);
    }
};

int main() {
    HotelManagementSystem hms;
    hms.manageHotel();
    return 0;
}
