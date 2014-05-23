/*Insertion sort implementation. 
The vector is divided into two parts - a sorted and an unsorted. 
In this method the element is "inserted" in its proper position by shifting all the elements greater than the element from the beginning till the hole.
Complexity is O(n^2) 
Considered to be a better sort than selection and bubble sort.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

void insertionSort(vector<int>& v)
{
	int value;
	int hole;
	for (int i = 1; i < v.size(); ++i)
	{
		value = v[i];
		hole = i;
		while (hole>0 && v[hole - 1] > value) //hole is valid and the adjacent element is greater then shift the element.
		{
			v[hole] = v[hole - 1];
			hole = hole - 1;
		}
		v[hole] = value; //insert element at proper position.
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
	insertionSort(v);
	cout << endl;
	cout << "After sort: ";
	for (auto i : v)
		cout << i << " ";
	system("pause");
}