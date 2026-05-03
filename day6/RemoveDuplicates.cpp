#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* removeDup(Node* head) {
    if(head->next == nullptr) return head;

    Node* temp = head;
    while(temp->next != nullptr) {
        if(temp->data == temp->next->data) {
            Node* newNode = temp->next;
            temp->next = temp->next->next;
            delete newNode;
        }
        else{
            temp=temp->next;
        }
    }
    return head;
}

void printList(Node* head) {
    while(head!=NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = new Node{1, nullptr};
    head->next = new Node{1, nullptr};
    head->next->next = new Node{1, nullptr};
    head->next->next->next = new Node{2, nullptr};
    head->next->next->next->next = new Node{3, nullptr};

    head = removeDup(head);

    cout << "New list \n";
    printList(head);
    return 0;
}