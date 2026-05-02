#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int countNodes(Node* head) {
    int count=0;
    while(head!=NULL) {
        count++;
        head=head->next;
    }

    return count;
}

int main() {
    Node* head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = new Node{4, nullptr};
    head->next->next->next->next = new Node{5, nullptr};

    int count = countNodes(head);
    cout << "Number of nodes are: " << count << endl;

    return 0;
}