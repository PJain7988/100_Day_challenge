#include<bits/stdc++.h>
using namespace std;
int partitionString(string s) {
    int n = s.length();
    int i = 0;
    int cnt = 1;
    unordered_map<char,int> mp;
    while(i<n){
    if(mp.size()==0){
        mp[s[i]]=1;
    }
    else if(mp.find(s[i])==mp.end()){
        mp[s[i]] = 1;
    }
    else{
        cnt++;
        mp.clear();
        mp[s[i]]=1;
    }
    i++;
    }
    return cnt;
}
int main(){
    string s;
    cin >> s;
    cout<<partitionString(s);
    return 0;
}