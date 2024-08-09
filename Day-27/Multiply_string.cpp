#include<bits/stdc++.h>
using namespace std;
string multiply(string num1, string num2) {
    int n1 = num1.size();
    int n2 = num2.size();
    if (num1 == "0" || num2 == "0") return "0";
    vector<int> result(n1 + n2, 0);
    for (int i = n1 - 1; i >= 0; i--) {
        for (int j = n2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }
    string resultStr = "";
    for (int i=0;i<result.size();i++) {
        int num = result[i];
        if (!(resultStr.empty() && num == 0)) {
            resultStr += to_string(num);
        }
    }
    return resultStr.empty() ? "0" : resultStr;
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    string result = multiply(s1,s2);
    cout<<result<<endl;
    return 0;
}