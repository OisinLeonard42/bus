#include <iostream>

int howManyBusses(int t_passengers); //this is the declaration of method
int freeSeats(int t_passengers, int t_buses); // declaration

int main()
{
	//number of passengers
	int NoOfPassengers = 50;
	int NoOfBusses = 0; // how many buses on trip
	int emptySeats = 0; 
	NoOfBusses = howManyBusses(NoOfPassengers); // call method
	emptySeats = freeSeats(NoOfPassengers, NoOfBusses); // call

	return 2;  

}


/// <summary>
/// calculate how many buses using roundup/ceil
/// </summary>
/// <param name="t_passengers">number of passengers</param>
/// <returns>required number of buses</returns>
int howManyBusses(int t_passengers) // definition
{
	int buses = 0;
	//number of seats on bus
	const float NO_OF_SEATS = 45.0f;

	buses = static_cast<int>(std::ceil( t_passengers / NO_OF_SEATS));
	return buses;
}


/// <summary>
/// Calculating the number of free seats
/// </summary>
/// <param name="t_passengers">number of passengers on the trip</param>
/// <param name="t_buses">number of buses on the trip</param>
/// <returns>number of empty seats</returns>
int freeSeats(int t_passengers, int t_buses)
{
	const int NO_OF_SEATS = 45;
	int free = 0;
	free = t_buses* NO_OF_SEATS - t_passengers;
	return free;
}
