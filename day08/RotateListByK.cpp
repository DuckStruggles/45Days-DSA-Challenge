#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* rotateByK(Node* head, int k) {
    if(k==0 || head==nullptr || head->next==nullptr) return head;
    Node* tail=head, *newHead, *newTail=head;
    int size=1;

    while(tail->next!=nullptr) {
        tail = tail->next;
        size++;
    }
    tail->next=head;

    k = k%size;
    int steps=size-k-1;

    while(steps) {
        newTail = newTail->next;
        steps--;
    }
    newHead = newTail->next;
    newTail->next = nullptr;

    return newHead;
}

void printList(Node* head) {
    while(head!=NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    int k;

    Node* head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = new Node{4, nullptr};
    head->next->next->next->next = new Node{5, nullptr};

    cout << "Enter value for k: ";
    cin >> k;

    cout << "Original List:\n";
    printList(head);

    cout << "New List:\n";
    printList(rotateByK(head, k));

    return 0;
}