#include <bits/stdc++.h> 

void generatePermutations(string& s, int start, vector<string>& result) {
    if (start == s.length() - 1) {
        result.push_back(s);
        return;
    }

    for (int i = start; i < s.length(); i++) {
        swap(s[start], s[i]);
        generatePermutations(s, start + 1, result);
        swap(s[start], s[i]);  // Backtracking
    }
}

vector<string> findPermutations(string& s) {
    vector<string> result;
    generatePermutations(s, 0, result);
    return result;
}
