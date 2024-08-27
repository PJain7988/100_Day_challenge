#include<bits/stdc++.h>
using namespace std;
int longestOnes(vector<int>& nums, int k) {
    int Max = 0; 
    int low = 0; 
    int high = 0; 
    int zeros = 0; 
    while (high < nums.size()){
        if (nums[high] == 0) 
            zeros++;
        while (zeros > k){
            if (nums[low] == 0) 
                zeros--;
            low++;
        }
        Max = max(Max, high - low + 1);
        high++;
    }
    return Max;
}
int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout << longestOnes(arr, k);
    return 0;
}