#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> nums,int i,vector<vector<int>>& result) {
    int n=nums.size();
    if(i==n){
        result.push_back(nums);
        return;
    }
    for(int j=i;j<n;j++){
        swap(nums[i],nums[j]);
        solve(nums,i+1,result);
    }
}
vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        solve(nums,0,result);
        return result;
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    vector<vector<int>> result=permute(nums);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}