// Brandon Julao
// COMSC-210-5481
// Lab 20
// 10-13-2024

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 3;

class Chair {
private:
    int legs;
    double* prices;

public:
    // Default constructor
    Chair() {
        srand(time(0)); // Seed for random number generation
        legs = rand() % 2 + 3; // Randomly select 3 or 4 legs
        prices = new double[SIZE];
        for (int i = 0; i < SIZE; i++)
            prices[i] = 100.00 + static_cast<double>(rand()) / RAND_MAX * 899.99; // Randomly select prices between 100.00 and 999.99
    }

    // Parameter constructor
    Chair(int l, double p[]) {
        legs = l;
        prices = new double[SIZE];
        for (int i = 0; i < SIZE; i++)
            prices[i] = p[i];
    }

    // Setters and getters
    void setLegs(int l) { legs = l; }
    int getLegs() { return legs; }
    void setPrices(double p1, double p2, double p3) {
        prices[0] = p1; prices[1] = p2; prices[2] = p3;
    }

    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: ";
        for (int i = 0; i < SIZE; i++)
            cout << fixed << setprecision(2) << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices() << endl << endl;
    }

    // Destructor to free allocated memory
    ~Chair() {
        delete[] prices;
    }
};

int main() {
    cout << fixed << setprecision(2);

    // Creating pointer to first chair object using default constructor
    Chair* chairPtr = new Chair;
    chairPtr->print();
    delete chairPtr;
    chairPtr = nullptr;

    // Creating dynamic chair object with parameter constructor
    double prices[] = { 121.21, 232.32, 414.14 };
    Chair* livingChair = new Chair(3, prices);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    // Creating dynamic array of chair objects using default constructors
    Chair* collection = new Chair[SIZE];
    for (int i = 0; i < SIZE; i++)
        collection[i].print();

    delete[] collection; // Deallocate memory for the array of Chair objects
    collection = nullptr;

    return 0;
}