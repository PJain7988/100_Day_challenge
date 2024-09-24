#include<bits/stdc++.h>
using namespace std;
int lengthOfLIS(vector<int>& nums) {
    int n=nums.size();
    int dp[n+1];
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=1;
        for(int j=i-1;j>=1;j--){
            if(nums[i-1]>nums[j-1]){
                dp[i]=max(dp[j]+1,dp[i]);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[i]);
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<lengthOfLIS(a)<<endl;
    return 0;
}