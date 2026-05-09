#include<iostream>
#include<vector>
using namespace std;

bool jumpGame(vector<int> arr) {
    int maxReach=0;

    for(int i=0; i<arr.size(); i++) {
        if(i>maxReach) return false;
        maxReach = max(maxReach, arr[i]+i);
    }
    return true;
}

int main() {
    vector<int> arr={2,3,1,2,4,3};

    cout << "End of array can be reached: " << jumpGame(arr) << endl;
    return 0;
}