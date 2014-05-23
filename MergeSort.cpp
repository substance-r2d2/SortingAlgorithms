/*Merge sort implementation.
The collection is divided into sub collections(of possible equal size) and then these sub-collections are "merged" in a sorted manner.
Complexity is O(n log n) but space complexity of O(n).
Merge sort is stable sort and is a recursive method but no an inplace algorithm.
It is a divide and conquer algorithm.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int>& l,vector<int>& r,vector<int>& v) //the left and right subvector are merged into vector v.
{
	int nl = l.size();
	int nr = r.size();
	int i = 0, j = 0, k = 0;
	//inserted in proper order in vector v.
	while (i < nl && j < nr) 
	{
		if (l[i] <= r[j])
		{
			v[k] = l[i];
			++i;
		}
		else
		{
			v[k] = r[j];
			++j;
		}
		++k;
	}
	//remaining elements are then inserted in v.
	while (i < nl)
	{
		v[k] = l[i];
		++i;
		++k;
	}
	while (j < nr)
	{
		v[k] = r[j];
		++j;
		++k;
	}
}

void mergeSort(vector<int> &v)
{
	int n = v.size();
	if (n < 2)
		return;
	int mid = n / 2;
	//divide the vector in two parts.
	vector<int> left(mid);
	vector<int> right(n - mid);
	for (int i = 0; i < mid; ++i)
		left[i] = v[i];
	for (int i = mid; i < v.size(); ++i)
		right[i-mid] = v[i];
	//sort left and right sub-vector.
	mergeSort(left);
	mergeSort(right);
	//merge them into vector v.
	merge(left, right, v);
}

int main()
{
	srand(time(0));
	vector<int> v;
	int insert;
	for (int i = 0; i < 8; ++i)//randomly generate and fill the vector with unique numbers
	{
		insert = rand() % 15;
		if (find(v.begin(),v.end(),insert)==v.end())
			v.push_back(insert);
	}
	cout << "Before sort: ";
	for (auto i : v)
		cout << i << " ";
	mergeSort(v);
	cout << endl;
	cout << "After sort: ";
	for (auto i : v)
		cout << i << " ";
	system("pause");
}