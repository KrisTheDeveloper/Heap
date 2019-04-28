// Heap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <queue>
#include <set>

using namespace std;
/* better heap
priority_queue<int,vector<int>,greater<int>> pq;
	int q;
	unordered_set<int> s;
	cin>>q;
	for(int i=0;i<q;i++){
		int x,y;
		cin >> x;
		if(x==1){
			cin >> y;
			pq.push(y);
		}
		if(x==2){
			cin >> y;
			s.insert(y);
		}
		if(x==3){
			while(s.find(pq.top())!=s.end()){
				pq.pop();
			}
			cout << pq.top() << endl;
		}
	}
*/

int main()
{
	long input;	
	vector<long> numbers;
	make_heap(numbers.begin(), numbers.end());

	long turns;
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
			cout << *min_element(begin(numbers), end(numbers)) << endl;
		}
	}
	
	return 0;
}