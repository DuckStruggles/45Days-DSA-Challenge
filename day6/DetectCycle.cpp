#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool detectCycle(Node* head) {
    if(head == nullptr) return false;

    Node* slow=head;
    Node* fast=head;

    while(fast!=nullptr && fast->next!=nullptr) {
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast) return true;
    }
    return false;
}

int main() {
    Node* head=new Node{1, nullptr};
    head->next=new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = new Node{4, nullptr};
    head->next->next->next->next = new Node{5, nullptr};

    //testing 
    head->next->next->next->next->next = head->next;

    bool hasCycle = detectCycle(head);

    cout << "Cycle detected: " << (hasCycle ? "True" : "False") << endl;
}