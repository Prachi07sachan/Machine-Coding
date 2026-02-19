#include <bits/stdc++.h>
using namespace std;


class Database {
private:
    int acc[50], pin[50], bal[50];
    int n;

public:
    Database() {
        n = 0;
    }

    void add(int a, int p, int b) {
        acc[n] = a;
        pin[n] = p;
        bal[n] = b;
        n++;
    }

    int find(int a, int p) {
        for (int i = 0; i < n; i++) {
            if (acc[i] == a && pin[i] == p)
                return i;
        }
        return -1;
    }

    int getBal(int i) {
        return bal[i];
    }

    bool withdraw(int i, int amt) {
        if (amt <= bal[i]) {
            bal[i] -= amt;
            return true;
        }
        return false;
    }

    void deposit(int i, int amt) {
        bal[i] += amt;
    }
};


class ATM {
private:
    Database db;

public:
    ATM() {
        db.add(101, 1234, 5000);
    }

    int balance(int acc, int pin) {
        int i = db.find(acc, pin);
        if (i == -1) return -1;
        return db.getBal(i);
    }

    string withdrawCash(int acc, int pin, int amt) {
        int i = db.find(acc, pin);
        if (i == -1) return "Invalid";

        return db.withdraw(i, amt) ? "Success" : "No balance";
    }

    void depositCash(int acc, int pin, int amt) {
        int i = db.find(acc, pin);
        if (i != -1)
            db.deposit(i, amt);
    }
};
