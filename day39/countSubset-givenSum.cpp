#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> t;

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
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
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
   vector<int> arr={2, 3, 5, 7, 8, 10};
    int n=arr.size();
    int sum=10;

    t.resize(n+1, vector<int>(sum+1, false));

    int ans = subsetSum(arr, sum, n);
    cout << "Number of subsets with given sum is =\t" << ans <<endl;

    return 0;
}