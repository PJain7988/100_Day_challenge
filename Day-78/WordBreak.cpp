#include<bits/stdc++.h>
using namespace std;
bool wordBreak(string& s, vector<string>& wordDict) {
        string a = "";
        vector<int> dp(s.length());
        for (int i = 0; i < s.length(); i++) {
            for (auto& str : wordDict) {
                if (i  <str.length() - 1)
                    continue;
                if (i == str.length() - 1 || dp[i - str.length()])
                    if (str == s.substr(i-str.length()+1,str.length())) {
                        dp[i] = 1;
                        break;
                    }
            }
        }
        return dp[s.length()-1];
    }
int main(){
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> wordDict(n);
    for (int i = 0; i < n; i++) {
        cin >> wordDict[i];
    }
    cout<<wordBreak(s,wordDict);
    return 0;
}