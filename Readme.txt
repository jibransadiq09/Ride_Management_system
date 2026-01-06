Ride Management System:

A simple C++ Ride Management System to manage drivers, passengers, and rides. This project allows passengers to book rides, view ride history, and find drivers based on vehicle type and minimum rating.

Overview:

The Ride Management System is a console-based application written in C++. It simulates a basic ride-booking platform where passengers can request rides with drivers. Each driver has a vehicle, and each ride is calculated based on the vehicle's base fare and the ride distance. The system also maintains ride history for reference.

Project Idea:

The main idea is to provide a simplified ride-hailing platform where:

Drivers and their vehicles can be managed.

Passengers can book rides easily.

Total fare is calculated dynamically based on distance and vehicle type.

Users can search for drivers based on their ratings.

Purpose:

The project aims to:

Demonstrate object-oriented programming concepts in C++.

Manage interactions between vehicles, drivers, passengers, and rides efficiently.

Provide a basic understanding of ride management systems similar to real-world applications like Uber or Careem.

Features:

Add and display drivers along with their vehicles.

Add and display registered passengers.

Book rides with chosen vehicle type.

Automatically calculate total fare based on distance and vehicle base fare.

View ride history of all booked rides.

Search for drivers by minimum rating.

Program Structure:

The system contains the following classes:

Vehicle – Stores information about the vehicle including ID, model, type, and base fare.

Driver – Stores driver details along with the vehicle they drive.

Passenger – Stores passenger details like name and contact.

Ride – Manages ride details, calculates total fare, and stores associated passenger and driver.

RideManager – Core system to handle drivers, passengers, ride booking, history, and driver searches.

How to Run:

Clone the repository:

git clone https://github.com/jibransadiq09/RideManagementSystem.git


Navigate to the project folder:

cd RideManagementSystem


Compile the C++ program using g++:

g++ main.cpp -o RideManagementSystem


Run the executable:

./RideManagementSystem


Follow the console menu to use the system.

