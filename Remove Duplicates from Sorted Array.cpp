int removeDuplicates(vector<int> &arr, int n) {
	vector<int>arr2;
	arr2.push_back(arr[0]);
	for(int i=0; i<n-1; i++)
	{
		if(arr[i] != arr[i+1])
			arr2.push_back(arr[i+1]);
	}

	return arr2.size();
}