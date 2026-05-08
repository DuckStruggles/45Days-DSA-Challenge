#include<iostream>
#include<vector>
using namespace std;

int container(vector<int> arr) {
    int left=0, right=arr.size()-1;
    int ans=0;

    while(left < right) {
        int width = right-left;
        int height = min(arr[left], arr[right]);
        int curr = width * height;

        if(arr[left] < arr[right]) left++;
        else right--;

        ans = max(ans, curr);
    }
    return ans;
}

int main() {
    vector<int> arr = {1,8,6,2,5,4,8,3,7};

    cout << "Maximum amount of water in container is: " << container(arr); 
    return 0;
}