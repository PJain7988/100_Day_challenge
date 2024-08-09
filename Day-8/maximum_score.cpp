#include<bits/stdc++.h>
using namespace std;
int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        long long ans =0,sumA=0,sumB=0;
    int i=0,j=0;
    while(i<n && j<m){
        if(nums1[i]<nums2[j]){
            sumA+=nums1[i];
            i++;
        }
        else if(nums1[i]>nums2[j]){
            sumB+=nums2[j];
            j++;
        }else if(nums1[i]==nums2[j]){
            if(sumA>sumB){
            ans+=sumA;
            }else{
            ans+=sumB;
        }
            ans+=nums1[i];
            i++;
            j++;
            sumA=0;
            sumB=0;
        }
    }
    while(i<n){
        sumA+=nums1[i];
        i++;
    }
    while(j<m){
        sumB+=nums2[j];
        j++;
    }
    ans+=max(sumA,sumB);
    return (int) (ans % 1000000007);
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    vector<int>b(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    int result = maxSum(a,b);
    cout<<result<<endl;
    return 0;
}