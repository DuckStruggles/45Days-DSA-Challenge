#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Item {
    int val;
    int weight;
};

bool compare(Item a, Item b) {
    double r1 = (double)a.val/a.weight;
    double r2 = (double)b.val/b.weight;

    return r1>r2;
}

double fractionalKnapsack(int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);
    double totalVal=0.0;

    for(auto item: items) {
        if(capacity >= item.weight) {
            totalVal += item.val;
            capacity -= item.weight;
        } else {
            totalVal += item.val * ((double)capacity/item.weight);
            break;
        }
    }
    return totalVal;
}

int main() {
    int n=5;
    vector<Item> items = {
        {60, 100},
        {100, 20},
        {120, 30}
    };

    int capacity = 50;

    cout << "Maxmimu value = " << fractionalKnapsack(capacity, items) << endl;

    return 0;
}