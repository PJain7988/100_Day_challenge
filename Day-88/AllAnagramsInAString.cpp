#include<bits/stdc++.h>
using namespace std;
bool check(vector<int> &v){
        for(auto &i: v)
        if(i)return false;
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> v(26,0);
        for(auto &i: p){
            v[i-'a']++;
        }
        vector<int> ans;
        for(int i = 0; i < s.length(); i++){
            v[s[i]-'a']--;
            if(i>=p.length()-1){
                if(check(v)){
                    ans.push_back(i-p.length()+1);
                }
                v[s[i-p.length()+1]-'a']++;
            }
        }
        return ans;
    }
int main(){
    string s,p;
    cin>>s>>p;
    vector<int> ans = findAnagrams(s,p);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}