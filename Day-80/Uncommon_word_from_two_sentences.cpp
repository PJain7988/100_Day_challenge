#include<bits/stdc++.h>
using namespace std;
vector<string> uncommonFromSentences(string s1, string s2) {
        string s = s1 + " " + s2;
        unordered_map<string,int> um;
        string tmp="";
        for(auto& val : s){ 
            if(val == ' '){
                um[tmp]++;
                tmp = "";
            }
            else{
                tmp += val; 
            }
        }
        if(tmp != ""){
            um[tmp]++;
            tmp = "";
        }
        vector<string> ans;
        for(auto& val:um){ 
            if(val.second==1){
                ans.emplace_back(val.first); 
            }

        }
        return ans;
    }
int main(){
    string s1 , s2;
    cin >> s1 >> s2;
    vector<string>ans = uncommonFromSentences(s1,s2);
    for(auto& val:ans){
        cout<<ans<<" ";
    }
    return 0;
}