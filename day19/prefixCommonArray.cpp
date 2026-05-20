#include<iostream>
#include<vector>
using namespace std;

void findPrefixCommonArray(vector<int> A, vector<int> B, vector<int> &C) {
    int n = A.size();
    vector<int> freqArr(n+1, 0);
    int countTwos=0;

    for(int i=0; i<n; i++) {
        freqArr[A[i]]++;
        if(freqArr[A[i]] == 2) countTwos++;

        freqArr[B[i]]++;
        if(freqArr[B[i]] == 2) countTwos++;

        C[i]=countTwos;
    }
}

int main() {
    int n;

    cout << "Enter array size: ";
    cin >> n;
    vector<int> A(n);
    vector<int> B(n);

    cout << "Enter elements of 1st array: ";
    for(int i=0; i<n; i++) {
        cin >> A[i];
    }

    cout << "Enter elements of 2nd array: ";
    for(int i=0; i<n; i++) {
        cin >> B[i];
    }

    vector<int> C(n); 
    findPrefixCommonArray(A, B, C);

    cout << "Prefix common array:\n";
    for(int i=0; i<C.size(); i++) {
        cout << C[i] << " ";
    }
    return 0;
}