bool isPalindrome(const string& str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void partitionHelper(const string& s, int start, vector<string>& currentPartition, vector<vector<string>>& result) {
    if (start >= s.length()) {
        // All characters have been processed, add current partition to the result
        result.push_back(currentPartition);
        return;
    }
    
    for (int i = start; i < s.length(); i++) {
        if (isPalindrome(s, start, i)) {
            // If the substring from 'start' to 'i' is a palindrome, add it to the current partition
            string palindrome = s.substr(start, i - start + 1);
            currentPartition.push_back(palindrome);
            
            // Recursively find partitions for the remaining string
            partitionHelper(s, i + 1, currentPartition, result);
            
            // Backtrack and remove the last added palindrome for the next iteration
            currentPartition.pop_back();
        }
    }
}

vector<vector<string>> partition(string& s) {
    vector<vector<string>> result;
    vector<string> currentPartition;
    
    partitionHelper(s, 0, currentPartition, result);
    
    return result;
}