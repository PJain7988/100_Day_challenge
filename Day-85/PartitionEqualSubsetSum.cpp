#include<bits/stdc++.h>
using namespace std;
bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }

        if(sum % 2 == 1){
            return false;
        }
        sum /= 2; // sum required 


        int dp[n+1][sum+1]; 
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= sum; j++){
                if(i == 0) dp[i][j] = 0;
                else if(j == 0) dp[i][j] = 1;
                else dp[i][j] = 0;
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= sum; j++){
                if(nums[i-1] <= j){
                    dp[i][j] = (dp[i][j] || dp[i-1][j] || dp[i-1][j-nums[i-1]]);
                }
                else dp[i][j] = (dp[i][j] || dp[i-1][j]);
            }
        }

        return dp[n][sum];
    }
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    cout << canPartition(nums) << endl;
    return 0;
}