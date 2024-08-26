#include<bits/stdc++.h>
using namespace std;
int maxSubarraySumCircular(vector<int>& a) {
    int n = a.size();
    int maxSum = INT_MIN, currentMax = 0;
    int totalSum = 0;
    int minSum = INT_MAX, currentMin = 0;
    for(int i = 0; i < n; i++) {
        currentMax = max(currentMax + a[i], a[i]);
        maxSum = max(maxSum, currentMax);
        currentMin = min(currentMin + a[i], a[i]);
        minSum = min(minSum, currentMin);
        totalSum += a[i];
    }
    if (maxSum < 0) return maxSum;
    return max(maxSum, totalSum - minSum);
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << maxSubarraySumCircular(arr) << endl;
    return 0;
}