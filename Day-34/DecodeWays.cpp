#include<bits/stdc++.h>
using namespace std;

int numDecodings(string s) {
    if (s.empty() || s[0] == '0') return 0;
    int n = s.size();
    vector<int> arr(n + 1, 0);
    arr[0] = 1;
    for (int i = 1; i <= n; ++i) {
        if (s[i-1] != '0') {
            arr[i] += arr[i-1];
        }
        if (i > 1 && (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6'))) {
            arr[i] += arr[i-2];
        }
    }

    return arr[n];
}
int main(){
    string s;
    cin>>s;
    cout<<numDecodings(s)<<endl;
    return 0;
}