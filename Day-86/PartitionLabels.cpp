#include<bits/stdc++.h>
using namespace std;
vector<int> partitionLabels(string s) {
    int arr[26] = {0};
    vector<int> result;
    int last = 0;
    for(int i = 0; i < s.size(); i++){
        arr[s[i] - 'a'] = i;
    }
    int left = 0, right = arr[s[left] - 'a'];
    while(right < s.size() && left < s.size()){
        right = arr[s[left] - 'a'];
        while(left < right){
            if(arr[s[left] - 'a'] > right){
                right = arr[s[left] - 'a'];
            }
            left++;
        }   
        result.push_back(right - last + 1);
        last = right+ 1;    
        left++;
    }
    return result;
}
int main(){
    string s;
    cin >> s;
    vector<int>ans = partitionLabels(s);
    cout << "[";
    for(int i=0;i<ans.size();i++){
        cout << ans[i];
        if(i != ans.size()-1) cout << ", ";
    }
    cout << "]";
    return 0;
}