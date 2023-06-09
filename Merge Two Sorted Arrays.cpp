#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	vector<int> result;

	int x = arr1.size();
	int y = arr2.size();

	for(int j=0; j<x; j++)
	{
		if(arr1[j] == 0)
			continue;
		else
			result.push_back(arr1[j]);
	}
		

	for(int j=0; j<y; j++)
	{
		if(arr2[j] == 0)
			continue;
		else
			result.push_back(arr2[j]);
	}

	sort(result.begin(), result.end());

	return result;
}