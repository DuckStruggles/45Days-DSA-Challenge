#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* mergeTwoList(Node* head1, Node* head2) {
    if(head1==nullptr && head2==nullptr) return nullptr;
    if(head1==nullptr) return head2;
    if(head2==nullptr) return head1;

    Node dummy;
    Node* head3 = &dummy;

    while(head1 && head2) {
        if(head1->data < head2->data) {
            head3->next=head1;
            head1=head1->next;
        }
        else {
            head3->next=head2;
            head2=head2->next;
        }
        head3=head3->next;
    }
    if(head1 != nullptr) {
        head3->next=head1;
    }
    else if(head2 != nullptr) {
        head3->next=head2;
    }
    return dummy.next;
}

int main() {
    Node* head1 = new Node{1, nullptr};
    head1->next = new Node{2, nullptr};
    head1->next->next = new Node{4, nullptr};

    Node* head2 = new Node{1, nullptr};
    head2->next = new Node{3, nullptr};
    head2->next->next = new Node{4, nullptr};

    Node* head3 = mergeTwoList(head1, head2);

    cout << "Merged List\n";
    while(head3) {
        cout << head3->data << " -> ";
        head3=head3->next;
    }
    return 0;
}