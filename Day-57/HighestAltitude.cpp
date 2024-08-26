#include<bits/stdc++.h>
using namespace std;
int largestAltitude(vector<int>& gain) {
    int n = gain.size();
    vector<int>dp(n+1,0);
    int max = dp[0];
    for(int i=0;i<n;i++){
        dp[i+1]=dp[i]+gain[i];
        if(dp[i+1]>max){
            max = dp[i+1];
        }
    }
    return max;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<largestAltitude(arr)<<endl;
    return 0;
}