#include<bits/stdc++.h>
using namespace std;

string reverseParentheses(string s) {
    stack<char> st;
    char ch;
    for (int i=0;i<s.size();i++) {
        ch = s[i];
        if (ch == ')') {
            string temp;
            while (st.empty() == false && st.top() != '(') {
                temp += st.top();
                st.pop();
            }
            st.pop();
            for (int i=0; i<temp.length(); i++) {
                 st.push(temp[i]);
            }
        } else {
            st.push(ch);
        }
    }
        string result;
    while (st.empty() == false) {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}
int main(){
    string s;
    cin>>s;
    string result = reverseParentheses(s);
    cout<<result<<endl;
    return 0;
}