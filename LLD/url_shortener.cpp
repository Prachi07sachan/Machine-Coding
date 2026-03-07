#include <iostream>
#include <vector>
using namespace std;

class Item {
public:
    int id;
    string name;
    int price;
    int qty;

    Item(int i, string n, int p, int q) {
        id = i;
        name = n;
        price = p;
        qty = q;
    }
};

class VendingMachine {
public:
    vector<Item> items;

    void addItem(Item i) {
        items.push_back(i);
    }

    void showItems() {
        for (auto i : items) {
            cout << i.id << " "
                 << i.name
                 << " Price:" << i.price
                 << " Qty:" << i.qty << endl;
        }
    }

    void buy(int id) {
        for (auto &i : items) {
            if (i.id == id) {

                if (i.qty == 0) {
                    cout << "Out of Stock\n";
                    return;
                }

                cout << "Pay " << i.price << " via UPI\n";
                cout << "Payment Successful\n";

                cout << "Dispensing " << i.name << endl;

                i.qty--;   // update inventory
                return;
            }
        }

        cout << "Invalid Item\n";
    }
};
