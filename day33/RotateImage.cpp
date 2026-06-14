#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<vector<int>> mat={{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n=mat.size();
    int k=n-1;

    for(int i=0; i<n >> 1; i++) {
        for(int j=i; j<k-i; j++) {
            int temp = mat[i][j];
            mat[i][j]=mat[k-j][i];
            mat[k-j][i] = mat[k-i][k-j];
            mat[k-i][k-j]=mat[j][k-i];
            mat[j][k-i] = temp;
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}