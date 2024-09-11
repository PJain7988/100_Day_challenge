#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    ans.push_back(vector<int>());
    for(int num : nums){
        int size = ans.size();
        for(int i=0;i<size;i++){
            vector<int> temp = ans[i];
            temp.push_back(num);
            ans.push_back(temp);
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
    vector<vector<int>>ans = subsets(nums);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}