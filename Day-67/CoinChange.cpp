#include<bits/stdc++.h>
using namespace std;
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1,amount+1);
    dp[0] = 0;
    for(int a=0; a<amount+1; a++){
        for(int c: coins){
            if(a-c >= 0){
                dp[a] = min(dp[a], 1+dp[a-c]);
            }
        }
    }
    return dp[amount] == amount+1 ? -1 : dp[amount];   
}
int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int amount;
    cin >> amount;
    cout << coinChange(arr, amount) << endl;
    return 0;
}