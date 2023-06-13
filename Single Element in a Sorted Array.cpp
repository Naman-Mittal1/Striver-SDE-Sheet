int singleNonDuplicate(vector<int>& arr)
{
	int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (mid % 2 == 0) {
            if (arr[mid] == arr[mid + 1]) {
                left = mid + 2;  
            } else {
                right = mid; 
            }
        }
        else {
            if (arr[mid] == arr[mid - 1]) {
                left = mid + 1; 
            } else {
                right = mid - 1;  
            }
        }
    }

    return arr[left];
}