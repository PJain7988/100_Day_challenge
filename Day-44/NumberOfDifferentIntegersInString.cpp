#include<bits/stdc++.h>
using namespace std;
int numDifferentIntegers(string word) {
    set<string> integer;
    string num = "";
    for (char c : word) {
        if (isdigit(c)) {
            num += c;
        } else {
            if (!num.empty()) {
                while (num.size() > 1 && num[0] == '0') {
                    num.erase(num.begin());
                }
                integer.insert(num);
                num = "";
            }
        }
    }
    if (!num.empty()) {
        while (num.size() > 1 && num[0] == '0') {
            num.erase(num.begin());
        }
        integer.insert(num);
    }
    return integer.size();
}
int main(){
    string s;
    cin >> s;
    cout<<numDifferentIntegers(s);
    return 0;
}