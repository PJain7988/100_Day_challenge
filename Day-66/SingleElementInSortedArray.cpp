#include<bits/stdc++.h>
using namespace std;
int singleNonDuplicate(vector<int>& nums) {
    unordered_map<int,int>f;
    int ans = 0;
    int n = nums.size();
    for(int i=0;i<n;i++){
        f[nums[i]]++;
    }
    for(auto i : f){
        if(i.second == 1){
            ans = i.first;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<singleNonDuplicate(nums);
    return 0;
}