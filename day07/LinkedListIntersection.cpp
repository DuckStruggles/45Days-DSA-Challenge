// find where two linked lists merge, linked lists are of equal length
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int instersectionNode(Node* headA, Node* headB) {
    int ans = -1;

    while(headA && headB) {
        if(headA == headB) return headA->data;

        headA = headA->next;
        headB = headB->next;
    }
    return ans;
}

int main() {
    Node* common = new Node{7, nullptr};
    common->next = new Node{9, nullptr};

    // List A: 1 → 3 → 5 → 7 → 9
    Node* headA = new Node{1, nullptr};
    headA->next = new Node{3, nullptr};
    headA->next->next = new Node{5, nullptr};
    headA->next->next->next = common;

    //List B: 2 → 4 → 6 → 7 → 9
    Node* headB = new Node{2, nullptr};
    headB->next = new Node{4, nullptr};
    headB->next->next = new Node{6, nullptr};
    headB->next->next->next = common;

    cout << "Intersection at node value: " << instersectionNode(headA, headB);

    return 0;
}