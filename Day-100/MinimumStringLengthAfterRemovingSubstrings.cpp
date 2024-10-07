#include<bits/stdc++.h>
using namespace std;
int minLength(string s) {
    int n = s.size();
    stack<char>s1;
    for(int i=0;i<n;i++){
        char c = s[i];
        if(s1.empty()){
            s1.push(c);
        }else if(s1.top()=='A' && c=='B'){
            s1.push(c);
            s1.pop();
            s1.pop();
        }else if(s1.top()=='C' && c=='D'){
            s1.push(c);
            s1.pop();
            s1.pop();
        }else{
            s1.push(c);
        }
    }
    return s1.size();
}
int main(){
    string s;
    cin >> s;
    cout<<minLength(s);
    return 0;
}