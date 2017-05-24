/**
 * Seating Chart ACM problem
 * @Author Matthew Brown
 */

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n;
	string input;

	do {
		int sum = 0;					// Keep track of the times we've found something out of order
		vector<string> Frodo;			// We want to keep track of Frodo's original sear order
		map<string, int> Samwise;		// We want to associate a new index with Sam's seat order


		// Enter the number of people
		cin >> n;
		if (n == 0) return 0;

		// Get the Frodo's seat order
		for (int i = 0; i < n; i++) {
			cin >> input;
			Frodo.push_back(input);
		}
		// Get Samwise's seat order 
		// The map is used to differentiate from Frodo's seat order
		for (int i = 0; i < n; i++) {
			cin >> input;
			Samwise.insert(pair<string, int>(input, i));
		}

		// Compare Samwise's order using Frodo's order, increment sum whenever A > B
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (Samwise[Frodo[i]] > Samwise[Frodo[j]])
					sum++;
			}
		}
		// Print the total number of switches
		cout << sum << endl;
	} while (n > 0);

	system("PAUSE");
	return 0;
}