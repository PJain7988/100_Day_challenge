#include<bits/stdc++.h>
using namespace std;
int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for(string str : tokens) {
        if(str == "+" || str == "-" || str == "*" || str == "/") {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
            int result;
            if(str == "+") {
                result = val2 + val1;
            }
            else if(str == "-") {
                result = val2 - val1;
            }
            else if(str == "*") {
                result = val2 * val1;
            }
            else if(str == "/") {
                result = val2 / val1;
            }
            st.push(result);
        }
        else {
            st.push(stoi(str));
        }
    }
    return st.top();
}
int main(){
    int n;
    cin >> n;
    vector<string> tokens(n);
    for(int i = 0; i < n; i++) {
        cin >> tokens[i];
    }
    cout<<evalRPN(tokens);
    return 0;
}