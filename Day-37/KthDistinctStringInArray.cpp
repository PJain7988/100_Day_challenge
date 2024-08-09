#include<bits/stdc++.h>
using namespace std;
string kthDistinct(vector<string>& arr, int k) {
    unordered_map<string,int>f;
    for(int i=0;i<arr.size();i++){
        f[arr[i]]++;
    }
    int c = 0;
    for (auto str : arr) {
        if (f[str] == 1) {
            c++;
            if (c == k) {
                return str;
            }
        }
    }
    return "";
}
int main(){
    int n;
    cin >> n;
    vector<string>str(n);
    for(int i=0;i<n;i++){
        cin>>str[i];
    }
    int k;
    cin>>k;
    cout<<kthDistinct(str,k)<<endl;
    return 0;
}