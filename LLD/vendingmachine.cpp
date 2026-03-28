#include<iostream>
#include<vector>
using namespace std;


class Product
{
public:
    string name;
    int price;

    Product(string n, int p)
    {
        name = n;
        price = p;
    }
};


class VendingMachine
{
public:
    vector<Product> items;

    
    void addProduct(Product p)
    {
        items.push_back(p);
    }


    void showProducts()
    {
        for(int i = 0; i < items.size(); i++)
        {
            cout << i+1 << ". " << items[i].name 
                 << " - Rs " << items[i].price << endl;
        }
        cout << endl;
    }

    
    void buyProduct(int index, int money)
    {
        if(index < 0 || index >= items.size())
        {
            cout << "Invalid choice\n\n";
            return;
        }

        if(money < items[index].price)
        {
            cout << "Not enough money\n\n";
            return;
        }

        cout << "You got: " << items[index].name << endl;
        cout << "Change: " << money - items[index].price << endl << endl;
    }
};

int main()
{
    VendingMachine vm;

    vm.addProduct(Product("Coke", 40));
    vm.addProduct(Product("Chips", 20));
    vm.addProduct(Product("Chocolate", 30));

    vm.showProducts();

    vm.buyProduct(0, 50); 
    

    return 0;  
}