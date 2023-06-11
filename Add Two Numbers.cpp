/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node* addTwoNumbers(Node* num1, Node* num2) {
    Node* result = new Node(); 
    Node* curr = result; 
    int carry = 0; 

    while (num1 != NULL || num2 != NULL || carry != 0) {
        int sum = carry;

        if (num1 != NULL) {
            sum += num1->data;
            num1 = num1->next;
        }

        if (num2 != NULL) {
            sum += num2->data;
            num2 = num2->next;
        }

        curr->next = new Node(sum % 10);
        curr = curr->next; 
        carry = sum / 10; 
    }

    Node* head = result->next; // Head of the resulting linked list
    delete result; // Delete the dummy head node

    return head;
}
