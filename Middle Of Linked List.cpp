/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node *findMiddle(Node *head) {
    
    if(head==NULL)
        return NULL;
    
    Node *oneStep = head;
    Node *twoStep = head;

    while (twoStep != NULL && twoStep->next != NULL) {
        oneStep = oneStep->next;          
        twoStep = twoStep->next->next;    
    }

    return oneStep;
}

