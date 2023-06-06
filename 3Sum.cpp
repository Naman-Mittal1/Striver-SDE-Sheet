#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	vector<vector<int>> triplets;
    
    // Sort the array in ascending order
    sort(arr.begin(), arr.end());

    // Fix the first element and use two-pointer technique to find the remaining two elements
    for (int i = 0; i < n - 2; i++) {
        // Skip duplicate first elements
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        int left = i + 1;
        int right = n - 1;
        int target = K - arr[i];

        while (left < right) {
            int sum = arr[left] + arr[right];

            if (sum == target) {
                triplets.push_back({arr[i], arr[left], arr[right]});

                // Skip duplicate second elements
                while (left < right && arr[left] == arr[left + 1])
                    left++;
                // Skip duplicate third elements
                while (left < right && arr[right] == arr[right - 1])
                    right--;

                left++;
                right--;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }
    
    return triplets;
}