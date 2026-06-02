#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* removeNth(Node* head, int n) {
    Node* dummy = new Node{0, head};
    Node* left=dummy;
    Node* right=head;

    while(n>0) {
        right=right->next;
        n--;
    }

    while(right!=nullptr) {
        left=left->next;
        right=right->next;
    }

    left->next=left->next->next;
    return dummy->next;
}

int main() {
    Node* head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = new Node{4, nullptr};
    head->next->next->next->next = new Node{5, nullptr};

    int n=2;

    head = removeNth(head, n);

    cout << "New Linked List\n";
    while(head) {
        cout << head->data << " -> ";
        head=head->next;
    }

    return 0;
}