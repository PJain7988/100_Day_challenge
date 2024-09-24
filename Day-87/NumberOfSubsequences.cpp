#include<bits/stdc++.h>
using namespace std;
int numSubseq(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    long ans = 0;
    int k = 1'000'000'007;
    vector<long> dp(n + 1, 1);
    for(int i = 1; i <= n; ++i){
        dp[i] = (dp[i - 1] << 1) % k;
    }
    for(int i = 0, j = n - 1; i < n; ++i){
        while(j >= i && nums[i] + nums[j] > target) {
            j--;
        }
        if(i > j){
            continue;
        } 
        ans = (ans + dp[j - i]) % k; 
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i){
        cin >> nums[i];
    }
    int target;
    cin >> target;
    cout<<numSubseq(nums,target);
    return 0;
}