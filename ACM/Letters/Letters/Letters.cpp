#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	vector<string> good;
	vector<string> bad;
	vector<string> bundles;
	vector<int> num;
	vector<int> five;
	vector<int> three;
	vector<string> three_key;
	string data;
	bool goOn=true;

	ifstream inFile;
	inFile.open("bulk.dat");
	if (!inFile.good()) {
		cout << "File did not open" << endl;
		system("PAUSE");
		exit(-1);
	}

	do {
		getline(inFile, data);
		if (data.size() != 5) {
			bool skip = false;
			for (unsigned i = 0; i < bad.size(); i++)
				if (data == bad[i]) skip = true;
			if(!skip) bad.push_back(data);
		}
		else {
			bool okay = true;
			for (char item : data) {
				if (item<'0' || item>'9') {
					bool skip = false;
					for (unsigned i = 0; i < bad.size(); i++)
						if (data == bad[i]) skip = true;
					if (!skip) bad.push_back(data);
					okay = false;
					break;
				}
			}
			if (!data.compare("00000")) bad.push_back(data);
			else if (okay) good.push_back(data);
		}
		inFile.peek();
		if (inFile.eof()) goOn = false;
	} while (goOn);

	sort(good.begin(), good.end());
	bundles.push_back(good[0]);
	num.push_back(1);
	for (unsigned i = 1; i < good.size(); i++) {
		if (good[i - 1] != good[i]) {
			bundles.push_back(good[i]);
			num.push_back(1); 
		}
		else {
			(*(num.end()-1))++;
		}
	}

	for (unsigned i = 0; i < num.size(); i++) {
		string key = bundles[i].substr(0, 3);
		if (num[i] >= 10) five.push_back(i);
		else if (three.size() == 0) {
			three.push_back(num[i]);
			three_key.push_back(bundles[i].substr(0, 3));
		}
		else{
			bool skip = false;
			for (unsigned j = 0; j < three_key.size(); j++) {
				if (!bundles[i].substr(0, 3).compare(three_key[j])) {
					three[j] += num[i];
					skip = true;
				}
			}
			if(!skip) {
				three.push_back(num[i]);
				three_key.push_back(bundles[i].substr(0, 3));
			}
		}
	}

	for (unsigned i = 0; i < three_key.size(); i++) {
//		cout << good[five[i]] << " " << num[five[i]] << endl;
		cout << three_key[i] << "XX  " << three[i] << endl;
	}

	cout << "INVALID ZIP CODES" << endl;
	for (unsigned i = 0; i < bad.size(); i++)
		cout << bad[i] << endl;

	system("PAUSE");
	return 0;
}