#include<iostream>
#include<vector>
using namespace std;

class V
{
public:
    string number;
    string type;

    V(string n, string t)
    {
        number = n;
        type = t;
    }
};

class ParkingSpot
{
public:
    int id;
    bool occupied;
    V* vehicle;

    ParkingSpot(int i)
    {
        id = i;
        occupied = false;
        vehicle = NULL;
    }
};

class ParkingLot
{
public:
    vector<ParkingSpot> s;

    ParkingLot(int n)
    {
        for(int i = 1; i <= n; i++)
        {
            s.push_back(ParkingSpot(i));
        }
    }

    void parkVehicle(V* v)
    {
        for(int i = 0; i < s.size(); i++)
        {
            if(!s[i].occupied)
            {
                s[i].occupied = true;
                s[i].vehicle = v;

                cout<<"Vehicle Number: "<<v->number<<endl;
                cout<<"Vehicle Type: "<<v->type<<endl;
                cout<<"Parked at Spot: "<<s[i].id<<endl;

                return;
            }
        }

        cout<<"Parking Full"<<endl;
    }
};

int main()
{
    ParkingLot p(10);

    V v1("UP78","Car");
    V v2("UP34","Bike");
    V v3("UP65","Truck");

    p.parkVehicle(&v1);
    p.parkVehicle(&v2);
    p.parkVehicle(&v3);

    return 0;
}