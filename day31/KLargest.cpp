#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements:\n";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << "Enter value of K: ";
    cin >> k;

    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i: arr) {
        minHeap.push(i);
        if(minHeap.size() > k) {
            minHeap.pop();
        }
    }

    cout << "Kth largest element in the array is: " << minHeap.top();
    return 0;
}