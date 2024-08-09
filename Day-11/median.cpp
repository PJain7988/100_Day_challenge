#include<bits/stdc++.h>
using namespace std;
 double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;

        while (low <= high) {
            int partition1 = (low + high) / 2;
            int partition2 = (m + n + 1) / 2 - partition1;

            int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];
            int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];

            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                if ((m + n) % 2 == 0) {
                    return ((double)max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2;
                } else {
                    return (double)max(maxLeft1, maxLeft2);
                }
            } else if (maxLeft1 > minRight2) {
                high = partition1 - 1;
            } else {
                low = partition1 + 1;
            }
        }

        throw invalid_argument("Input arrays are not sorted.");
    }
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> nums1(n);
    vector<int> nums2(m);
    for(int i=0;i<n;i++){
        cin>>nums1[i];
    }
    for(int i=0;i<m;i++){
        cin>>nums2[i];
    }
    cout<<findMedianSortedArrays(nums1,nums2);
    return 0;
}