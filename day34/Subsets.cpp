#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> ans;

void backtrack(vector<int> arr, vector<int> curr, int idx) {
    ans.push_back(curr);

    for(int i=idx; i<arr.size(); i++) {
        curr.push_back(arr[i]);
        backtrack(arr, curr, i+1);
        curr.pop_back();
    }
}

int main() {
    vector<int> arr= {1, 2, 3};
    vector<int> curr;
    backtrack(arr, curr, 0);

    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
