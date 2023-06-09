#include <bits/stdc++.h>

string fourSum(vector<int>& arr, int target, int n) {
    if (n < 4) {
        return "No";
    }

    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 3; i++) {
        for (int j = i + 1; j < n - 2; j++) {
            int left = j + 1;
            int right = n - 1;
            int remaining = target - arr[i] - arr[j];

            while (left < right) {
                int sum = arr[left] + arr[right];
                if (sum == remaining) {
                    return "Yes";
                } else if (sum < remaining) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    return "No";
}

