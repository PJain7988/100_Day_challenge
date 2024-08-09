#include<bits/stdc++.h>
using namespace std;
int maxProduct(vector<int>& nums) {
    double max1 = 1;
    double max2 = 1;
    int ans = INT_MIN;
    for(int i=0;i<nums.size();i++){ 
        if(max1==0) max1 = 1;
        if(max2==0) max2 = 1;
        max1 *= (nums[i]);
        max2 *= (nums[nums.size()-i-1]);
        double temp = max1;
        if(max1 < max2) temp = max2;
        if(ans < temp) ans = temp;
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    cout << maxProduct(nums) << endl;
    return 0;
}