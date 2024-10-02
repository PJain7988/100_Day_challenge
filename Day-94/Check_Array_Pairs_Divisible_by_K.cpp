#include<bits/stdc++.h>
using namespace std;
bool canArrange(vector<int>& arr, int k) {
    vector<int> freq(k, 0);
    for (int num : arr) {
        int rem = num % k;
        if (rem < 0) {
            rem += k;
        }
        freq[rem]++;
    }        
    if (freq[0] % 2 != 0) {
        return false;
    } 
    for (int i = 1; i <= k / 2; i++) {
        if (freq[i] != freq[k - i]) {
            return false;
        }
    } 
    return true;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(canArrange(arr,k)){
        cout<<"true";
    }else{
        cout<<"false";
    }
    return 0;
}