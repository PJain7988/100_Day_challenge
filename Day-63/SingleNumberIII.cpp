#include<bits/stdc++.h>
using namespace std;
vector<int> singleNumber(vector<int>& nums) {
    vector<int>arr;
    unordered_map<int,int>f;
    for(int i=0;i<nums.size();i++){
        f[nums[i]]++;
    }
    for(auto i: f){
        if(i.second == 1){
            arr.push_back(i.first);
        }
    }
    return arr;
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int>ans = singleNumber(nums);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}