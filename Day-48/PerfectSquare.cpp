#include<bits/stdc++.h>
using namespace std;
int numSquares(int n) {
    if(n<=0){
        return 0;
    }
    vector<int> dp(n+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j*j<=i;j++)
            dp[i]=min(dp[i],1+dp[i-j*j]); 
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    cout<<numSquares(n)<<endl;
    return 0;
}