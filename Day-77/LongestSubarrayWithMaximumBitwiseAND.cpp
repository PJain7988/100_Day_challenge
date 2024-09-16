#include<bits/stdc++.h>
using namespace std;
int longestSubarray(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int temp_length=0;
        int ans=1;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxi) temp_length++;
            else temp_length=0;
            ans=max(ans,temp_length);
        }
        return ans;
    }
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<longestSubarray(v)<<endl;
    return 0;
}