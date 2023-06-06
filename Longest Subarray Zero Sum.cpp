#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  unordered_map<int, int> prefixSum; 
    int maxLength = 0;
    int sum = 0;

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        if (sum == 0) {
            maxLength = i + 1; 
        } else {
            if (prefixSum.count(sum) > 0) {
                maxLength = max(maxLength, i - prefixSum[sum]);
            } else {
                prefixSum[sum] = i;
            }
        }
    }

    return maxLength;

}