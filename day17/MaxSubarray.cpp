#include<iostream>
#include<vector>
using namespace std;

int maxSubarray(vector<int> arr) {
    if(arr.size()==0) return 0;
    
    int sum=arr[0]; // global maxima
    int currSum = arr[0]; //local maxima

    for(int i=1; i<arr.size(); i++) {
        currSum = max(arr[i], arr[i]+currSum);

        sum= max(sum, currSum);
    }
    return sum;
}

int main() {
    int n;

    cout << "Enter array size: ";
    cin >> n;
    vector<int> arr(n);

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << "Maximum subarray sum is: " << maxSubarray(arr);
    return 0;
}