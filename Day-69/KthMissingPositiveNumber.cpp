#include<bits/stdc++.h>
using namespace std;
int findKthPositive(vector<int>& arr, int k) {
    int s=0;
    int e=arr.size()-1;
    while(s<e){
    int mid= s+(e-s)/2;
    if(arr[mid]-mid-1<k){
        s=mid+1;
    }else{
        e=mid;
    }
    }
    if(arr[s]-s-1<k){
        return s+k+1;
    }
    return s+k;
}
int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout << findKthPositive(arr,k);
    return 0;
}