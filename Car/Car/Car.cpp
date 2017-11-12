#include <iostream>
using namespace std;

class Car {
public:
	char m_make[10];
	char m_model[10];
	size_t m_year;
	size_t m_engine;
	char m_color[10];

	void Print() const
	{
		cout << "car make:" << m_make << endl;
		cout << "car model:" << m_model << endl;
		cout << "car year:" << m_year << endl;
		cout << "car engine:" << m_engine << endl;
		cout << "car color:" << m_color << endl;
	}

	/*
	The function return the car with older
	input: Two cars
	output: 0 if equal, 1 if newer, otherwise -1
	*/
	int Newer(const Car &otherCar) const
	{
		int result = 0;
		if (m_year > otherCar.m_year)
		{
			result = 1;
		}
		else if (m_year < otherCar.m_year)
		{
			result = -1;
		}
		return result;
	}
	/*
	The function return the car with greater engine value
	input: Two cars
	output: 0 if equal, 1 if bigger, otherwise -1
	*/
	int IsBiggerEngineVolume(const Car &otherCar) const
	{
		int result = 0;
		if (m_engine > otherCar.m_engine)
		{
			result = 1;
		}
		else if (m_engine < otherCar.m_engine)
		{
			result = -1;
		}
		return result;
	}
};

/*
The function populate a car with the user input
input: a car
output: 0 if succeed, otherwise -1
*/
int PopulateCar(Car &car)
{
	cout << "please enter car details" << endl;
	cout << "car make(max 10 chars):";
	cin >> car.m_make;

	cout << "car model(max 10 chars):";
	cin >> car.m_model;

	cout << "car year:";
	cin >> car.m_year;
	if (cin.fail() && car.m_year > 1880 && car.m_year < 2017)
	{
		cout << "Sorry, value should be integer between 1800 - 2017" << endl;
		return -1;
	}

	cout << "car engine volume:";
	cin >> car.m_engine;
	if (cin.fail())
	{
		cout << "Sorry, value should be integer" << endl;
		return -1;
	}

	cout << "car color(max 10 chars):";
	cin >> car.m_color;
	return 0;
}

/*
The program compares 2 user's cars
*/
int main()
{
	Car my_car;
	Car friend_car;
	size_t sucees1 = PopulateCar(my_car);
	if (sucees1 >= 0)
	{
		cout << "*****************************" << endl << "Car Details" << endl << "*****************************" << endl;
		my_car.Print();
	}
	else
	{
		return -1;
	}

	size_t sucees2 = PopulateCar(friend_car);
	if (sucees2 >= 0)
	{
		cout << "*****************************" << endl << "Car Details" << endl << "*****************************" << endl;
		friend_car.Print();
	}
	else
	{
		return -1;
	}


	if (sucees1 >= 0 && sucees2 >= 0)
	{
		cout << "*****************************" << endl << "Car Compare" << endl << "*****************************" << endl;
		int result = my_car.IsBiggerEngineVolume(friend_car);
		if (0 == result)
		{
			cout << "Both cars are with the same engine volume" << endl;
		}
		else if (1 == result)
		{
			cout << "The" << my_car.m_model << "car has bigger engine volume" << endl;
		}
		else
		{
			cout << "The" << my_car.m_model << "car has smaller engine volume" << endl;
		}
		

		// compare year
		result = my_car.Newer(friend_car);		
		if (0 == result)
		{
			cout << "Both cars are same year" << endl;
		}
		else if (1 == result)
		{
			cout << "The" << my_car.m_model << "car is newer" << endl;
		}
		else
		{
			cout << "The" << my_car.m_model << "car is older" << endl;
		}
	}
	return 0;
}