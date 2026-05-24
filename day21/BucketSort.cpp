#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void bucketSort(vector<int> &arr) {
    int n=arr.size();

    if(n==0) return;

    int maxVal = *max_element(arr.begin(), arr.end());

    //create buckets
    int bucketCount = 10;
    vector<vector<int>> buckets(bucketCount);

    for(int num: arr) {
        int bucketIndex = (num * bucketCount) / (maxVal + 1);
        buckets[bucketIndex].push_back(num);
    }

    // sort buckets
    for(int i=0; i<bucketCount; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    int idx=0;

    for(int i=0; i<bucketCount; i++) {
        for(int num: buckets[i]) {
            arr[idx++] = num;
        }
    }
}

int main() {
    vector<int> arr={10, 5, 11, 15, 20, 30, 23, 21};
    bucketSort(arr);

    for(int i: arr){
        cout << i << " ";
    }

    return 0;
}