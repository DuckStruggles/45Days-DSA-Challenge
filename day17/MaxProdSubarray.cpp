#include<iostream>
#include<vector>
using namespace std;

int maxProd(vector<int> arr) {
    int maxP=arr[0];
    if(arr.size() == 1) return maxP;

    int prevMax=arr[0];
    int prevMin=arr[0];

    for(int i=1; i<arr.size(); i++) {
        if(arr[i]<0) swap(prevMax, prevMin);

        prevMax=max(arr[i], arr[i]*prevMax);
        prevMin=min(arr[i], arr[i]*prevMin);

        maxP = max(maxP, prevMax);
    }
    return maxP;
}

int main() {
    int n;

    cout << "Enter array size: ";
    cin >> n;
    vector<int> arr(n);

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << "Maximum product from subarray is: " << maxProd(arr);
    return 0;
}