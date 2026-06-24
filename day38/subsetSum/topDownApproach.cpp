#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> t;

int subsetSum(vector<int> arr, int sum, int n)
{
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < sum+1; j++) {
            if(j == 0) t[i][j]=true;
            if(i==0) t[i][j] = false;
        }
    }
    t[0][0]=true;

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < sum + 1; j++) {
            if (j >= arr[i-1]) {
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else {
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}

int main()
{
   vector<int> arr={2, 3, 7, 8, 10};
    int n=arr.size();
    int sum=11;

    t.resize(n+1, vector<bool>(sum+1, false));

    bool ans = subsetSum(arr, sum, n);
    if(ans) cout << "Yes there is a subset sum";
    else cout << "No subset sum";

    return 0;
}