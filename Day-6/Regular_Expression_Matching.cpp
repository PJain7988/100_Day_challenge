#include<bits/stdc++.h>
using namespace std;

    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    for (int j = 2; j <= n; ++j) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2];
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (p[j - 2] == s[i - 1] || p[j - 2] == '.'));
            }
        }
    }

    return dp[m][n];
    }
int main(){
    string s,p;
    cin>>s>>p;
    bool result = isMatch(s,p);
    if(result == true)
    cout<<s<<" and "<<p<<" are matched with regular expression."<<endl;
    else
    cout<<s<<" and "<<p<<" are not matched with regular expression."<<endl;
    return 0;
}