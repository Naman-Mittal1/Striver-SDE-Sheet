#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	int majorityElement = arr[0];
    int count = 1;

	// sort(arr, arr+n);

    for (int i = 1; i < n; i++) {
        if (arr[i] == majorityElement) {
            count++;
        } else {
            count--;
            if (count == 0) {
                majorityElement = arr[i];
                count = 1;
            }
        }
    }

    // Check if the majority element is valid
    count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == majorityElement) {
            count++;
        }
    }

    if (count > n / 2) {
        return majorityElement;
    }

    return -1;  // No majority element found
}