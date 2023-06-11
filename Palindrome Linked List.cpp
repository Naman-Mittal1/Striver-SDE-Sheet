#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

bool isPalindrome(LinkedListNode<int> *head) {
    
    vector<int> values;
    
    LinkedListNode<int> *current = head;
    while (current != nullptr) {
        values.push_back(current->data);
        current = current->next;
    }
    
    int start = 0;
    int end = values.size() - 1;
    
    while (start < end) {
        if (values[start] != values[end]) {
            return false;
        }
        start++;
        end--;
    }
    
    return true;

}