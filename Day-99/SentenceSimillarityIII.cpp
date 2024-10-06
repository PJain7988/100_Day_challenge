#include<bits/stdc++.h>
using namespace std;
vector<string> extract_words(string sentence){
    sentence += " ";
    vector<string> ans;
    string word = "";
    for(int i=0;i<sentence.size();i++){
        if(sentence[i]==' '){
            ans.push_back(word);
            word="";
        }else{
            word += sentence[i];
        }
    }
    return ans;
}
bool areSentencesSimilar(string s1, string s2) {
    if (s1.length() < s2.length()) {
        swap(s1, s2);
    }
    vector<string> ans1, ans2;
    ans1 = extract_words(s1);
    ans2 = extract_words(s2);
    int l = 0;
    while (l < ans2.size() && l < ans1.size() && ans1[l] == ans2[l]) {
        l++;
    }
    int r = 0;
    while (r < ans2.size() && r < ans1.size() && ans1[ans1.size() - 1 - r] == ans2[ans2.size() - 1 - r]) {
        r++;
    }
    return l + r >= ans2.size();  
}
int main(){
    string s1 , s2;
    cin >> s1 >> s2;
    cout << boolalpha << areSentencesSimilar(s1,s2);
    return 0;
}