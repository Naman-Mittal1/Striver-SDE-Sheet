bool isValidParenthesis(string str) {
    stack<char> parenthesesStack;

    for (char c : str) {
        if (c == '(' || c == '[' || c == '{') {
            parenthesesStack.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (parenthesesStack.empty()) {
                return false;
            }
            char top = parenthesesStack.top();
            parenthesesStack.pop();
            
            // Check if the closing parenthesis matches the top of the stack
            if ((c == ')' && top != '(') || 
                (c == ']' && top != '[') || 
                (c == '}' && top != '{')) {
                return false;
            }
        }
    }

    // If the stack is empty at the end, all parentheses have been matched
    return parenthesesStack.empty();
}
