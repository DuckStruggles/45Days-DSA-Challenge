#include<iostream>
#include<vector>
#include <unordered_set>
using namespace std;

int removeDuplicates(vector<int> &arr) {
    int n=arr.size();
    unordered_set<int> s;
    int idx=0;
    
    for(int i=0; i<n; i++) {
        if(s.find(arr[i]) == s.end()) {
            s.insert(arr[i]);
            arr[idx] = arr[i];
            idx++;
        }
    }
    return s.size();
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "\nEnter elements\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int size = removeDuplicates(arr);
    cout << "New array -> \n";
    for(int i=0; i<size; i++) cout << arr[i] << " ";

    return 0;
}    