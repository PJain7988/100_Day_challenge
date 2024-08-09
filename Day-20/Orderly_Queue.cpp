#include<bits/stdc++.h>
using namespace std;
string orderlyQueue(string s, int k) {
    if (k == 1) {
        string result = s;
        string temp = s;
        for (int i = 0; i < s.size(); i++) {
            temp = temp.substr(1) + temp[0];
            if (temp < result) {
                result = temp;
            }
        }
        return result;
    } else {
        sort(s.begin(), s.end());
        return s;
    }
}
int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    cout<<orderlyQueue(s,k);
    return 0;
}