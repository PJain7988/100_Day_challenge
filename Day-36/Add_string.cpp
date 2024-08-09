#include<bits/stdc++.h>
using namespace std;
string addStrings(string num1, string num2) {
    string result;
    int carry = 0;
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += num1[i] - '0';
        if (j >= 0) sum += num2[j] - '0';
        carry = sum / 10;
        result.push_back(sum % 10 + '0');
        i--;
        j--;
    }
    reverse(result.begin(), result.end());
    return result;
}
int main(){
    string s,t;
    cin>>s>>t;
    cout<<addStrings(s,t);
    return 0;
}