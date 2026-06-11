#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> kClosest(vector<int> arr, int k, int x) {
    priority_queue<pair<int, int>> p; //max heap
    vector<int> ans;

    for(int i=0; i<arr.size(); i++) {
        p.push({abs(arr[i]-x), arr[i]});
        if(p.size() > k) p.pop();
    }

    while(p.size() > 0) {
        ans.push_back(p.top().second);
        p.pop();
    }

    //sort the ans if you want
    return ans;
}

int main() {
    vector<int> arr = {1,2,3,4,5};
    int k=4;
    int x=3;

    vector<int> ans = kClosest(arr, k, x);
    
    cout << "K closest elements are: ";
    for(int i: ans) {
        cout << i << " ";
    }
}