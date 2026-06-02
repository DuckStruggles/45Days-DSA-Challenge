#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* middle(Node* head) {
    Node* slow=head;
    Node* fast=head;

    while(fast && fast->next) {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

Node* reverse(Node* head) {
    Node *curr=head, *prev=nullptr, *nxt;

    while(curr) {
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    return prev;
}

void reorderList(Node* head) {
    if(!head || !head->next) return;

    Node *mid = middle(head);
    Node *second=reverse(mid->next);
    mid->next=nullptr;

    Node *first=head;

    while(second) {
        Node* t1=first->next;
        Node* t2=second->next;

        first->next=second;
        second->next=t1;

        first=t1;
        second=t2;
    }
}

int main() {
    Node* head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = new Node{4, nullptr};
    head->next->next->next->next = new Node{5, nullptr};

    reorderList(head);

    while(head) {
        cout << head->data << " -> ";
        head = head->next;
    }

    return 0;
}