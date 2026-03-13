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

    // Function to park vehicle
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
                cout<<"Parked at Spot: "<<s[i].id<<endl<<endl;

                return;
            }
        }

        cout<<"Parking Full"<<endl<<endl;
    }

    // removeVehicle() implementation
    void removeVehicle(string number)
    {
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i].occupied && s[i].vehicle->number == number)
            {
                cout<<"Vehicle Number: "<<s[i].vehicle->number<<endl;
                cout<<"Leaving Spot: "<<s[i].id<<endl;

                // mark slot empty
                s[i].occupied = false;
                s[i].vehicle = NULL;

                cout<<"Spot "<<s[i].id<<" is now free and available for new vehicles"<<endl<<endl;

                return;
            }
        }

        cout<<"Vehicle Not Found"<<endl<<endl;
    }
};

int main()
{
    ParkingLot p(5);

    V v1("UP78","Car");
    V v2("UP34","Bike");
    V v3("UP65","Truck");

    p.parkVehicle(&v1);
    p.parkVehicle(&v2);
    p.parkVehicle(&v3);

    // vehicle leaves
    p.removeVehicle("UP34");

    // new vehicle can park in freed slot
    V v4("UP90","Car");
    p.parkVehicle(&v4);

    return 0;
}