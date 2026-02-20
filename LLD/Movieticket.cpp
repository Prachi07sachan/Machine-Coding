#include <bits/stdc++.h>
using namespace std;

class MovieSystem {
private:
    string movie[10];
    int seats[100];
    int n; // movie count

public:
    MovieSystem() {
        n = 0;
        movie[n] = "Avengers"; 
        seats[n++] = 50;
        movie[n] = "Inception"; 
        seats[n++] = 40;
    }

    int availableSeats(string m) {
        for (int i = 0; i < n; i++) {
            if (movie[i] == m)
                return seats[i];
        }
        return -1;
    }

    string book(string m, int count) {
        for (int i = 0; i < n; i++) {
            if (movie[i] == m) {
                if (count <= seats[i]) {
                    seats[i] -= count;
                    return "Booked";
                }
                return "No seats";
            }
        }
        return "Movie not found";
    }
};