/**
 * Program to calculate the Cosine Similarity, Pearson Correlation, Euclidean Distance, and Jaccard Similarity
 * between two vectors of data.
 * @author Matthew Brown
 */

#include <iostream>
#include <cmath>

using namespace std;

/**
 * Basic input function to sanitize user input
 */
template<typename T>
void input(T&);

/**
 * Function to initialize the data array
 * Pre: Takes pointers to two data arrays and the size of the arrays
 * Post: Creates two new arrays and initilizes them to 0
 */
void init(double*&, double*&, int&);

/**
 * Fuction to handle data input from the user
 * Pre: takes two initialized arrays and their size and populates then with user data
 * Post: Valid user data in the arrays
 */
void userInput(double*&, double*&, int&);

/**
 * Function to calculate the cosine similarity between two vectors of data
 * Pre: Takes two populated vectors and their size
 * Post: Returns true if there is no division by zero and stores the value in a passed parameter
 */
bool CosSim(double*, double*, int, double&);

/**
 * Function to calculate the Pearson correlation between two vectors of data
 * Pre: Takes two populated vectors and their size
 * Post: Returns true if there is no division by zero and stores the value in a passed parameter
 */
bool Pearson(double*, double*, int, double&);

/**
 * Function to calculate the euclidean distance between two vectors of data
 * Pre: Takes two populated vectors and their size
 * Post: Returns the distance
 */
double Euclidean(double*, double*, int);

/**
 * Function to calculate the Jaccard similarity between two vectors of data
 * Pre: Takes two sets of BINARY data vectors and their size
 * Post: Returns true if there is no division by zero and stores the value in a passed parameter
 */
bool Jaccard(double*, double*, int, double&);

/**
 * Basic funtion to output the different metric options for the user to choose from
 */
void intro(void);

/**
 * Main body of the program. 
 * Creates the arrays to hold information in.
 * Calls the functions to populate the arrays with data.
 * Runs the loops to calculate the metrics.
 * Outputs the information.
 */
int main() {
	double* x = 0;
	double* y = 0;
	int n, choice;
	bool goOn = true;
	char YorN;
	double return_value;

	// Get the data from the user
	userInput(x, y, n);

	// Ask the user which metric they would like to run
	while (goOn) {
		intro();
		cout << "Method: ";
		input(choice);
		switch (choice) {
		case 1:
			if(CosSim(x, y, n, return_value))
				cout << "Cosine Similarity: " << return_value << endl << endl;
			else {
				cout << "There was division by zero." << endl << endl;
			}
			break;
		case 2:
			if (Pearson(x, y, n, return_value)) {
				cout << "Pearson Correlation: " << return_value << endl << endl;
			}
			else {
				cout << "There was division by zero." << endl << endl;
			}
			break;
		case 3:
			cout << "Euclidean Distance: " << Euclidean(x, y, n) << endl << endl;
			break;
		case 4:
			if (Jaccard(x, y, n, return_value)) {
				cout << "Jaccard Coefficients: " << return_value << endl << endl;
			}
			else {
				cout << "There was division by zero." << endl << endl;
			}
			break;
		default:
			cout << "Please enter valid input!" << endl;
			break;
		}

		// Ask the user if they would like to run another metric
		cout << "Type y if you would you like to do another: ";
		input(YorN);
		YorN = tolower(YorN);
		if (YorN == 'y') {
			goOn = true;
		}
		else {
			goOn = false;
		}
	}

	delete[] x;
	delete[] y;
	system("PAUSE");
	return 0;
}

template<typename T>
void input(T &value) {
	bool goOn = true;
	// loop until valid input is given
	while (goOn) {
		cin >> value;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Please enter a valid number!" << endl;
		}
		else {
			goOn = false;
		}
	}
}

void init(double* &x, double* &y, int &n) {
	x = new double[n];
	y = new double[n];

	// start off by populating the arrays with values of 0.0
	for (int i = 0; i < n; i++) {
		x[i] = y[i] = 0.0;
	}
}

void userInput(double* &x, double* &y, int &n) {
	cout << "Please enter the number of items in a vector: ";
	input(n);
	
	// Initialize the data vectors
	init(x, y, n);

	// Populate the data vectors.
	cout << "Please enter the values of the first vector:" << endl;
	for (int i = 0; i < n; i++) { 
		cout << "x[" << i + 1 << "]: ";
		input(x[i]);
	}
	cout << endl << "Please enter the values of the second vector:" << endl;
	for (int i = 0; i < n; i++) {
		cout << "y[" << i + 1 << "]: ";
		input(y[i]);
	}

	cout << endl << "The data vectors have been populated successfully!" << endl << endl;
}

bool CosSim(double* x, double* y, int n, double &d) {
	double den;	// denominator
	double dot = 0.0; // dot product of vector x and y
	double mag_x = 0.0; // magnitude of vector x
	double mag_y = 0.0; // magnitude of vector y

	// Calculate the dot product
	for (int i = 0; i < n; i++) {
		dot += x[i] * y[i];
		mag_x += x[i] * x[i];
		mag_y += y[i] * y[i];
	}
	// Calculate the magnitude of x and y
	mag_x = sqrt(mag_x);
	mag_y = sqrt(mag_y);

	// Calculate the bottom of the cosine similarity equation
	den = mag_x * mag_y;

	// Return false if mag_x or mag_y were 0
	if (den == 0) {
		d = 0;
		return false;
	}
	// else store the cosine similarity in d and return true
	else {
		d = dot / den;
		return true;
	}
}

bool Pearson(double* x, double* y, int n, double &corr) {
	double avg_x, avg_y, var_x, var_y, covar, stdev_x, stdev_y, den;
	avg_x = avg_y = var_x = var_y = covar = stdev_x = stdev_y = 0.0;

	// Calculate the average for x and y
	for (int i = 0; i < n; i++) {
		avg_x += x[i];
		avg_y += y[i];
	}
	avg_x /= static_cast<double>(n);
	avg_y /= static_cast<double>(n);

	// Calculate the variance and covariance of x and y
	for (int i = 0; i < n; i++) {
		var_x += (x[i] - avg_x)*(x[i] - avg_x);
		var_y += (y[i] - avg_y)*(y[i] - avg_y); 
		covar += ((x[i] - avg_x)*(y[i] - avg_y));
	}
	var_x /= static_cast<double>(n - 1);
	var_y /= static_cast<double>(n - 1);
	covar /= static_cast<double>(n - 1);

	// Calculate the standard deviation of x and y from their respective variance
	stdev_x = sqrt(var_x);
	stdev_y = sqrt(var_y);

	// Calculate the bottom of the correlation equation
	den = stdev_x*stdev_y;

	// If stdev_x or stdev_y were 0, return false
	if (den == 0) {
		corr = 0;
		return false;
	}
	// else store the correlation in corr and return true
	else {
		corr = covar / den;
		return true;
	}
}

double Euclidean(double* x, double* y, int n) {
	double dist;
	double sum = 0.0;

	// Calculate the euclidean distance
	for (int i = 0; i < n; i++) {
		sum += pow(x[i] - y[i], 2.0);
	}
	dist = sqrt(sum);
	return dist;
}

bool Jaccard(double* x, double* y, int n, double &j) {
	int m11, m10, m01, m00, den;
	m11 = m10 = m01 = m00 = 0;

	// Tabulate the different match cases
	for (int i = 0; i < n; i++) {
		if (x[i] == 1) {
			if (y[i] == 1) {
				m11++;
			}
			else m10++;
		}
		else if (y[i] == 1) {
			m01++;
		}
		else {
			m00++;
		}
	}

	den = m10 + m01 + m11;
	if (den == 0) {
		j = 0.0;
		return false;
	}
	else {
		j = static_cast<double>(m11) / static_cast<double>(den);
		return true;
	}
}

void intro() {
	cout << "Which test would you like to run? " << endl;
	cout << "1. Cosine Similarity" << endl;
	cout << "2. Pearson Correlation" << endl;
	cout << "3. Euclidean Distance" << endl;
	cout << "4. Jaccarad Coefficients" << endl << endl;
}