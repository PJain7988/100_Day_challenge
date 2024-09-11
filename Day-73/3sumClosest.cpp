#include<bits/stdc++.h>
using namespace std;
int threeSumClosest(vector<int>& nums, int target) 
    {
        if(nums.size() == 3)
            return nums[0] + nums[1] + nums[2];

        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size(); ++ i)
        {
            int left = i + 1;
            int right = nums.size() - 1;
            int targetSum = target - nums[i];

            while (left < right)
            {
                int temp = nums[left] + nums[right];
                
                if(abs(temp + nums[i] - target) < abs(ans - target))
                    ans = temp + nums[i];

                if(temp < targetSum)
                    left++;
                else if (temp > targetSum)
                    right--;
                else
                {
                    return target;
                }
            }
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
    int target;
    cin >> target;
    cout<<threeSumClosest(nums,target);
    return 0;
}