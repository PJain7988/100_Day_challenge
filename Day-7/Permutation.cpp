#include<bits/stdc++.h>
using namespace std;

string getPermutation(int n, int k) {
    vector<int> factorial(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        factorial[i] = factorial[i - 1] * i;
    }
    vector<char> digits;
    for (int i = 1; i <= n; i++) {
        digits.push_back('0' + i);
    }
    string result;
    k--;
    for (int i = n; i > 0; i--) {
        int index = k / factorial[i - 1];
        result.push_back(digits[index]);
        digits.erase(digits.begin() + index);
        k %= factorial[i - 1];
    }
    return result;
}
int main(){
    int n,k;
    cin>>n>>k;
    cout<<getPermutation(n,k);
    return 0;
}