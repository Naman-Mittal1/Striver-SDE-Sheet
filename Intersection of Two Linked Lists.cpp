/****************************************************************

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

*****************************************************************/

Node* findIntersection(Node* firstHead, Node* secondHead)
{
    if (firstHead == NULL || secondHead == NULL)
        return NULL;

    Node* p1 = firstHead;
    Node* p2 = secondHead;

    while (p1 != p2)
    {
        p1 = (p1 == NULL) ? secondHead : p1->next;
        p2 = (p2 == NULL) ? firstHead : p2->next;
    }

    return p1;
}