#include<bits/stdc++.h>
using namespace std;
pair<string, int> removeSubstring(const string &s, const string &sub, int points) {
    stack<char> st;
    int total_points = 0;
    for (int i=0;i<s.size();i++) {
        char ch = s[i];
        if (!st.empty() && st.top() == sub[0] && ch == sub[1]) {
            st.pop();
            total_points += points;
        } else {
            st.push(ch);
        }
    }
    string result;
    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }
    reverse(result.begin(), result.end());
    return {result, total_points};
}

int maximumGain(string s, int x, int y) {
    int ab_points = 0, ba_points = 0;
    if (x >= y) {
        pair<string, int> result = removeSubstring(s, "ab", x);
        s = result.first;
        ab_points = result.second;
        
        result = removeSubstring(s, "ba", y);
        s = result.first;
        ba_points = result.second;
    } else {
        pair<string, int> result = removeSubstring(s, "ba", y);
        s = result.first;
        ba_points = result.second;
        
        result = removeSubstring(s, "ab", x);
        s = result.first;
        ab_points = result.second;
    }
    return ab_points + ba_points;
}
int main(){
    string s;
    cin>>s;
    int x,y;
    cin>>x>>y;
    int result = maximumGain(s,x,y);
    cout<<result<<endl;
    return 0;
}