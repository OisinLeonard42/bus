#include <iostream>

int howManyBusses(int t_passengers); //this is the declaration of method
int freeSeats(int t_passengers, int t_buses); // declaration
float calBusCost(int t_hours);
float totalCost(int t_buses, float t_costOfBuses);

int main()
{
	//number of passengers
	int NoOfPassengers = 50;
	int NoOfBusses = 0; // how many buses on trip
	int emptySeats = 0; 
	int hours = 2;//how many hours
	float costPerBus = 0.0f; // cost of each bus
	float costForAllBusesIncVAT = 0.0f;


	NoOfBusses = howManyBusses(NoOfPassengers); // call method
	emptySeats = freeSeats(NoOfPassengers, NoOfBusses); // call
	costPerBus = calBusCost(hours);
	costForAllBusesIncVAT = totalCost(NoOfBusses, costPerBus);
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


/// <summary>
/// where going to calculate the cost of the bus 
/// /// </summary>
/// <param name="t_hours">numbers of hours bus is hired for</param>
/// <returns>cost of one bus</returns>
float calBusCost(int t_hours)
{
	const float FIRST_RATE = 40.0f;
	const float SECOND_RATE = 30.0f;
	const float THIRD_RATE = 25.0f;
	float cost = 0.0f;
	if (t_hours <= 2)
	{
		cost = t_hours * FIRST_RATE;
	}
	if (t_hours >= 3 && t_hours <= 5)
	{
		cost = ((t_hours - 2) * SECOND_RATE) + 2 * FIRST_RATE;
	}
	if (t_hours >= 6 && t_hours <= 16)
	{
		cost = ((t_hours - 5) * THIRD_RATE) + (3 * SECOND_RATE) + (2 * FIRST_RATE);

	}


		return cost;
}

float totalCost(int t_buses, float t_costOfBuses)
{
	float cost = 0.0f;
	const float VAT_RATE = 7.5f;
	float VATAmt = 0.0;

	cost = cost + t_costOfBuses;
	VATAmt = (t_costOfBuses / 100.0f) * VAT_RATE;
	cost = (cost + VATAmt) * t_buses;

	return cost;
}
