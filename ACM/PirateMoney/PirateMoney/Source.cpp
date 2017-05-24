#include <iostream>
#include <vector>

using namespace std;

/**
 * Class to hold our combinations of coins.
 */
class PirateMoney {
public:
	unsigned base;
	vector<int> quarters;
	vector<int> dimes;
	vector<int> nickels;
	vector<int> pennies;

	/**
	 * Default Constructor.
	 */
	PirateMoney();
	/**
	 * Overloaded constructor. Sets base to the value of change we are making combinations for.
	 * Instantiates the vectors to store our coin combinations.
	 * Combinations that use none of a coin push 0 as the value.
	 */
	PirateMoney(unsigned);

	/**
	 * Recursive function that uses backtracking to get every valid combination of coins.
	 * Since the values are passed by value, we preserve the state of each function call 
	 * and reset properly when we return. No duplicates are considered due to edge guarding.
	 * Pre: A valid amount of change from the user, as well as any coins to exclude from the user.
	 * Post: Four vectors full of the combinations of coins, ready to output.
	 */
	void change(unsigned, int, int, int, bool, bool, bool, bool);

	/**
	 * Overloaded ostream operator to output our combinations easily.
	 */
	friend ostream& operator<<(ostream& out, PirateMoney soln) {
		out << "The solutions for " << soln.base << " coins are:" << endl;
		for (unsigned i = 0; i < soln.quarters.size(); i++) {
			out << '\t';
			if (soln.quarters[i] != 0) {
				out << soln.quarters[i];
				if (soln.quarters[i] == 1) out << " quarter";
				else out << " quarters";
			}
			if (soln.dimes[i] != 0) {
				if (soln.quarters[i] != 0) out << ", ";
				out << soln.dimes[i];
				if (soln.dimes[i] == 1) out << " dime";
				else out << " dimes";
			}
			if (soln.nickels[i] != 0) {
				if (soln.quarters[i] != 0 || soln.dimes[i] != 0) out << ", ";
				out << soln.nickels[i];
				if (soln.nickels[i] == 1) out << " nickel";
				else out << " nickels";
			}
			if (soln.pennies[i] != 0) {
				if (soln.quarters[i] != 0 || soln.dimes[i] != 0 || soln.nickels[i] != 0) out << ", ";
				out << soln.pennies[i];
				if (soln.pennies[i] == 1) out << " penny";
				else out << " pennies";
			}
			out << '.' << endl;
		}
			return out;
	}
};

/**
 * Recursive function to get input from the user.
 * Stores whether to exclude a coin.
 */
template<typename T>
void input(T&);

/**
 * Function to get initialization values for our class.
 * Gets a valid change amount, and what coins (if any) to exclude from the user.
 */
void init(unsigned&, bool&, bool&, bool&, bool&);

/**
 * Main body of the program. Calls all the functions to get user input.
 * Creates the object and calls change to solve the problem.
 * Outputs the solutions.
 */
int main() {
	// Declare variables used for initialization of our class.
	unsigned n; // amount of change to sort.
	bool no_q, no_d, no_n, no_p; // Whether or not to use a specific coin.

	// Set our initialization values for the PirateMoney object.
	init(n, no_q, no_d, no_n, no_p);

	// Initialize our solution object.
	PirateMoney soln(n);
	// Call the change method to get our solutions.
	soln.change(n, 0, 0, 0, no_q, no_d, no_n, no_p);

	// Output all of our solutions.
	cout << soln;

	system("pause");
	return 0;
}

PirateMoney::PirateMoney() {
	base = 0;
	vector<int> quarters;
	vector<int> dimes;
	vector<int> nickels;
	vector<int> pennies;
}

PirateMoney::PirateMoney(unsigned total) {
	base = total;
	vector<int> quarters;
	vector<int> dimes;
	vector<int> nickels;
	vector<int> pennies;
}
 
void PirateMoney::change(unsigned total, int q, int d, int n, bool q_done, bool d_done, bool n_done, bool p_done) {
	// First we take out quarters. If q_done is enabled, we skip it.
	if (total >= 25 && !q_done) {
		change(total - 25, q + 1, d, n, q_done, d_done, n_done, p_done);
		q_done = true;
	}
	// Next we take out dimes. If d_done is enabled, we skip it.
	if (total >= 10 && !d_done) {
		change(total - 10, q, d + 1, n, q_done, d_done, n_done, p_done);
		d_done = true;
	}
	// Next we take out nickels. If n_done is enabled, we skip it.
	if (total >= 5 && !n_done) {
		change(total - 5, q, d, n + 1, q_done, d_done, n_done, p_done);
		n_done = true;
	}
	// If p_done is not enabled, we store the rest of the total as pennies.
	// We push the values of q, d, n as the number of coins for each coin into their respective vectors.
	if (!p_done) {
		quarters.push_back(q);
		dimes.push_back(d);
		nickels.push_back(n);
		pennies.push_back(total);
	}
	// If we are exlcuding pennies, we have to check if the total has been reduced to 0.
	// If they are, we can push the rest of the values into the vectors and 0 for pennies.
	else if (total == 0) {
		quarters.push_back(q);
		dimes.push_back(d);
		nickels.push_back(n);
		pennies.push_back(0);
	}
	return;
}

template<typename T>
void input(T &var) {
	cin >> var;
	if (!cin.good()) {
		cout << "Please enter valid input! ";
		cin.clear();
		cin.ignore(1000, '\n');
		input(var);
	}
}

void init(unsigned &n, bool &no_q, bool &no_d, bool &no_n, bool &no_p) {
	cout << "Please enter an amount of change to count: ";
	input(n);

	cout << "Please enter if you want to exclude a type of coins (use 0 for no and 1 for yes)" << endl;
	cout << "Quarters? ";
	input(no_q);
	cout << "Dimes? ";
	input(no_d);
	cout << "Nickels? ";
	input(no_n);
	cout << "Pennies? ";
	input(no_p);

	return;
}