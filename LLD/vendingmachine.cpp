#include <bits/stdc++.h>
using namespace std;

class VendingMachine {
private:
    string items[5] = {"Coke", "Pepsi", "Chips", "Chocolate", "Candy"};
    int price[5] = {20, 20, 15, 25, 10};
    int quantity[5] = {10, 8, 12, 5, 15};
    int moneyInserted;

public:
    VendingMachine() {
        moneyInserted = 0;
    }

    void display() {
        cout << "Items available:" << endl;
        for (int i = 0; i < 5; i++) {
            cout << i << ". " << items[i] << " - Rs." << price[i] << endl;
        }
    }

    void insertMoney(int amount) {
        moneyInserted += amount;
        cout << "Total money: " << moneyInserted << endl;
    }

    bool buyItem(int itemNum) {
        if (itemNum < 0 || itemNum >= 5) {
            cout << "Invalid item!" << endl;
            return false;
        }

        if (quantity[itemNum] == 0) {
            cout << "Out of stock!" << endl;
            return false;
        }

        if (moneyInserted < price[itemNum]) {
            cout << "Insufficient money!" << endl;
            return false;
        }

        // Dispense item
        quantity[itemNum]--;
        int change = moneyInserted - price[itemNum];
        cout << "Item dispensed: " << items[itemNum] << endl;
        if (change > 0) {
            cout << "Change: " << change << endl;
        }
        moneyInserted = 0;
        return true;
    }
};
