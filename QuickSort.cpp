/*Quick sort implementation.
In this method we select a pivot and all the elements smaller than the pivot are moved to left of the pivot 
and all the elemets greater than the pivot to the right. 
Complexity is O(n^2) in worst case but in average case its O(n log n).The worst case behaviour is rare.
Quick sort is an partitioning inplace algorithm. 
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int partition(vector<int>& v, int start, int end)
{
	int pivot = v[end];
	int pIndex = start;
	for (int i = start; i < end; ++i)
	{
		if (v[i] <= pivot) //Arrange the elements accordingly.
		{
			swap(v[i], v[pIndex]);
			++pIndex;
		}
	}
	swap(v[pIndex], v[end]); //swap the pivot and element at partition index. 
	return pIndex;
}

void quickSort(vector<int>& v, int start, int end)
{
	if (start <  end){
		int pIndex = partition(v, start, end);
		//recursively call the function.
		quickSort(v, start, pIndex - 1);
		quickSort(v, pIndex + 1, end);
	} 
}

int main()
{
	srand(time(0));
	vector<int> v;
	int insert;
	int count = 0;
	while (count<8)//randomly generate and fill the vector with unique numbers
	{
		insert = rand() % 15;
		if (find(v.begin(), v.end(), insert) == v.end())
		{
			v.push_back(insert);
			++count;
		}
	}
	cout << "Before sort: ";
	for (auto i : v)
		cout << i << " ";
	quickSort(v,0,7);
	cout << endl;
	cout << "After sort: ";
	for (auto i : v)
		cout << i << " ";
	system("pause");
}