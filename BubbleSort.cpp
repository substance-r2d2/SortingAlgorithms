/*Bubble sort implementation. 
In each iteration element is checked with its adjacent element, if the element is greater than its adjacent then they are swapped.
This way the largest element "bubbles up" to the last position ,second largest to second last position and so on.
Complexity is O(n^2) */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

void bubbleSort(vector<int>& v)
{
	int temp;
	for (int k = 1; k < v.size(); ++k)
	{
		int flag = 0; //to check if the pass actually swaps any elements
		for (int i = 0; i < (v.size() - k); ++i)//check only till the unsorted part of vector
		{
			if (v[i]>v[i + 1]) //check if adjacent is greater
			{
				temp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0) //no swap means already sorted.
			break;
	}
}

int main()
{
	srand(time(0));
	vector<int> v;
	int insert;
	for (int i = 0; i < 10; ++i)//randomly generate and fill the vector with unique numbers
	{
		insert = rand() % 15;
		if (find(v.begin(),v.end(),insert)==v.end())
			v.push_back(insert);
	}
	cout << "Before sort: ";
	for (auto i : v)
		cout << i << " ";
	bubbleSort(v);
	cout << endl;
	cout << "After sort: ";
	for (auto i : v)
		cout << i << " ";
	system("pause");
}