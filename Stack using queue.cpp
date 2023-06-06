#include <bits/stdc++.h> 

class Stack {
    queue<int> q1;
    queue<int> q2;
    
public:
    Stack() {
        // Constructor
    }

    int getSize() {
        return q1.size();
    }

    bool isEmpty() {
        return q1.empty();
    }

    void push(int element) {
        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(element);

        // Move back all elements from q2 to q1
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop() {
        if (isEmpty())
            return -1; // or any other appropriate error handling

        int topElement = q1.front();
        q1.pop();
        return topElement;
    }

    int top() {
        if (isEmpty())
            return -1; // or any other appropriate error handling
        
        return q1.front();
    }
};