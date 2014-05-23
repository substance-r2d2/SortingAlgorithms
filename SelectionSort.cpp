/*Selection sort implementation. 
Uses simple logic of "selecting" the smallest element from the collection in each iteration and sorting the collection accordingly. 
Complexity is O(n^2) */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

void selectionSort(vector<int>& v)
{
	int temp;
	int iMin;
	for (int i = 0; i < v.size(); ++i)
	{
		iMin = i;
		for (int j = i + 1; j < v.size(); ++j)
		{
			if (v[j] < v[iMin]) //Find the subscript of the smallest element.
				iMin = j;
		}
		temp = v[i]; //Swap the smallest element with the current element. 
		v[i] = v[iMin];
		v[iMin] = temp;
	}
}

int main()
{
	srand(time(0));
	vector<int> v;
	for (int i = 0; i < 10;++i)//randomly generate and fill the vector
		v.push_back(rand() % 15);
	cout << "Before sort: ";
	for (auto i : v)
		cout << i << " ";
	selectionSort(v);
	cout << endl;
	cout << "After sort: ";
	for (auto i : v)
		cout << i << " ";
	system("pause");
}