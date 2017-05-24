/**
 * Chutes and Ladders simulation from the 1998 ACM Programming Competition
 * Implemented by @author Matthew Brown
 */

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
	vector<int> rolls;				// Stores the rolls from the first part of the file
	vector<vector<int>> chutes;		// Stores the start and end tiles for the chutes
	vector<vector<int>> ladders;	// Stores the start and end tiles for the ladders
	vector<int> lose;				// Stores the lose-a-turn tile locations
	vector<int> gain;				// Stores the gain-a-turn tile locations
	int first, second;				// Temporary variables to handle input 

	// create vectors for the chutes vector of vectors to store things in
	{
		vector<int> one;
		vector<int> two;
		chutes.push_back(one);
		chutes.push_back(two);
	}

	// create vectors for the ladders vector of vectors to store things in
	{
		vector<int> one;
		vector<int> two;
		ladders.push_back(one);
		ladders.push_back(two);
	}

	// create our input filestream object to load data from
	ifstream inFile;
	{
		// open the file
		inFile.open("chutes.dat");
		if (!inFile.good()) exit(-1);

		int temp=1;

		// Handles the roll data parsing
		do {
			inFile >> temp;
			rolls.push_back(temp);
		} while (temp != 0);
		inFile.get();

		// handles the individual game parsing
		inFile >> temp;
		do {
			vector<int> players;
			for (int i = 0; i < temp; i++) {
				players.push_back(0);
			}
			inFile.get();

			// handles the parsing of the chutes and ladders
			do {
				temp = 1;
				inFile >> first >> second;
				inFile.get();
				if (first == 0 && second == 0) temp = 0;
				else if (first < second) {
					ladders[0].push_back(first);
					ladders[1].push_back(second);
				}
				else {
					chutes[0].push_back(first);
					chutes[1].push_back(second);
				}
			} while (temp != 0);

			// Handles parsing of the the lose-a-turn and gain-a-turn tiles
			do{
				inFile >> temp;
				inFile.get();
				if (temp < 0) lose.push_back(temp);
				else if (temp > 0) gain.push_back(temp);
			} while (temp != 0);

			// Play the game with the board setup
			int playerCounter = 0;
			for (unsigned i = 0; i < rolls.size(); i++) {
				// If a player's space is negative, then they lost a turn last round
				if (players[playerCounter] < 0) {
					// Make the players space positive so they don't lose another turn
					players[playerCounter] *= -1;
					// decrement our roll counter so we don't consume an unused roll
					i--;
				}
				// Else it is the current player's turn
				else {
					// Calculate where the player would move to
					int move = players[playerCounter] + rolls[i];
					// Check if the player lands on a chute tile
					for (unsigned j = 0; j < chutes[0].size(); j++) {
						// Move the player to the end of the chute
						if (move == chutes[0][j]) players[playerCounter] = chutes[1][j];
					}
					// Check if the player lands on a ladder tile
					for (unsigned j = 0; j < ladders[0].size(); j++) {
						// move the player to the top of the ladder
						if (move == ladders[0][j]) players[playerCounter] = ladders[1][j];
					}
					// Check if the player lands on a lose-a-turn tile
					for (unsigned j = 0; j < lose.size(); j++) {
						if (move == lose[j]) {
							// Move the player normally, but make their space negative to denote lost turn
							players[playerCounter] = move;
							players[playerCounter] *= -1;
						}
					}
					// Check if the player lands on a gain-a-turn tile
					for (unsigned j = 0; j < gain.size(); j++) {
						if (move == gain[j]) {
							// Move the player normally.
							players[playerCounter] = move;
							// Decrement playerCounter so they get to go again.
							playerCounter--;
						}
					}
				}
				// Check to see if the player reached 100 and won
				if (players[playerCounter] == 100) break;
				// Else change player
				playerCounter++;
				// If the playerCounter exceed the number of players, change it back to 0.
				if (playerCounter >= players.size()) playerCounter = 0;
			}
			// Report the winner
			cout << playerCounter+1 << endl;

			// Check to see if there is a next set.
			inFile >> temp;
			inFile.get();
		} while (temp != 0);

		inFile.close();
	}
	system("PAUSE");
	return 0;
}