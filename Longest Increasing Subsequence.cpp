#include<bits/stdc++.h>

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> maxSize;
  
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(maxSize.begin(), maxSize.end(), arr[i]);
        if (it == maxSize.end()) {
            maxSize.push_back(arr[i]);
        } else {
            *it = arr[i];
        }
    }

    return maxSize.size();
}
