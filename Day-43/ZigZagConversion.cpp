#include<bits/stdc++.h>
using namespace std;
string convert(string s, int numRows) {
    if (numRows == 1 || numRows >= s.length()) {
        return s;
    }
    vector<string> rows(numRows);
    int index = 0;
    int step = 1;
    for (auto c : s) {
        rows[index] += c;
        if (index == 0) {
            step = 1;
        } else if (index == numRows - 1) {
            step = -1;
        }
        index += step;
    }
    string result;
    for (string word : rows) {
        result += word;
    }
    return result;
}
int main(){
    string s;
    cin>>s;
    int n;
    cin>>n;
    cout<<convert(s,n)<<endl;
    return 0;
}