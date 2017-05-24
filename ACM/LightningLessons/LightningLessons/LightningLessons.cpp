#include <iostream>
#include <deque>

using namespace std;

/**
 * Program to teach Zeus how to lightning bolt properly.
 */
int main() {
	// Declare the variables we will use for the program
	int bolts;
	int pivots;
	int value;
	int sum;
	int cycle;
	bool goOn=true; // Default to true so that it does more than 1 iteration.

	// get input from standard input. Tells us how many bolts to expect.
	cin >> bolts;
	cin.get();

	// loop to handle lightning bolt count.
	for (int i = 0; i < bolts; i++) {
		// declare our cycle checker here so it gets cleared and reinitialized every time we get a new lightning bolt.
		deque<int> values;
		cin >> pivots;
		// populate our 
		for (int j = 0; j < pivots; j++) {
			cin >> value;
			values.push_front(value);
		}
		cin.get();

		goOn = true;
		cycle = 0;
		while (goOn) {
			sum = 0;
			for (int j = 0; j < values.size() - 1; j++) {
				cout << values[j] << ' ';
				values[j] -= values[j + 1];
				cout << values[j] << endl;
				sum += values[j];
			}
			cycle++;
			values.pop_back();

			if (sum == 0) {
				goOn = false;
				for (int j = 0; j < cycle; j++)
					cout << 'z';
				cout << "ap!" << endl;
			}
			else if (values.size() == 1) {
				goOn = false;
				if (values[0] < 0)
					cout << "*bunny*" << endl;
				else {
					cout << "*fizzle*" << endl;
				}
			}
		}
	}

	system("PAUSE");
	return 0;
}