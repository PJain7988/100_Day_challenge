#include<bits/stdc++.h>
using namespace std;
int triangleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int count = 0;
    int n = nums.size();
    for (int i = n-1 ; i >= 2 ; i--) {
        int left = 0, right = i - 1;
        while(left < right){
            if(nums[left] + nums[right] > nums[i]) {
                count += (right - left);
                right--;
            }else{
                left++;
            }
        }
    }
    return count;
}
int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << triangleNumber(arr) << endl;
    return 0;
}