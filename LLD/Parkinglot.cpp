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

    // Constructor
    ParkingLot(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            s.push_back(ParkingSpot(i));
        }
    }

    // Park Vehicle
    void parkVehicle(string number, string type)
    {
        for (auto &spot : s)
        {
            if (!spot.occupied)
            {
                spot.vehicle = new V(number, type);
                spot.occupied = true;

                cout << "Vehicle parked at spot " << spot.id << endl;
                return;
            }
        }
        cout << "Parking Full!\n";
    }

    // Remove Vehicle
    void removeVehicle(string number)
    {
        for (auto &spot : s)
        {
            if (spot.occupied && spot.vehicle->number == number)
            {
                spot.occupied = false;
                delete spot.vehicle;
                spot.vehicle = NULL;

                cout << "Vehicle removed from spot " << spot.id << endl;
                return;
            }
        }
        cout << "Vehicle not found!\n";
    }

    // Display Status
    void displayStatus()
    {
        cout << "\nParking Lot Status:\n";

        for (auto &spot : s)
        {
            if (spot.occupied)
            {
                cout << "Spot " << spot.id << " -> Occupied ("
                     << spot.vehicle->number << ", "
                     << spot.vehicle->type << ")\n";
            }
            else
            {
                cout << "Spot " << spot.id << " -> Free\n";
            }
        }
    }
};

int main()
{
    ParkingLot p(3);

    p.parkVehicle("UP65AB1234", "Car");
    p.parkVehicle("UP65XY5678", "Bike");

    p.displayStatus();

    p.removeVehicle("UP65AB1234");

    p.displayStatus();

    return 0;
}
