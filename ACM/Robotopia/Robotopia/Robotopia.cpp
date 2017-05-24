#include <iostream>
#include <vector>

using namespace std;

int main() {
	// Variable declarations for everything we're using
	int num, aArms, bArms, aLegs, bLegs, totalLegs,
		totalArms, temp, remArms, remLegs;
	int robotA = 0; // stores the first valid value of RobotA for a combination
	int robotB = 0; // stores the first valid value of RobotB for a combination
	int aCount = 1; // keeps track of our number of RobotA during calculations
	int bCount = 1; // keeps track of our number of RobotB during calculations
	bool match = false;	// keeps track of whether or not we've found a valid combination of robots
	bool invalid = true;	// keeps track of whether or not we have more or less than 1 valid combination
	vector<string> answers;

	cin >> num;
	for (int i = 0; i < num; i++) {	// loop for the amount of inputs user enters
		// reinitialize values for each set of robots
		robotA = 1;
		robotB = 1;
		match = false;
		invalid = true;
		bCount = 0;

		cin >> aLegs;
		cin >> aArms;
		cin >> bLegs;
		cin >> bArms;
		cin >> totalLegs;
		cin >> totalArms;
	
		// Here we use the total legs/arms minus one set of each since we know each combination must contain one of each
		remLegs = totalLegs - aLegs - bLegs; // reinit our working legs
		remArms = totalArms - aArms - bArms; // reinit our working arms
		// find out how many times we can loop through before running out of arms
		aCount = remArms / aArms;
		// found out how many times we can loop through before running out of legs
		temp = remLegs / aLegs;
		// swap for the most limiting value
		if (aCount > temp) aCount = temp;

		// loop until we reach the limit
		while (aCount>=0) {
			// remaining arms and legs must both be zero for a valid combination
			if (((remArms - aCount*aArms - bCount*bArms) == 0)&&((remLegs - aCount*aLegs - bCount*bLegs) == 0)) {
				// it this is our first match
				if(!match){
					robotA += aCount;  // store the number of robotA we used
					robotB += bCount;  // store the number of RobotB we used
					invalid = false;	// so far we've only found one match so it's valid
					match = true;		// let the program know we've found a match
				}
				// if this is our second match
				else {
					invalid = true;		// since this is our second match, the combination is invalid
					break;				// we no longer need to continue in this combination
				}
			}
			aCount--;	// upkeep to keep track of RobotA
			bCount++;	// upkeep to keep track of RobotB
		}
		if (!invalid&&match)	// if we only found 1 match, print the results
   			cout << robotA << " " << robotB << endl;
		else					// else print out a ?
			cout << "?" << endl;
	}

	system("pause");
	return 0;
}