#include <bits/stdc++.h>

string reverseString(string &str) {
    reverse(str.begin(), str.end());
    
    int n = str.length();
    int start = 0;
    int end = 0;
    int i = 0;
    
    while (i < n) {
        while (i < n && str[i] == ' ') {
            i++;
        }
        
        if (i == n) {
            break;
        }
        
        if (end > 0) {
            str[end] = ' ';
            end++;
        }
        
        start = end;
        
        while (i < n && str[i] != ' ') {
            str[end] = str[i];
            i++;
            end++;
        }
        
        reverse(str.begin() + start, str.begin() + end);
    }
    
    str.resize(end);
    
    // Remove leading spaces
    size_t firstNonSpace = str.find_first_not_of(' ');
    if (firstNonSpace != string::npos) {
        str = str.substr(firstNonSpace);
    }
    
    // Remove trailing spaces
    size_t lastNonSpace = str.find_last_not_of(' ');
    if (lastNonSpace != string::npos) {
        str = str.substr(0, lastNonSpace + 1);
    }
    
    return str;
}