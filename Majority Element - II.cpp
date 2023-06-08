#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int>& arr) {
    vector<int> result;

    if (arr.empty()) {
        return result;
    }

    int num1 = 0, num2 = 0;
    int count1 = 0, count2 = 0;

    // Step 1: Find potential candidates using Boyer-Moore Voting Algorithm
    for (int num : arr) {
        if (num == num1) {
            count1++;
        } else if (num == num2) {
            count2++;
        } else if (count1 == 0) {
            num1 = num;
            count1 = 1;
        } else if (count2 == 0) {
            num2 = num;
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }

    // Step 2: Count the occurrences of potential candidates
    count1 = 0;
    count2 = 0;
    for (int num : arr) {
        if (num == num1) {
            count1++;
        } else if (num == num2) {
            count2++;
        }
    }

    // Step 3: Check if the candidates appear more than n/3 times
    int n = arr.size();
    if (count1 > n / 3) {
        result.push_back(num1);
    }
    if (count2 > n / 3) {
        result.push_back(num2);
    }

    return result;
}