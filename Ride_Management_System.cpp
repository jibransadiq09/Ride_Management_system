#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* ===================== VEHICLE ===================== */
class Vehicle
{
private:
    int vehicleID;
    string model;
    string type;
    float baseFare;

public:
    Vehicle() {}

    Vehicle(int id, string m, string t, float fare)
    {
        vehicleID = id;
        model = m;
        type = t;
        baseFare = fare;
    }

    float getBaseFare() const
    {
        return baseFare;
    }

    string getType() const
    {
        return type;
    }

    void displayVehicle() const
    {
        cout << "Vehicle ID: " << vehicleID
             << ", Model: " << model
             << ", Type: " << type
             << ", Base Fare: " << baseFare << endl;
    }
};

/* ===================== DRIVER ===================== */
class Driver
{
private:
    int driverID;
    string name;
    float rating;
    Vehicle vehicle;

public:
    Driver() {} // ✅ Required for Visual Studio

    Driver(int id, string n, float r, Vehicle v)
    {
        driverID = id;
        name = n;
        rating = r;
        vehicle = v;
    }

    Vehicle getVehicle() const
    {
        return vehicle;
    }

    void displayDriver() const
    {
        cout << "Driver ID: " << driverID
             << ", Name: " << name
             << ", Rating: " << rating << endl;
        vehicle.displayVehicle();
    }
};

/* ===================== PASSENGER ===================== */
class Passenger
{
private:
    int passengerID;
    string name;

public:
    Passenger() {} // ✅ Required

    Passenger(int id, string n)
    {
        passengerID = id;
        name = n;
    }

    void displayPassenger() const
    {
        cout << "Passenger ID: " << passengerID
             << ", Name: " << name << endl;
    }
};

/* ===================== RIDE ===================== */
class Ride
{
private:
    int rideID;
    float distance;
    Passenger passenger;
    Driver driver;
    float totalFare;

public:
    Ride(int id, float dist, Passenger p, Driver d)
    {
        rideID = id;
        distance = dist;
        passenger = p;
        driver = d;
        totalFare = 0;
    }

    void calculateFare()
    {
        totalFare = distance * driver.getVehicle().getBaseFare();
    }

    void displayRideInfo() const
    {
        cout << "\n--- Ride Details ---\n";
        cout << "Ride ID: " << rideID << endl;
        passenger.displayPassenger();
        driver.displayDriver();
        cout << "Distance: " << distance << " km\n";
        cout << "Total Fare: " << totalFare << endl;
    }
};

/* ===================== RIDE MANAGER ===================== */
class RideManager
{
private:
    vector<Driver> drivers;
    vector<Passenger> passengers;
    vector<Ride *> rideHistory;
    int rideCounter;

public:
    RideManager()
    {
        rideCounter = 1;
    }

    void addDriver(Driver d)
    {
        drivers.push_back(d);
    }

    void addPassenger(Passenger p)
    {
        passengers.push_back(p);
    }

    void displayDrivers() const
    {
        for (const auto &d : drivers)
        {
            d.displayDriver();
        }
    }

    void bookRide()
    {
        float distance;
        cout << "Enter distance (km): ";
        cin >> distance;

        string vehicleChoice;
        cout << "Enter vehicle type (Car/Bike): ";
        cin >> vehicleChoice;

        int dIndex = -1;
        for (int i = 0; i < drivers.size(); i++)
        {
            if (drivers[i].getVehicle().getType() == vehicleChoice)
            {
                dIndex = i;
                break;
            }
        }

        if (dIndex == -1)
        {
            cout << "No drivers available for this vehicle type.\n";
            return;
        }

        Ride *r = new Ride(
            rideCounter++,
            distance,
            passengers[0],
            drivers[dIndex]);

        r->calculateFare();
        rideHistory.push_back(r);

        cout << "Ride booked successfully!\n";
        r->displayRideInfo();
    }

    void showHistory() const
    {
        for (auto r : rideHistory)
        {
            r->displayRideInfo();
        }
    }
};

/* ===================== MAIN ===================== */
int main()
{
    RideManager manager;

    Vehicle car(1, "Honda City", "Car", 50);
    Vehicle bike(2, "Yamaha", "Bike", 30);

    manager.addDriver(Driver(101, "Ali", 4.5, car));
    manager.addDriver(Driver(102, "Ahmed", 4.3, bike));

    manager.addPassenger(Passenger(201, "Ayesha"));

    int choice;
    do
    {
        cout << "\n1. Display Drivers\n2. Book Ride (Choose Car or Bike)\n3. Show Ride History\n0. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1)
            manager.displayDrivers();
        else if (choice == 2)
            manager.bookRide();
        else if (choice == 3)
            manager.showHistory();

    } while (choice != 0);

    return 0;
}
