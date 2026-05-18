#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int> &arr) {
    int n=arr.size();

    for(int i=1; i<n; i++) {
        int key=arr[i];
        int j=i-1;

        while(j>=0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main() {
    int n;

    cout << "Enter number of elements in array: ";
    cin>> n;

    vector<int> arr(n);

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    insertionSort(arr);

    cout << "Elements of the array are:\n";

    for(int i: arr) {
        cout << i << " ";
    }
}