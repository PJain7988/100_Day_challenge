#include<bits/stdc++.h>
using namespace std;
static bool compare(string& a, string& b) {
    return a + b > b + a;
}
string largestNumber(vector<int>& nums) {
    vector<string> numStrings;
    for (int num : nums) {
        numStrings.push_back(to_string(num));
    }
    sort(numStrings.begin(), numStrings.end(), compare);
    if (numStrings[0] == "0") {
        return "0";
    }
    string result;
    for (string numStr : numStrings) {
        result += numStr;
    }
    return result;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<largestNumber(arr);
    return 0;
}