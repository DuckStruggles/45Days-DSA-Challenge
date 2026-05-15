#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {

    struct Node {
        int key, value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    int cap;
    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

public:

    LRUCache(int capacity) {

        cap = capacity;

        // dummy nodes
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    // insert node right after head
    void insertAfterHead(Node* node) {

        Node* currAfterHead = head->next;

        head->next = node;
        node->prev = head;

        node->next = currAfterHead;
        currAfterHead->prev = node;
    }

    // delete node from doubly linked list
    void deleteNode(Node* node) {

        Node* prevNode = node->prev;
        Node* afterNode = node->next;

        prevNode->next = afterNode;
        afterNode->prev = prevNode;
    }

    int get(int key) {

        // key not present
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        // move node to front
        deleteNode(node);
        insertAfterHead(node);

        return node->value;
    }

    void put(int key, int value) {

        // key already exists
        if (mp.find(key) != mp.end()) {

            Node* node = mp[key];

            node->value = value;

            // move to front
            deleteNode(node);
            insertAfterHead(node);
        }

        // new key
        else {

            // cache full
            if (mp.size() == cap) {

                // least recently used node
                Node* lru = tail->prev;

                mp.erase(lru->key);

                deleteNode(lru);

                delete lru;
            }

            Node* newNode = new Node(key, value);

            insertAfterHead(newNode);

            mp[key] = newNode;
        }
    }

    // helper function to display cache
    void display() {

        Node* temp = head->next;

        cout << "Cache: ";

        while (temp != tail) {
            cout << "[" << temp->key << ":" << temp->value << "] ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {

    LRUCache cache(2);

    cache.put(1, 10);
    cache.display();

    cache.put(2, 20);
    cache.display();

    cout << "Get 1: " << cache.get(1) << endl;
    cache.display();

    cache.put(3, 30); // removes key 2
    cache.display();

    cout << "Get 2: " << cache.get(2) << endl;

    cache.put(4, 40); // removes key 1
    cache.display();

    cout << "Get 1: " << cache.get(1) << endl;
    cout << "Get 3: " << cache.get(3) << endl;
    cout << "Get 4: " << cache.get(4) << endl;

    return 0;
}