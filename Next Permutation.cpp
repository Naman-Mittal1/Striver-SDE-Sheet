#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    int dipIndex = -1;

    for (int i = n - 2; i >= 0; --i) {
        if (permutation[i] < permutation[i + 1]) {
            dipIndex = i;
            break;
        }
    }

    if (dipIndex == -1) {
        reverse(permutation.begin(), permutation.end());
        return permutation;
    }

    int swapIndex = dipIndex + 1;
    for (int i = dipIndex + 1; i < n; ++i) {
        if (permutation[i] > permutation[dipIndex] && permutation[i] <= permutation[swapIndex]) {
            swapIndex = i;
        }
    }
    swap(permutation[dipIndex], permutation[swapIndex]);

    reverse(permutation.begin() + dipIndex + 1, permutation.end());

    return permutation;
}