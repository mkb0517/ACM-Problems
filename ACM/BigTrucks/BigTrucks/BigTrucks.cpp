#include<iostream>
#include<vector>
using namespace std;

struct road_weight
{
	int loc_a, loc_b, loc_weight;
};

int main()
{
	int number_of_locations,
		number_of_items, location,
		number_of_roads, distance;

	vector<int> items_at_location;
	int temp_i;
	cin >> number_of_items;
	for (int i = 0; i < number_of_items; i++)
	{
		cin >> temp_i;
		items_at_location.push_back(temp_i);
	}
	cin >> number_of_roads;
	int a, b, d;
	vector<road_weight> ;
	for (int i = 0; i < number_of_roads; i++)
	{
		cin >> a >> b >> d;

	}

	system("pause");
	return 0;
}