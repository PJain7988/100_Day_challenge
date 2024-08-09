#include <bits/stdc++.h>
using namespace std;

vector<int> getMax(vector<int> &nums, int t)
{
    int n = nums.size();
    vector<int> result;
    int to_pop = n - t;

    for (int num : nums)
    {
        while (to_pop > 0 && !result.empty() && result.back() < num)
        {
            result.pop_back();
            to_pop--;
        }
        result.push_back(num);
    }
    result.resize(t);

    return result;
}
bool isGreater(vector<int> &nums1, int i, vector<int> &nums2, int j)
{
    while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j])
    {
        i++;
        j++;
    }
    return j == nums2.size() || (i < nums1.size() && nums1[i] > nums2[j]);
}
vector<int> merge(vector<int> &nums1, vector<int> &nums2)
{
    int m = nums1.size(), n = nums2.size();
    vector<int> result(m + n, 0);
    int i = 0, j = 0;

    for (int k = 0; k < m + n; ++k)
    {
        if (isGreater(nums1, i, nums2, j))
        {
            result[k] = nums1[i++];
        }
        else
        {
            result[k] = nums2[j++];
        }
    }

    return result;
}
vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
{
    int n = nums1.size();
    int m = nums2.size();
    vector<int> result;
    for (int i = max(0, k - m); i <= min(k, n); ++i)
    {
        vector<int> max1 = getMax(nums1, i);
        vector<int> max2 = getMax(nums2, k - i);
        vector<int> merged = merge(max1, max2);
        if (isGreater(merged, 0, result, 0))
            result = merged;
    }

    return result;
}
int main()
{
    int n, m, k;
    cin >> n >> m;
    vector<int> nums1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums1[i];
    }
    vector<int> nums2(m);
    for (int i = 0; i < m; i++)
    {
        cin >> nums2[i];
    }
    cin >> k;
    vector<int> result = maxNumber(nums1, nums2, k);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}