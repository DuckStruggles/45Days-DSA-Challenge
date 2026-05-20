#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* findMiddle(Node *head) {
    Node* slow=head;
    Node* fast=head;

    while( (fast != NULL) && (fast->next!=NULL)) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    Node* head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = new Node{4, nullptr};
    head->next->next->next->next = new Node{5, nullptr};    

    Node* mid = findMiddle(head);
    cout << "Middle element is: " << mid->data << endl;
}