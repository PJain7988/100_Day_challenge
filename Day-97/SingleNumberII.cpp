#include<bits/stdc++.h>
using namespace std;
int singleNumber(vector<int>& nums) {
    unordered_map<int,int>p;
        for(int i : nums){
            p[i]++;
        }
        for(auto i : p){
            if(i.second == 1){
                return i.first;
            }
        }
        return -1;
    }
int main(){
    int n;
    cin >> n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<singleNumber(nums);
    return 0;
}