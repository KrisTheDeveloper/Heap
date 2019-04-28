// Heap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;
/*
6
1 6
1 7
1 8
3
2 8
3
*/

int main()
{
	int input;	
	vector<int> numbers;
	make_heap(numbers.begin(), numbers.end());

	int turns;
	cin >> turns;
	for (int i = 0; i < turns; i++)
	{
		cin >> input;
		if (input == 1)
		{
			cin >> input;
			numbers.push_back(input);
			push_heap(begin(numbers), end(numbers));
		}
		else if (input == 2)
		{
			cin >> input;
			int pos = distance(numbers.begin(), find(numbers.begin(), numbers.end(), input));
			numbers.erase(numbers.begin() + pos);
			pop_heap(numbers.begin() + pos, numbers.end());
		}
		else if (input == 3)
		{
			sort_heap(numbers.begin(), (numbers.begin() + (numbers.size())));
			cout << numbers.front() << endl;
		}
	}
	
	/*
	string line;
	getline(std::cin, line);
	istringstream stream(line);
	while (stream >> input)
		numbers.push_back(input);
	*/
	return 0;
}